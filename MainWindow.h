#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//----------------------------------------------------------------------
#include <QMainWindow>
#include <QVBoxLayout>
#include <QGraphicsView>
#include "GameScene.h"
#include "MainMenu.h"
//----------------------------------------------------------------------

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void OnStartGame(QString scenarioPath);

private:
    GameScene* _scene;
    QGraphicsView* _view;

    MainMenu* _mainMenu;
};
//----------------------------------------------------------------------
#endif // MAINWINDOW_H
