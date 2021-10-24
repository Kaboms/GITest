#ifndef SHOWTEXTCOMMAND_H
#define SHOWTEXTCOMMAND_H
//----------------------------------------------------------------------
#include "AbstractScenarioCommand.h"
//----------------------------------------------------------------------
//! Показать текст который произносит главный герой

class ShowTextCommand : public AbstractScenarioCommand
{
public:
    ShowTextCommand(GameScene* scene);
    virtual ~ShowTextCommand() override;
    virtual void Init(const QString& params) override;
    virtual void Execute();

private:
    QString _text;
    QString _speaker = "Ты";
};
//----------------------------------------------------------------------
#endif // SHOWTEXTCOMMAND_H
