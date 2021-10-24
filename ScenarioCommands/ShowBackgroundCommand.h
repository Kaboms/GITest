#ifndef SHOWBACKGROUNDCOMMAND_H
#define SHOWBACKGROUNDCOMMAND_H
//----------------------------------------------------------------------
#include "ShowItemCommand.h"
//----------------------------------------------------------------------
//! Показать задний фон. Если фон уже открыт, заменяет текущий

class ShowBackgroundCommand : public ShowItemCommand
{
public:
    ShowBackgroundCommand(GameScene* scene);
    virtual ~ShowBackgroundCommand() override;
    virtual void Init(const QString& params) override;
    virtual void Execute() override;
};
//----------------------------------------------------------------------
#endif // SHOWBACKGROUNDCOMMAND_H
