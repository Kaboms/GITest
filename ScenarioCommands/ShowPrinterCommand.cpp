#include "ShowPrinterCommand.h"
//----------------------------------------------------------------------

ShowPrinterCommand::ShowPrinterCommand(GameScene* scene) : AbstractScenarioCommand(scene)
{
}
//----------------------------------------------------------------------

ShowPrinterCommand::~ShowPrinterCommand()
{
}
//----------------------------------------------------------------------

void ShowPrinterCommand::Execute()
{
    Scene->ShowPrinter();
}
//----------------------------------------------------------------------
