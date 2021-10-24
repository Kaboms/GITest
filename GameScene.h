#ifndef GAMESCENE_H
#define GAMESCENE_H
//----------------------------------------------------------------------
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <map>
#include "Printer.h"
#include "ScenarioManager.h"
//----------------------------------------------------------------------
typedef std::map<QString, QGraphicsPixmapItem*> ItemsMap;
//----------------------------------------------------------------------
class ScenarioManager;
//----------------------------------------------------------------------
//! Игровая сцена

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QObject* parent);
    virtual ~GameScene() override;

    void Init(const QSize& size, const QString& scenario_path);

    void ShowBackground(const QString& id, QString resurse_path, const int& order);
    void HideBackground(const QString& id);

    void ShowCharacter(const QString& id, const QString& resurse_path, const QPoint& position, const int& order);
    void HideCharacter(const QString& id);

    void ShowPrinter();
    void HidePrinter();

    void ShowText(const QString& speaker, const QString& text);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:
    QGraphicsPixmapItem* ShowItem(ItemsMap& items, const QString& id, const QString& resurse_path, const QPoint& position, const int& order);
    void HideItem(ItemsMap& items, const QString& id);

private:
    ItemsMap _characters;
    ItemsMap _backgrounds;
    QString _currentBackground;

    Printer* _printer;

    std::unique_ptr<ScenarioManager> _scenarioManager;
};
//----------------------------------------------------------------------
#endif // GAMESCENE_H
