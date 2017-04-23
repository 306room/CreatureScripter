#include "templatetables.h"
#include "cache.h"

#include <QVector>
#include <QLineEdit>
#include <QAbstractItemModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QTreeView>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <functional>

class TemplateTreeItem
{
//private:
public:
    enum itemType{ROOT,TABLE,FIELD};
    itemType type;
    const char* _cData;
    TemplateTreeItem *_parentItem;
    QSqlField _itemData;
    QVariant _editableValue;
    QSqlField _originalData;
    QVector<TemplateTreeItem*> _childItems;
    TemplateTreeItem() : type(ROOT),_parentItem(nullptr){}
    TemplateTreeItem(const char* n,TemplateTreeItem* p) : type(TABLE), _cData(n),_parentItem(p)
    {
        p->appendChild(this);
    }
    TemplateTreeItem(const QSqlField& f, TemplateTreeItem* p) :
        type(FIELD),
        _parentItem(p),
        _itemData(f),
        _editableValue(f.value()),
        _originalData(f)
    {
        p->appendChild(this);
    }
    ~TemplateTreeItem(){
        qDeleteAll(_childItems);
        _childItems.clear();
    }
    void appendChild(TemplateTreeItem *item)
    {
        _childItems.append(item);
    }
    TemplateTreeItem *child(int row){
        return _childItems.at(row);
    }

    int childCount() const{ return _childItems.count(); }
    int columnCount() const {
        switch(type){
        case ROOT: return 2;
        case TABLE: return 2;
        case FIELD: return 2;
        }
    }
    QVariant data(int column) const{
        switch(type){
        case ROOT: return column ? "Value" : "Field";
        case TABLE: return column ? "" : _cData;
        case FIELD: return column ? _itemData.value() : _itemData.name();
        }
    }
    int row() const {
        if (_parentItem)
            return _parentItem->_childItems.indexOf(const_cast<TemplateTreeItem*>(this));
        return 0;
    }
    TemplateTreeItem *parentItem() {return _parentItem; }
    bool SetData(QVariant data){
        Q_ASSERT(type==FIELD);
        _editableValue.setValue(data);
        return true;
    }

    bool Match(const QString& match)
    {
        Q_ASSERT(type==FIELD);
        if(match.isEmpty()) return true;

        return _originalData.name().contains(match, Qt::CaseInsensitive)
                || _editableValue.toString().contains(match,Qt::CaseInsensitive);
    }
};

class TemplateTableModel : public QAbstractItemModel
{
private:
public:
    TemplateTreeItem* rootItm;
    TemplateTableModel(const QVector<std::pair<const char*,QSqlRecord>>& records, QWidget* parent) :
        QAbstractItemModel(parent),
        rootItm(new TemplateTreeItem)
    {
        for(auto r = records.begin(); r != records.end(); r++){
            TemplateTreeItem* itm = new TemplateTreeItem(r->first, rootItm);
            for(int col = 0; col < r->second.count(); col++){
                new TemplateTreeItem(r->second.field(col), itm);
            }
        }
    }
    ~TemplateTableModel() { rootItm; }

    QModelIndex index(int row, int column, const QModelIndex &parent) const override
    {
        if (!hasIndex(row, column, parent))
            return QModelIndex();

        TemplateTreeItem *parentItem;

        if (!parent.isValid())
            parentItem = rootItm;
        else
            parentItem = static_cast<TemplateTreeItem*>(parent.internalPointer());

        TemplateTreeItem *childItem = parentItem->child(row);
        if (childItem)
            return createIndex(row, column, childItem);
        else
            return QModelIndex();
    }
    QModelIndex parent(const QModelIndex &index) const
    {
        if (!index.isValid())
            return QModelIndex();

        TemplateTreeItem *childItem = static_cast<TemplateTreeItem*>(index.internalPointer());
        TemplateTreeItem *parentItem = childItem->parentItem();

        if (parentItem == rootItm)
            return QModelIndex();

        return createIndex(parentItem->row(), 0, parentItem);
    }
    int rowCount(const QModelIndex &parent) const
    {
        TemplateTreeItem *parentItem;
        if (parent.column() > 0)
            return 0;

        if (!parent.isValid())
            parentItem = rootItm;
        else
            parentItem = static_cast<TemplateTreeItem*>(parent.internalPointer());

        return parentItem->childCount();
    }
    int columnCount(const QModelIndex& parent) const override
    {
        if (parent.isValid())
            return static_cast<TemplateTreeItem*>(parent.internalPointer())->columnCount();
        else
            return rootItm->columnCount();
    }
    QVariant data(const QModelIndex &index, int role) const override
    {
        if (!index.isValid())
            return QVariant();

        if (role != Qt::DisplayRole)
            return QVariant();

        TemplateTreeItem *item = static_cast<TemplateTreeItem*>(index.internalPointer());

        return item->data(index.column());
    }
    Qt::ItemFlags flags(const QModelIndex &index) const
    {
        if(index.column() == 1)
            return Qt::ItemIsEditable | Qt::ItemIsSelectable;
        else
            return Qt::NoItemFlags;
        /*
        //todo: currently readonly
        if (!index.isValid())
            return 0;

        return QAbstractItemModel::flags(index);
        */
    }
    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
            return rootItm->data(section);

        return QVariant();
    }
    bool setData(const QModelIndex &index, const QVariant &value, int /*role*/) override
    {
        return static_cast<TemplateTreeItem*>(index.internalPointer())->SetData(value);
    }
};

TemplateTables::TemplateTables(const QVector<std::pair<const char*,QSqlRecord>>& records, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* l = new QVBoxLayout(this);
    setLayout(l);

    QFormLayout* fl = new QFormLayout();
    l->addLayout(fl);
    QLineEdit* searchEdit = new QLineEdit(this);
    connect(searchEdit, &QLineEdit::textChanged, this, &TemplateTables::onTextChange);
    fl->addRow("Field/value", searchEdit);


    view = new QTreeView(this);
    model = new TemplateTableModel(records, this);
    view->setModel(model);
    view->expandAll();
    view->resizeColumnToContents(0);
    view->resizeColumnToContents(1);
    l->addWidget(view);
}

void TemplateTables::onTextChange(const QString &s)
{
    for(int r = 0; r < model->rootItm->childCount(); r++) {
        QModelIndex root = model->index(r,0,QModelIndex());
        TemplateTreeItem* rootItm = static_cast<TemplateTreeItem*>(root.internalPointer());
        for(int r0 = 0; r0 < rootItm->childCount(); r0++){
            QModelIndex r0Idx = root.child(r0,0);
            TemplateTreeItem* r0Itm = static_cast<TemplateTreeItem*>(r0Idx.internalPointer());
            view->setRowHidden(r0, root, !r0Itm->Match(s));
        }
    }
}