#ifndef SHOWITEMCOMMAND_H
#define SHOWITEMCOMMAND_H
//----------------------------------------------------------------------
#include "AbstractScenarioCommand.h"
//----------------------------------------------------------------------
//! Базовая комманда для показа элементов на сцене

class ShowItemCommand : public AbstractScenarioCommand
{

public:
    ShowItemCommand(GameScene* scene);
    virtual ~ShowItemCommand() override;
    virtual void Init(const QString& params) override;
    virtual void Execute() = 0;

protected:
    QString _id;
    QString _resursePath = "";
    int _order = -1;
};
//----------------------------------------------------------------------
#endif // SHOWITEMCOMMAND_H
