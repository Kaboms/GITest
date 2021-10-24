#ifndef ABSTRACTSCENARIOCOMMAND_H
#define ABSTRACTSCENARIOCOMMAND_H
//----------------------------------------------------------------------
#include <QString>
#include <memory>
#include "GameScene.h"
//----------------------------------------------------------------------
class GameScene;
class AbstractScenarioCommand;
//----------------------------------------------------------------------
// Некоторые команды могут иметь необязательный параметр Point
// Для того, чтобы понимать, что данный параметр не инициализирован испольуется данный макрос
#define UNDEFINED_POINT QPoint(-1, -1)
//----------------------------------------------------------------------
//! Базовый класс для всех команд.

class AbstractScenarioCommand
{
public:
    AbstractScenarioCommand(GameScene* scene);
    virtual ~AbstractScenarioCommand();
    virtual void Init(const QString& params);
    virtual void Execute() = 0;

    bool GetInput() const;

protected:
    // Нужно ли ждать дейсвие от пользователя, чтобы продолжить
    bool Input = true;
    GameScene* Scene;
};
//----------------------------------------------------------------------
#endif // ABSTRACTSCENARIOCOMMAND_H
