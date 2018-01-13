#include "documentgraphicsscene.h"
#include "squaregraphicsobject.h"
#include <QGraphicsSceneMouseEvent>

DocumentGraphicsScene::DocumentGraphicsScene(QObject *parent)
    : QGraphicsScene(0.0, 0.0, 600.0, 600.0, parent)
{
    mItemUnderMouse = nullptr;
    mSelectedItemByDoubleClick = nullptr;
}

void DocumentGraphicsScene::addSquare(const QString &text,
                                      const QPoint &position,
                                      const QSize &size)
{
    // crea cuadro de texto nuevo
    SquareGraphicsObject *square = new SquareGraphicsObject;
    square->setText(text);
    square->setPosition(position);
    square->setSize(size);
    addItem(square);
    update();
}

void DocumentGraphicsScene::mouseDoubleClickEvent
    (QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mSelectedItemByDoubleClick) {
        // vamos por el segundo elemento seleccionado
        SquareGraphicsObject *cuadro1 = nullptr;
        SquareGraphicsObject *cuadro2 = nullptr;
        QGraphicsItem *firstSelectedItem = nullptr;
        QGraphicsItem *secondSelectedItem = nullptr;

        firstSelectedItem = mSelectedItemByDoubleClick;
        secondSelectedItem = getItemUnderMouseUpdatingCurrentItem();

        if (secondSelectedItem) {
            cuadro1 = static_cast<SquareGraphicsObject *>(firstSelectedItem);
            cuadro2 = static_cast<SquareGraphicsObject *>(secondSelectedItem);
            cuadro1->join(cuadro2);

            // ya se hizo la unión, se actualiza a un
            // nuevo elemento por seleccionar
            mSelectedItemByDoubleClick = nullptr;
        }
    } else {
        // vamos por el primero
        mSelectedItemByDoubleClick = getItemUnderMouseUpdatingCurrentItem();
    }
    mouseEvent->accept();
}

void DocumentGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // mueve de lugar el objeto actual
    if (mItemUnderMouse) {
        SquareGraphicsObject *cuadroItem = nullptr;
        cuadroItem = static_cast<SquareGraphicsObject *>(mItemUnderMouse);
        cuadroItem->setPosition(mouseEvent->scenePos().toPoint());
        update();
    }
    mouseEvent->accept();
}

void DocumentGraphicsScene::mousePressEvent
    (QGraphicsSceneMouseEvent *mouseEvent)
{
    // actualiza el elemento actual
    getItemUnderMouseUpdatingCurrentItem();
    mouseEvent->accept();
}

void DocumentGraphicsScene::mouseReleaseEvent
    (QGraphicsSceneMouseEvent *mouseEvent)
{
    // anula el objeto actual
    mItemUnderMouse = nullptr;
    mouseEvent->accept();
}

QGraphicsItem *DocumentGraphicsScene::getItemUnderMouseUpdatingCurrentItem()
{
    // obtiene el objeto actual (seleccionado)
    QList<QGraphicsItem *> objects = items();
    QGraphicsItem *itemUnderMouse = nullptr;
    SquareGraphicsObject *axItem = nullptr;
    const int nObjects = objects.size();
    for (int ax = 0; ax < nObjects; ++ax) {
        // desmarca los objetos
        axItem = static_cast<SquareGraphicsObject *>(objects[ax]);
        axItem->setSelectedMark(false);
        if (objects[ax]->isUnderMouse()) {
            itemUnderMouse = objects[ax];
        }
    }
    // actualiza el elemento actual
    mItemUnderMouse = itemUnderMouse;
    if (mItemUnderMouse) {
        SquareGraphicsObject *square = nullptr;
        square = static_cast<SquareGraphicsObject *>(mItemUnderMouse);
        square->setSelectedMark(true);
    }
    update();
    return itemUnderMouse;
}

