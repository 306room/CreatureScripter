#include "eventwidgetclasses.h"
#include "eventaidef.h"

namespace EventAI{

type_EventType::type_EventType(int currType)
{
    EventAIStorage& s = EventAIStorage::Get();
    foreach(const EventAI_event& e, s.Events()){
        addItem(e.name, e.id);
    }
    bool ok;
    for(int i = 0; i <= count(); i++){
        if(i == count()){
            Q_ASSERT(0); //ugly hack to assert that we got a valid ID
        }
        int t = itemData(i).toInt(&ok);
        Q_ASSERT(ok);
        if(t == currType){
            setCurrentIndex(i);
            setToolTip(s.Events()[currType].description);
            break;
        }
    }
}

type_ActionType::type_ActionType(int currType)
{
    EventAIStorage& s = EventAIStorage::Get();
    foreach(const EventAI_Action& a, s.Actions()){
        addItem(a.name, a.id);
    }
    bool ok;
    for(int i = 0; i <= count(); i++){
        if(i == count()){
            Q_ASSERT(0); //ugly hack to assert that we got a valid ID
        }
        int t = itemData(i).toInt(&ok);
        Q_ASSERT(ok);
        if(t == currType){
            setCurrentIndex(i);
            setToolTip(s.Actions()[currType].description);
            break;
        }
    }
}

}
