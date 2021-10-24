#ifndef SCENARIOMANAGER_H
#define SCENARIOMANAGER_H
//----------------------------------------------------------------------
#include <QString>
#include "ScenarioCommands/AbstractScenarioCommand.h"
#include <queue>
#include "GameScene.h"
//----------------------------------------------------------------------
class GameScene;
class AbstractScenarioCommand;
//----------------------------------------------------------------------
typedef std::queue<std::shared_ptr<AbstractScenarioCommand>> CommandsQueue;
//----------------------------------------------------------------------
//! Класс для парсинга и выполнения сценариев

class ScenarioManager
{
public:
    ScenarioManager(GameScene* canvas);
    ~ScenarioManager();

    void Parse(const QString& scenarioPath);
    void ExecuteNext();

private:
    void CreateCommand(const QString& command);

private:
    CommandsQueue _commands;
    GameScene* _scene;
};
//----------------------------------------------------------------------
#endif // SCENARIOMANAGER_H
