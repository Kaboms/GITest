#include "ShowCharacterCommand.h"
#include <QRegularExpression>
#include <qdebug.h>
//----------------------------------------------------------------------

ShowCharacterCommand::ShowCharacterCommand(GameScene* scene) : ShowItemCommand(scene)
{
}
//----------------------------------------------------------------------

ShowCharacterCommand::~ShowCharacterCommand()
{
}
//----------------------------------------------------------------------

void ShowCharacterCommand::Init(const QString& params)
{
    ShowItemCommand::Init(params);

    QRegularExpression rx;
    rx.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    rx.setPattern("(?<=\\s|^@char\\s)\\s*\\w+(?=\\s)");
    QRegularExpressionMatch idMatch = rx.match(params);
    if (idMatch.hasMatch())
    {
        _id = idMatch.captured();
    }

    rx.setPattern("(?<=\\sposition:)(\\s*)(\\d+)\\s*,\\s*(\\d+)");
    QRegularExpressionMatch positionMatch = rx.match(params);
    if (positionMatch.hasMatch())
    {
        // Совпадение возвращает три группы:
        // в первой содержатся пробелы и ковычка, во второй X координата, в третьей Y координата
        int x = positionMatch.captured(2).toInt();
        int y = positionMatch.captured(3).toInt();
        _position = QPoint(x, y);
    }
}
//----------------------------------------------------------------------

void ShowCharacterCommand::Execute()
{
    Scene->ShowCharacter(_id, _resursePath, _position, _order);
}
//----------------------------------------------------------------------
