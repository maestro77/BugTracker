//
#include "../../playerbot.h"
#include "DruidActions.h"

using namespace ai;

bool CastCasterFormAction::Execute(Event event)
{
    ai->RemoveShapeshift();
    return true;
}

ActionList CastAbolishPoisonAction::getAlternatives()
{
    return NextAction::merge( NextAction::array({ new NextAction("cure poison") }), CastSpellAction::getPrerequisites());
}

ActionList CastAbolishPoisonOnPartyAction::getAlternatives()
{
    return NextAction::merge( NextAction::array({ new NextAction("cure poison on party") }), CastSpellAction::getPrerequisites());
}

Value<Unit*>* CastEntanglingRootsCcAction::GetTargetValue()
{
    return context->GetValue<Unit*>("cc target", "entangling roots");
}

bool CastEntanglingRootsCcAction::Execute(Event event)
{
    return ai->CastSpell("entangling roots", GetTarget()); 
}
