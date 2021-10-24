#include "HidePrinterCommand.h"
//----------------------------------------------------------------------

HidePrinterCommand::HidePrinterCommand(GameScene* scene) : AbstractScenarioCommand(scene)
{
}
//----------------------------------------------------------------------

HidePrinterCommand::~HidePrinterCommand()
{
}
//----------------------------------------------------------------------

void HidePrinterCommand::Execute()
{
    Scene->HidePrinter();
}
//----------------------------------------------------------------------
