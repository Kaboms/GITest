#include "MainMenu.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QAction>
#include <QStyle>
#include <QFileDialog>
//----------------------------------------------------------------------

MainMenu::MainMenu(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    layout->addStretch();

    QHBoxLayout* lineEditLayout = new QHBoxLayout(this);

    _scenarioPathEdit = new QLineEdit(this);
    _scenarioPathEdit->setReadOnly(true);

    QAction* openFileAction = _scenarioPathEdit->addAction(style()->standardIcon(QStyle::SP_DialogOpenButton), QLineEdit::TrailingPosition);
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(OnOpenFile()));

    lineEditLayout->addStretch();
    lineEditLayout->addWidget(new QLabel("Файл сценария", this));
    lineEditLayout->addWidget(_scenarioPathEdit);
    lineEditLayout->addStretch();

    layout->addLayout(lineEditLayout);

    _startButton = new QPushButton("Старт", this);
    _startButton->setEnabled(false);
    _startButton->setFixedWidth(200);
    connect(_startButton, SIGNAL(pressed()), this, SLOT(OnStartPressed()));
    layout->addWidget(_startButton, 0, Qt::AlignCenter);

    layout->addStretch();

    connect(this, SIGNAL(StartGame(QString)), parent, SLOT(OnStartGame(QString)));

    if (QFile("scenario.txt").exists())
    {
        _scenarioPathEdit->setText("scenario.txt");
        _startButton->setEnabled(true);
    }
}
//----------------------------------------------------------------------

MainMenu::~MainMenu()
{
}
//----------------------------------------------------------------------

void MainMenu::OnOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName();
    if (fileName != "")
    {
        _startButton->setEnabled(true);
        _scenarioPathEdit->setText(fileName);
    }
    else
    {
        _startButton->setEnabled(false);
    }
}
//----------------------------------------------------------------------

void MainMenu::OnStartPressed()
{
    emit StartGame(_scenarioPathEdit->text());
}
//----------------------------------------------------------------------
