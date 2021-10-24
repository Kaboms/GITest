#ifndef MAINMENU_H
#define MAINMENU_H
//----------------------------------------------------------------------
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
//----------------------------------------------------------------------

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    MainMenu(QWidget* parent);
    virtual ~MainMenu() override;

public slots:
    void OnOpenFile();
    void OnStartPressed();

signals:
    void StartGame(QString scenarioPath);

private:
    QLineEdit* _scenarioPathEdit;
    QPushButton* _startButton;
};
//----------------------------------------------------------------------
#endif // MAINMENU_H
