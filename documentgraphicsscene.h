#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>

class DocumentGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    DocumentGraphicsScene(QObject *parent = nullptr);
    void addSquare(const QString &text, const QPoint &position,
                   const QSize &size);
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
private:
    // elemento para mover de lugar o eliminar
    QGraphicsItem *mItemUnderMouse;

    // elemento seleccionado para unir con otro elemento
    QGraphicsItem *mSelectedItemByDoubleClick;

    // obtiene el elemento actual y lo actualiza
    QGraphicsItem *getItemUnderMouseUpdatingCurrentItem();
};

#endif // GRAPHICSSCENE_H
