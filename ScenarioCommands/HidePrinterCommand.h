#ifndef HIDEPRINTERCOMMAND_H
#define HIDEPRINTERCOMMAND_H
//----------------------------------------------------------------------
#include "AbstractScenarioCommand.h"
//----------------------------------------------------------------------
//! Скрыть принтер

class HidePrinterCommand: public AbstractScenarioCommand
{
public:
    HidePrinterCommand(GameScene* scene);
    virtual ~HidePrinterCommand() override;
    virtual void Execute() override;
};
//----------------------------------------------------------------------
#endif // HIDEPRINTERCOMMAND_H
