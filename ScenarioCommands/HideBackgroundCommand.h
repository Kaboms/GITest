#ifndef HIDEBACKGROUNDCOMMAND_H
#define HIDEBACKGROUNDCOMMAND_H
//----------------------------------------------------------------------
#include "AbstractScenarioCommand.h"
//----------------------------------------------------------------------
//! Скрыть задний фон

class HideBackgroundCommand: public AbstractScenarioCommand
{
public:
    HideBackgroundCommand(GameScene* scene);
    virtual ~HideBackgroundCommand() override;
    virtual void Init(const QString& params) override;
    virtual void Execute() override;

private:
    QString _backId;
};
//----------------------------------------------------------------------
#endif // HIDEBACKGROUNDCOMMAND_H
