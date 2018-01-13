#include "squaregraphicsscene.h"
#include "squaregraphicsobject.h"

SquareGraphicsScene::SquareGraphicsScene(QObject *parent)
    : QGraphicsScene(0.0, 0.0, 620.0, 620.0, parent)
{
    // crea cuadro de texto nuevo
    mSquare = new SquareGraphicsObject;
    mSquare->setPosition(QPoint(10, 10));
    mSquare->setSize(QSize(200, 200));
    addItem(mSquare);
}

void SquareGraphicsScene::updateWidth(int width)
{
    const int height = mSquare->getSize().height();
    mSquare->setSize(QSize(width, height));
    update();
}

void SquareGraphicsScene::updateHeight(int height)
{
    const int width = mSquare->getSize().width();
    mSquare->setSize(QSize(width, height));
    update();
}

void SquareGraphicsScene::updateText(const QString &text)
{
    mSquare->setText(text);
    update();
}
