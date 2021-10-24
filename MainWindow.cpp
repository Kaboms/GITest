#include "MainWindow.h"
#include <memory>
#include <QLabel>
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
//----------------------------------------------------------------------

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    setContentsMargins(0, 0, 0, 0);

    QScreen* screen = QGuiApplication::primaryScreen();

    int width = screen->geometry().width() / 2;
    int height = screen->geometry().height() / 2;

    setFixedSize(width, height);

    _mainMenu = new MainMenu(this);
    setCentralWidget(_mainMenu);
}
//----------------------------------------------------------------------

MainWindow::~MainWindow()
{
}
//----------------------------------------------------------------------

void MainWindow::OnStartGame(QString scenarioPath)
{
    _mainMenu->hide();

    _scene = new GameScene(this);
    _scene->Init(QSize(geometry().width(), geometry().height()), scenarioPath);

    _view = new QGraphicsView(_scene);
    setCentralWidget(_view);
    _view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->show();
}
//----------------------------------------------------------------------
