#include "HideCharacterCommand.h"
#include <QRegularExpression>
//----------------------------------------------------------------------

HideCharacterCommand::HideCharacterCommand(GameScene* scene) : AbstractScenarioCommand(scene)
{
}
//----------------------------------------------------------------------

HideCharacterCommand::~HideCharacterCommand()
{
}
//----------------------------------------------------------------------

void HideCharacterCommand::Init(const QString& params)
{
    AbstractScenarioCommand::Init(params);

    QRegularExpression rx;
    rx.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    rx.setPattern("(?<=\\s|^@hideChar\\s)\\s*\\w+(?=\\s)");
    QRegularExpressionMatch idMatch = rx.match(params);
    if (idMatch.hasMatch())
    {
        _characterId = idMatch.captured();
    }

}
//----------------------------------------------------------------------

void HideCharacterCommand::Execute()
{
    Scene->HideCharacter(_characterId);
}
//----------------------------------------------------------------------
