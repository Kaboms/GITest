#ifndef HIDECHARACTERCOMMAND_H
#define HIDECHARACTERCOMMAND_H
//----------------------------------------------------------------------
#include "AbstractScenarioCommand.h"
//----------------------------------------------------------------------
//! Скрыть персонажа

class HideCharacterCommand : public AbstractScenarioCommand
{
public:
    HideCharacterCommand(GameScene* scene);
    virtual ~HideCharacterCommand() override;
    virtual void Init(const QString& params) override;
    virtual void Execute() override;

private:
    QString _characterId;
};
//----------------------------------------------------------------------
#endif // HIDECHARACTERCOMMAND_H
