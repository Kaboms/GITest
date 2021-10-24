#include "GameScene.h"
#include <QDir>
#include <QGraphicsView>
#include <ScenarioCommands/AbstractScenarioCommand.h>
#include "PathHelper.h"
#include <QGraphicsProxyWidget>
//----------------------------------------------------------------------
#define LAYOUTS_COUNT 256
//----------------------------------------------------------------------

GameScene::GameScene(QObject* parent) : QGraphicsScene(parent)
{
    _printer = new Printer();
    // Чтобы принтер был всегда поверх всех элементов
    _printer->setZValue(LAYOUTS_COUNT + 1);
    _printer->hide();
    addItem(_printer);
}
//----------------------------------------------------------------------

GameScene::~GameScene()
{
}
//----------------------------------------------------------------------

void GameScene::Init(const QSize& size, const QString& scenario_path)
{
    setSceneRect(0, 0, size.width(), size.height());

    int xPos = sceneRect().width() / 2 - _printer->boundingRect().width() / 2;
    int yPos = sceneRect().height() / 2;
    _printer->setPos(xPos, yPos);

    _printer->Resize();

    _scenarioManager = std::make_unique<ScenarioManager>(this);
    _scenarioManager->Parse(scenario_path);
}
//----------------------------------------------------------------------

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mousePressEvent(event);

    _scenarioManager->ExecuteNext();
}
//----------------------------------------------------------------------

QGraphicsPixmapItem* GameScene::ShowItem(ItemsMap& items, const QString& id, const QString& resurse_path, const QPoint& position, const int& order)
{
    QGraphicsPixmapItem* item = nullptr;

    auto item_find = items.find(id);
    if (item_find != items.end())
    {
        item = item_find->second;
        item->show();
    }
    else
    {
        item = new QGraphicsPixmapItem();
        items[id] = item;
        addItem(item);
    }

    if (position != UNDEFINED_POINT)
    {
        qreal x = sceneRect().width() * (position.x() * 0.01);
        qreal y = sceneRect().height() * (position.y() * 0.01);
        item->setPos(x, y);
    }

    if (order != -1)
    {
        // В Qt чем выше значение, тем ближе к камере. Нам же нужно сделать наоборот.
        item->setZValue(LAYOUTS_COUNT - order);
    }

    return item;
}
//----------------------------------------------------------------------

void GameScene::HideItem(ItemsMap& items, const QString& id)
{
    auto item_find = items.find(id);
    if (item_find != items.end())
    {
        QGraphicsPixmapItem* item = item_find->second;
        item->hide();
    }

    update();
}
//----------------------------------------------------------------------

void GameScene::ShowBackground(const QString& id, QString resurse_path, const int& order)
{
    if (_currentBackground != "")
    {
        _backgrounds[_currentBackground]->hide();
    }
    _currentBackground = id;

    QGraphicsPixmapItem* item = ShowItem(_backgrounds, id, resurse_path, UNDEFINED_POINT, order);

    if (resurse_path != "")
    {
        QPixmap pixmap;
        if (pixmap.load(PathHelper::GetPath(resurse_path)))
        {
            item->setPixmap(pixmap.scaled(sceneRect().width(), sceneRect().height()));
        }
    }

    update();
}
//----------------------------------------------------------------------

void GameScene::HideBackground(const QString& id)
{
    HideItem(_backgrounds, id);
}
//----------------------------------------------------------------------

void GameScene::ShowCharacter(const QString& id, const QString& resurse_path, const QPoint& position, const int& order)
{
    QGraphicsPixmapItem* item = ShowItem(_characters, id, resurse_path, position, order);

    if (resurse_path != "")
    {
        QPixmap pixmap;
        if (pixmap.load(PathHelper::GetPath(resurse_path)))
        {
            item->setPixmap(pixmap.scaledToHeight(sceneRect().height()));
        }
    }

    update();
}
//----------------------------------------------------------------------

void GameScene::HideCharacter(const QString& id)
{
    HideItem(_characters, id);
}
//----------------------------------------------------------------------

void GameScene::ShowPrinter()
{
    _printer->show();
}
//----------------------------------------------------------------------

void GameScene::HidePrinter()
{
    _printer->hide();
}
//----------------------------------------------------------------------

void GameScene::ShowText(const QString& speaker, const QString& text)
{
    _printer->SetText(speaker, text);
}
//----------------------------------------------------------------------
