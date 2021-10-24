#include "ScenarioManager.h"
#include <QFile>
#include <QRegularExpression>
#include "ScenarioCommands/ShowCharacterCommand.h"
#include "ScenarioCommands/HideCharacterCommand.h"
#include "ScenarioCommands/ShowBackgroundCommand.h"
#include "ScenarioCommands/HideBackgroundCommand.h"
#include "ScenarioCommands/ShowPrinterCommand.h"
#include "ScenarioCommands/HidePrinterCommand.h"
#include "ScenarioCommands/ShowTextCommand.h"
#include "ScenarioCommands/EndCommand.h"
#include <QDir>
#include "PathHelper.h"
//----------------------------------------------------------------------

ScenarioManager::ScenarioManager(GameScene* scene)
{
    _scene = scene;
}
//----------------------------------------------------------------------

ScenarioManager::~ScenarioManager()
{
}
//----------------------------------------------------------------------

void ScenarioManager::CreateCommand(const QString& command)
{
    std::shared_ptr<AbstractScenarioCommand> newCommand;

    if (QRegularExpression("^@char\\s").match(command).hasMatch())
        newCommand = std::make_shared<ShowCharacterCommand>(_scene);
    else if (QRegularExpression("^@hideChar\\s").match(command).hasMatch())
        newCommand = std::make_shared<HideCharacterCommand>(_scene);
    else if (QRegularExpression("^@back\\s").match(command).hasMatch())
        newCommand = std::make_shared<ShowBackgroundCommand>(_scene);
    else if (QRegularExpression("^@hideBack\\s").match(command).hasMatch())
        newCommand = std::make_shared<HideBackgroundCommand>(_scene);
    else if (QRegularExpression("^@showPrinter\\s").match(command).hasMatch())
        newCommand = std::make_shared<ShowPrinterCommand>(_scene);
    else if (QRegularExpression("^@hidePrinter\\s").match(command).hasMatch())
        newCommand = std::make_shared<HidePrinterCommand>(_scene);
    else if(QRegularExpression("«.*»").globalMatch(command).hasNext())
        newCommand = std::make_shared<ShowTextCommand>(_scene);
    else if(QRegularExpression("^@end").globalMatch(command).hasNext())
        newCommand = std::make_shared<EndCommand>(_scene);

    if (newCommand != nullptr)
    {
        newCommand->Init(command);
        _commands.push(newCommand);
    }
}
//----------------------------------------------------------------------

void ScenarioManager::Parse(const QString& scenarioPath)
{
    QFile scenarioFile(PathHelper::GetPath(scenarioPath));
    if (scenarioFile.open(QFile::ReadOnly))
    {
        QString command = "";
        QRegularExpression rx("(^\\s*)(@|\"|«|\\/\\/\\/|\\w+:\\s*«)");

        while (!scenarioFile.atEnd())
        {
            QString line = scenarioFile.readLine();

            if (line.size() == 0)
                continue;

            // Если в комманде уже есть данные и мы дошли до следующей, то парсим текущую
            if (command.size() && rx.match(line).hasMatch())
            {
                CreateCommand(command.simplified());
                command = "";
            }
            command.append(line);
        }

        if (command.size())
            CreateCommand(command);

        // Выполняем первую комманду
        if (_commands.size())
            ExecuteNext();
    }

    scenarioFile.close();
}
//----------------------------------------------------------------------

void ScenarioManager::ExecuteNext()
{
    if (_commands.size())
    {
        std::shared_ptr<AbstractScenarioCommand> command = _commands.front();
        command->Execute();

        _commands.pop();

        if (command->GetInput() == false)
            ExecuteNext();
    }
}
//----------------------------------------------------------------------
