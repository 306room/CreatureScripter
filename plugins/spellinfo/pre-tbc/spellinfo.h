#ifndef SPELLINFO_H
#define SPELLINFO_H

#include <QObject>
#include <QtPlugin>

#include "../interface.h"
namespace Spell{
struct entry;
}
extern quint8 m_locale;
class LoadingScreen;
class SpellInfo : public QObject, SpellInfoInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID SpellInfoInterface_iid FILE "pre-tbc.json")
    Q_INTERFACES(SpellInfoInterface)

    public:

        bool init(LoadingScreen* ls) const;

        void setEnums(EnumHash enums);

        MPQList getMPQFiles() const;
        quint32 getSpellsCount() const;
        QObject* getMetaSpell(quint32 id, bool realId = false) const;
        QVariantHash getValues(quint32 id) const;
        QObjectList getMetaSpells() const;
        EnumHash getEnums() const;
        quint8 getLocale() const;
        QStringList getNames() const;
        QImage GetSpellIcon(quint32 iconId);
        const Spell::entry *GetEntry(quint32 id, bool realid);
};

#endif // SPELLINFO_H
