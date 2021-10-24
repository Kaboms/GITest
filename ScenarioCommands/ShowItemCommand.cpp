#include "ShowItemCommand.h"
#include <QRegularExpression>
//----------------------------------------------------------------------

ShowItemCommand::ShowItemCommand(GameScene* scene) : AbstractScenarioCommand(scene)
{
}
//----------------------------------------------------------------------

ShowItemCommand::~ShowItemCommand()
{
}
//----------------------------------------------------------------------

void ShowItemCommand::Init(const QString& params)
{
    AbstractScenarioCommand::Init(params);

    QRegularExpression rx;
    rx.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    rx.setPattern("(?<=\\sapperanse:)(\\s*\")([^\"]*)");
    QRegularExpressionMatch resurseMatch = rx.match(params);
    if (resurseMatch.hasMatch())
    {
        // Совпадение возвращает две группы: в первой содержатся пробелы и ковычка, а во второй сам путь до файла.
        _resursePath = resurseMatch.captured(2);
    }

    rx.setPattern("(?<=\\sorder:)(\\s*)\\d+");
    QRegularExpressionMatch orderMatch = rx.match(params);
    if (orderMatch.hasMatch())
    {
        _order = orderMatch.captured().toInt();
    }
}
//----------------------------------------------------------------------
