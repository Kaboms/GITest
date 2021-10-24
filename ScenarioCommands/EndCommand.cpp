#include "EndCommand.h"
#include <QCoreApplication>
//----------------------------------------------------------------------

EndCommand::EndCommand(GameScene* scene) : AbstractScenarioCommand(scene)
{
}
//----------------------------------------------------------------------

EndCommand::~EndCommand()
{
}
//----------------------------------------------------------------------

void EndCommand::Execute()
{
    QCoreApplication::quit();
}
//----------------------------------------------------------------------
