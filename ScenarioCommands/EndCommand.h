#ifndef ENDCOMMAND_H
#define ENDCOMMAND_H
//----------------------------------------------------------------------
#include "AbstractScenarioCommand.h"
//----------------------------------------------------------------------
//! Завершение игры и выход в главное меню

class EndCommand : public AbstractScenarioCommand
{
public:
    EndCommand(GameScene* scene);
    virtual ~EndCommand() override;
    virtual void Execute() override;
};
//----------------------------------------------------------------------
#endif // ENDCOMMAND_H
