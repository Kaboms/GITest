#include "HideBackgroundCommand.h"
#include <QRegularExpression>
//----------------------------------------------------------------------

HideBackgroundCommand::HideBackgroundCommand(GameScene* scene) : AbstractScenarioCommand(scene)
{
}
//----------------------------------------------------------------------

HideBackgroundCommand::~HideBackgroundCommand()
{
}
//----------------------------------------------------------------------

void HideBackgroundCommand::Init(const QString& params)
{
    AbstractScenarioCommand::Init(params);

    QRegularExpression rx;
    rx.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    rx.setPattern("(?<=\\s|^@hideBack\\s)\\s*\\w+(?=\\s)");
    QRegularExpressionMatch idMatch = rx.match(params);
    if (idMatch.hasMatch())
    {
        _backId = idMatch.captured();
    }

}
//----------------------------------------------------------------------

void HideBackgroundCommand::Execute()
{
    Scene->HideBackground(_backId);
}
//----------------------------------------------------------------------
