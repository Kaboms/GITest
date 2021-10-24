#ifndef SHOWPRINTERCOMMAND_H
#define SHOWPRINTERCOMMAND_H
//----------------------------------------------------------------------
#include "AbstractScenarioCommand.h"
//----------------------------------------------------------------------
//! Показать принтер

class ShowPrinterCommand : public AbstractScenarioCommand
{
public:
    ShowPrinterCommand(GameScene* scene);
    virtual ~ShowPrinterCommand() override;
    virtual void Execute() override;
};
//----------------------------------------------------------------------
#endif // SHOWPRINTERCOMMAND_H
