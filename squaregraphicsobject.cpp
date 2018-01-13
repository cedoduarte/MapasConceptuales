#include "squaregraphicsobject.h"
#include <QPainter>

SquareGraphicsObject::SquareGraphicsObject(QGraphicsObject *parent)
    : QGraphicsObject(parent)
{
    mSelectedMark = false;
}

void SquareGraphicsObject::setPosition(const QPoint &position)
{
    mPosition.setX(position.x() - mSize.width() / 2);
    mPosition.setY(position.y() - mSize.height() / 2);
}

void SquareGraphicsObject::join(SquareGraphicsObject *other)
{
    if (this == other) {
        // no hacemos nada porque no se puede conectar consigo mismo
    } else {
        // conecta con una línea los cuadros
        if (mOthers.contains(other)) {
            // no hacemos nada porque ya existe
        } else {
            mOthers.append(other);
        }
    }
}

QRectF SquareGraphicsObject::boundingRect() const
{
    return QRectF(mPosition.x(), mPosition.y(),
                  mSize.width(), mSize.height());
}

void SquareGraphicsObject::paint(QPainter *painter,
                                 const QStyleOptionGraphicsItem *option,
                                 QWidget *widget)
{
    if (mSelectedMark) {
        // dibuja cuadro relleno de color amarillo
        painter->fillRect(boundingRect(), Qt::yellow);
        painter->drawRect(boundingRect());
    } else {
        // dibuja cuadro normal
        painter->drawRect(boundingRect());
    }

    // dibuja el texto del cuadro
    painter->drawText(mPosition.x(), mPosition.y(), mSize.width(),
                      mSize.height(), Qt::TextWordWrap, mText);

    // se pintan las líneas de todos los elementos unidos
    const int nOtros = mOthers.size();
    for (int ax = 0; ax < nOtros; ++ax) {
        painter->drawLine(mPosition.x() + mSize.width() / 2,
                          mPosition.y() + mSize.height(),
                          mOthers[ax]->mPosition.x()
                          + mOthers[ax]->mSize.width() / 2,
                          mOthers[ax]->mPosition.y());
    }
    (void) option;
    (void) widget;
}
