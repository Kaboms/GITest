#ifndef PRINTER_H
#define PRINTER_H
//----------------------------------------------------------------------
#include <QGraphicsItem>
//----------------------------------------------------------------------

class Printer : public QGraphicsItem
{
public:
    Printer(QGraphicsItem* parent = nullptr);
    virtual ~Printer() override;

    QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);

    void Resize();

    void SetText(const QString& speaker,  const QString& text);

private:
    QString _speaker = "";
    QString _text = "";

    QRect _speakerRect;
    QRect _textRect;
};
//----------------------------------------------------------------------
#endif // PRINTER_H
