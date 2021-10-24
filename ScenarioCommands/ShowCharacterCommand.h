#ifndef SHOWCHARACTERCOMMAND_H
#define SHOWCHARACTERCOMMAND_H
//----------------------------------------------------------------------
#include "ShowItemCommand.h"
#include <QPoint>
//----------------------------------------------------------------------
//! Показать персонажа

class ShowCharacterCommand : public ShowItemCommand
{
public:
    ShowCharacterCommand(GameScene* manager);
    virtual ~ShowCharacterCommand() override;
    virtual void Init(const QString& params) override;
    virtual void Execute() override;

private:
    QPoint _position = UNDEFINED_POINT;
};
//----------------------------------------------------------------------
#endif // SHOWPERSONCOMMAND_H
