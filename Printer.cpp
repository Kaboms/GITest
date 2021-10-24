#include "Printer.h"
#include <QPainter>
#include <QGraphicsScene>
//----------------------------------------------------------------------

Printer::Printer(QGraphicsItem* parent) : QGraphicsItem(parent)
{
}
//----------------------------------------------------------------------

Printer::~Printer()
{
}
//----------------------------------------------------------------------

QRectF Printer::boundingRect() const
{
    return QRectF(0, 0, scene()->sceneRect().width() * 0.3, scene()->sceneRect().height() * 0.3);
}
//----------------------------------------------------------------------

void Printer::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->fillRect(boundingRect(), Qt::white);
    painter->drawRect(boundingRect());

    QFont font = painter->font();
    font.setPixelSize(boundingRect().height() * 0.1);
    painter->setFont(font);

    painter->drawText(_speakerRect, 0, _speaker);

    font.setPixelSize(boundingRect().height() * 0.08);
    painter->setFont(font);

    painter->drawText(_textRect, Qt::TextWordWrap, _text);
}
//----------------------------------------------------------------------

void Printer::Resize()
{
    _speakerRect = QRect(10, 10, boundingRect().size().width() - 20, boundingRect().size().height() * 0.1);
    _textRect = QRect(_speakerRect.x(), _speakerRect.y() + 30, _speakerRect.width(), boundingRect().size().height() - boundingRect().height() * 0.1 - 30);

    update();
}
//----------------------------------------------------------------------

void Printer::SetText(const QString& speaker,  const QString& text)
{
    _speaker = speaker;
    _text = text;

    update();
}
//----------------------------------------------------------------------
