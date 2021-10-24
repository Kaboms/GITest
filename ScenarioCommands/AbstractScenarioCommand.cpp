#include "AbstractScenarioCommand.h"
#include <QRegularExpression>
#include <QDebug>
//----------------------------------------------------------------------

AbstractScenarioCommand::AbstractScenarioCommand(GameScene* scene)
{
    Scene = scene;
}
//----------------------------------------------------------------------

AbstractScenarioCommand::~AbstractScenarioCommand()
{
}
//----------------------------------------------------------------------

void AbstractScenarioCommand::Init(const QString& params)
{
    QRegularExpressionMatch inputMatch = QRegularExpression("(?<=\\sinput:)(\\s*)(true|false)", QRegularExpression::CaseInsensitiveOption).match(params);
    if (inputMatch.hasMatch())
    {
        QString value = inputMatch.captured(2).toLower();
        // Так как значение по умолчанию true, то проверяем только если переданный параметр равен false
        if (value == "false")
            Input = false;
    }
}
//----------------------------------------------------------------------

bool AbstractScenarioCommand::GetInput() const
{
    return Input;
}
//----------------------------------------------------------------------
