#include "ShowTextCommand.h"
#include <QRegularExpression>
//----------------------------------------------------------------------

ShowTextCommand::ShowTextCommand(GameScene* scene) : AbstractScenarioCommand(scene)
{
}
//----------------------------------------------------------------------

ShowTextCommand::~ShowTextCommand()
{
}
//----------------------------------------------------------------------

void ShowTextCommand::Init(const QString& params)
{
    AbstractScenarioCommand::Init(params);

    QRegularExpression rx;
    rx.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    rx.setPattern("(?<=^)\\w+(?=:)");
    QRegularExpressionMatch speakerMatch = rx.match(params);
    if (speakerMatch.hasMatch())
    {
        // Совпадение возвращает две группы: в первой содержатся пробелы и ковычка, а во второй сам путь до файла.
        _speaker = speakerMatch.captured();
    }

    rx.setPattern("(\\s*\\«)([^»]*)");
    QRegularExpressionMatch textMatch = rx.match(params);
    if (textMatch.hasMatch())
    {
        // Совпадение возвращает две группы: в первой содержатся пробелы и ковычка, а во второй сам путь до файла.
        _text = textMatch.captured(2);
    }
}
//----------------------------------------------------------------------

void ShowTextCommand::Execute()
{
    Scene->ShowText(_speaker, _text);
}
//----------------------------------------------------------------------

