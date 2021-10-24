#include "ShowBackgroundCommand.h"
#include <QRegularExpression>
//----------------------------------------------------------------------

ShowBackgroundCommand::ShowBackgroundCommand(GameScene* scene) : ShowItemCommand(scene)
{
}
//----------------------------------------------------------------------

ShowBackgroundCommand::~ShowBackgroundCommand()
{
}
//----------------------------------------------------------------------

void ShowBackgroundCommand::Init(const QString& params)
{
    ShowItemCommand::Init(params);

    QRegularExpression rx;
    rx.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    rx.setPattern("(?<=\\s|^@back\\s)\\s*\\w+(?=\\s)");
    QRegularExpressionMatch idMatch = rx.match(params);
    if (idMatch.hasMatch())
    {
        _id = idMatch.captured();
    }
}
//----------------------------------------------------------------------

void ShowBackgroundCommand::Execute()
{
    Scene->ShowBackground(_id, _resursePath, _order);
}
//----------------------------------------------------------------------
