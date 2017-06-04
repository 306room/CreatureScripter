#include "tables.h"
#include "cache.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlField>
#include <QSqlQuery>
#include <QSqlError>

namespace Tables {
const QString creature::t = "creature";
const QString creature::id = "id";
const QString creature::map = "Map";

const QString creature_template_addon::t = "creature_template_addon";
const QString creature_template_addon::entry = "entry";

const QString creature_model_info::t = "creature_model_info";
const QString creature_model_info::modelid = "modelid";

const QString creature_equip_template::t = "creature_equip_template";
const QString creature_equip_template::entry = "entry";

const QString creature_equip_template_raw::t = "creature_equip_template_raw";

const QString creature_addon::t = "creature_addon";

const QString creature_ai_scripts::t = "creature_ai_scripts";
const QString creature_ai_scripts::id = "id";
const QString creature_ai_scripts::creature_id = "creature_id";
const QString creature_ai_scripts::event_type = "event_type";
const QString creature_ai_scripts::event_inverse_phase_mask = "event_inverse_phase_mask";
const QString creature_ai_scripts::event_chance = "event_chance";
const QString creature_ai_scripts::event_flags = "event_flags";
const QString creature_ai_scripts::event_param1 = "event_param1";
const QString creature_ai_scripts::event_param2 = "event_param2";
const QString creature_ai_scripts::event_param3 = "event_param3";
const QString creature_ai_scripts::event_param4 = "event_param4";
const QString creature_ai_scripts::action1_type = "action1_type";
const QString creature_ai_scripts::action1_param1 = "action1_param1";
const QString creature_ai_scripts::action1_param2 = "action1_param2";
const QString creature_ai_scripts::action1_param3 = "action1_param3";
const QString creature_ai_scripts::action2_type = "action2_type";
const QString creature_ai_scripts::action2_param1 = "action2_param1";
const QString creature_ai_scripts::action2_param2 = "action2_param2";
const QString creature_ai_scripts::action2_param3 = "action2_param3";
const QString creature_ai_scripts::action3_type = "action3_type";
const QString creature_ai_scripts::action3_param1 = "action3_param1";
const QString creature_ai_scripts::action3_param2 = "action3_param2";
const QString creature_ai_scripts::action3_param3 = "action3_param3";
const QString creature_ai_scripts::comment = "comment";
const QString creature_ai_scripts::event_param_n = "event_param%1";
const QString creature_ai_scripts::action_n_type = "action%1_type";
const QString creature_ai_scripts::action_x_param_y = "action%1_param%2";


const QString item_template::t = "item_template";

const QString map_template::t = "map_template";
const QString map_template::entry = "Entry";
const QString map_template::mapname = "MapName";

const QString creature_template::t = "creature_template";
const QString creature_template::entry             = "entry";
const QString creature_template::name              = "name";
const QString creature_template::modelid_1         = "modelid_1";
const QString creature_template::modelid_2         = "modelid_2";
const QString creature_template::modelid_3         = "modelid_3";
const QString creature_template::modelid_4         = "modelid_4";
const QString creature_template::equipment_id      = "equipment_id;";
const QString creature_template::Unit_flags        = "Unit_flags";
const QString creature_template::Dynamicflags      = "Dynamicflags";
const QString creature_template::Family            = "Family";
const QString creature_template::KillCredit1       = "KillCredit1";
const QString creature_template::KillCredit2       = "KillCredit2";
const QString creature_template::subname           = "subname";
const QString creature_template::gossip_menu_id    = "gossip_menu_id";
const QString creature_template::minlevel          = "minlevel";
const QString creature_template::maxlevel          = "maxlevel";
const QString creature_template::minhealth         = "minhealth";
const QString creature_template::maxhealth         = "maxhealth";
const QString creature_template::minmana           = "minmana";
const QString creature_template::maxmana           = "maxmana";
const QString creature_template::armor             = "armor";
const QString creature_template::faction_A         = "faction_A";
const QString creature_template::faction_H         = "faction_H";
const QString creature_template::npcflag           = "npcflag";
const QString creature_template::speed_walk        = "speed_walk";
const QString creature_template::speed_run         = "speed_run";
const QString creature_template::scale             = "scale";
const QString creature_template::rank              = "rank";
const QString creature_template::mindmg            = "mindmg";
const QString creature_template::maxdmg            = "maxdmg";
const QString creature_template::dmgschool         = "dmgschool";
const QString creature_template::attackpower       = "attackpower";
const QString creature_template::dmg_multiplier    = "dmg_multiplier";
const QString creature_template::baseattacktime    = "baseattacktime";
const QString creature_template::rangeattacktime   = "rangeattacktime";
const QString creature_template::unit_class        = "unit_class";
const QString creature_template::unit_flags        = "unit_flags";
const QString creature_template::dynamicflags      = "dynamicflags";
const QString creature_template::family            = "family";
const QString creature_template::trainer_type      = "trainer_type";
const QString creature_template::trainer_spell     = "trainer_spell";
const QString creature_template::trainer_class     = "trainer_class";
const QString creature_template::trainer_race      = "trainer_race";
const QString creature_template::minrangedmg       = "minrangedmg";
const QString creature_template::maxrangedmg       = "maxrangedmg";
const QString creature_template::rangedattackpower = "rangedattackpower";
const QString creature_template::type              = "type";
const QString creature_template::type_flags        = "type_flags";
const QString creature_template::lootid            = "lootid";
const QString creature_template::pickpocketloot    = "pickpocketloot";
const QString creature_template::skinloot          = "skinloot";
const QString creature_template::resistance1       = "resistance1";
const QString creature_template::resistance2       = "resistance2";
const QString creature_template::resistance3       = "resistance3";
const QString creature_template::resistance4       = "resistance4";
const QString creature_template::resistance5       = "resistance5";
const QString creature_template::resistance6       = "resistance6";
const QString creature_template::spell1            = "spell1";
const QString creature_template::spell2            = "spell2";
const QString creature_template::spell3            = "spell3";
const QString creature_template::spell4            = "spell4";
const QString creature_template::PetSpellDataId    = "PetSpellDataId";
const QString creature_template::mingold           = "mingold";
const QString creature_template::maxgold           = "maxgold";
const QString creature_template::MovementType      = "MovementType";
const QString creature_template::InhabitType       = "InhabitType";
const QString creature_template::Civilian          = "Civilian";
const QString creature_template::RacialLeader      = "RacialLeader";
const QString creature_template::RegenHealth       = "RegenHealth";
const QString creature_template::trainer_id        = "trainer_id";
const QString creature_template::vendor_id         = "vendor_id";
const QString creature_template::MechanicImmuneMask= "MechanicImmuneMask";
const QString creature_template::SchoolImmuneMask  = "SchoolImmuneMask";
const QString creature_template::flags_extra       = "flags_extra";
const QString creature_template::AIName            = "AIName";
const QString creature_template::ScriptName        = "ScriptName";

QVector<MangosRecord> Table::Query(const QVariant &value, const QString tarKey, int expectSize)
{
    if(!value.isValid()) {
        throw std::runtime_error("Query got invalid value");
    }else if(value.isNull()){
        throw std::runtime_error("Query got null-value");
    }

    QSqlDatabase db = Cache::Get().GetDB();
    QSqlField f;
    f.setValue(value);
    f.setType(value.type());
    QString qs = QString("SELECT * FROM %1 WHERE %2 = %3").arg(
                db.driver()->escapeIdentifier(dbTable(), QSqlDriver::TableName),
                db.driver()->escapeIdentifier(tarKey, QSqlDriver::FieldName),
                db.driver()->formatValue(f));

    QSqlQuery q(qs, db);
    if(!q.exec()){
        throw std::runtime_error(QString("Error (%1) during query exec in Query")
                                 .arg(q.lastError().text()).toStdString().c_str());
    }
    if(expectSize == 1 && q.size() != 1){
        throw std::runtime_error(QString("Query returned %1 result(s), expected 1")
                                 .arg(q.size()).toStdString().c_str());
    }
    QVector<MangosRecord> ret;
    while(q.next()){
        ret.push_back(MangosRecord(q.record(), _t));
    }

    return ret;
}

MangosRecord Table::Query1(const QVariant &value, const QString tarKey, bool assert)
{
    QVector<MangosRecord> records = Query(value, tarKey, assert ? 1 : -1);
    return records.empty() ? MangosRecord() : records.takeFirst();
}

QString Table::dbTable() {
    return QString("%1.%2").arg(Cache::Get().settings.value("worldDB").toString(), table());
}

creature_template::creature_template(quint32 entry) :
    Table(t)
{
    record = Query1(entry, creature_template::entry);
    record.table = t;
    record.pk = creature_template::entry;

    creatures = new creature(entry);
    scripts = new creature_ai_scripts(entry);
    equipment = new creature_equip_template(record.value(equipment_id));
    template_addon = new creature_template_addon(entry);
    model_info[0] = new creature_model_info(record.value(modelid_1));
    model_info[1] = new creature_model_info(record.value(modelid_2));
    model_info[2] = new creature_model_info(record.value(modelid_3));
    model_info[3] = new creature_model_info(record.value(modelid_4));

    //makeRelation<creature_template_addon>(entry, creature_template_addon::entry),
    //makeRelation<creature_model_info>(modelid_1, creature_model_info::modelid),
    //makeRelation<creature_model_info>(modelid_2, creature_model_info::modelid),
    //makeRelation<creature_model_info>(modelid_3, creature_model_info::modelid),
    //makeRelation<creature_model_info>(modelid_4, creature_model_info::modelid),
}


creature::creature(quint32 entry)
    :Table(t)
{
    records = Query(entry, creature::id);
}

creature_equip_template::creature_equip_template(const QVariant &v) :
    Table(t),
    record(Query1(v, creature_equip_template::entry, false))
{
    //makeRelation<creature>("equipentry1", "entry", "Main-hand"),
    //makeRelation<creature>("equipentry2", "entry", "Off-hand"),
    //makeRelation<creature>("equipentry3", "entry", "Ranged")
}

MangosRecord &creature_ai_scripts::getNewEmpty()
{

    QSqlRecord r;
    r.insert(0, QSqlField("id", QVariant::Int));
    r.insert(1, QSqlField(this->creature_id, QVariant::Int));
    r.insert(2, QSqlField(this->event_type, QVariant::Int));
    r.insert(3, QSqlField(this->event_inverse_phase_mask, QVariant::Int));
    r.insert(4, QSqlField(this->event_chance, QVariant::Int));
    r.insert(5, QSqlField(this->event_flags, QVariant::Int));
    r.insert(6, QSqlField(this->event_param1, QVariant::Int));
    r.insert(7, QSqlField(this->event_param2, QVariant::Int));
    r.insert(8, QSqlField(this->event_param3, QVariant::Int));
    r.insert(9, QSqlField(this->event_param4, QVariant::Int));
    r.insert(10, QSqlField(this->action1_type, QVariant::Int));
    r.insert(11, QSqlField(this->action1_param1, QVariant::Int));
    r.insert(12, QSqlField(this->action1_param2, QVariant::Int));
    r.insert(13, QSqlField(this->action1_param3, QVariant::Int));
    r.insert(14, QSqlField(this->action2_type, QVariant::Int));
    r.insert(15, QSqlField(this->action2_param1, QVariant::Int));
    r.insert(16, QSqlField(this->action2_param2, QVariant::Int));
    r.insert(17, QSqlField(this->action2_param3, QVariant::Int));
    r.insert(18, QSqlField(this->action3_type, QVariant::Int));
    r.insert(19, QSqlField(this->action3_param1, QVariant::Int));
    r.insert(20, QSqlField(this->action3_param2, QVariant::Int));
    r.insert(21, QSqlField(this->action3_param3, QVariant::Int));
    r.insert(22, QSqlField(this->comment, QVariant::String));
    records.push_back(MangosRecord(r, t));
    return records[records.size()-1];
}

void creature_ai_scripts::populateLatest(quint32 id, quint32 entry)
{
    MangosRecord& rec = records[records.size()-1];
    rec.setValue(this->id, id);
    rec.setValue(this->creature_id, entry);
    for(int i = 2; i < num_cols-1; i++)
    {
        rec.setValue(i, 0);
    }
    rec.setValue(num_cols-1, "todo");

}

creature_ai_scripts::creature_ai_scripts(quint32 entry) :
    Table(t)
{
    records = Query(entry, creature_ai_scripts::creature_id);
    for(auto it = records.begin(); it != records.end(); it++){
        (*it).table = t;
        (*it).pk = creature_ai_scripts::id;
    }
}

creature_template_addon::creature_template_addon(const QVariant &v):
    Table(t),
    record(Query1(v, creature_template_addon::entry, false))
{
}

creature_model_info::creature_model_info(QVariant v) :
    Table(t),
    record(Query1(v, creature_model_info::modelid, false))
{

}



}
