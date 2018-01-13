#ifndef SQUAREGRAPHICSSCENE_H
#define SQUAREGRAPHICSSCENE_H

#include <QGraphicsScene>

class SquareGraphicsObject;

class SquareGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SquareGraphicsScene(QObject *parent = nullptr);
    void updateWidth(int width);
    void updateHeight(int height);
    void updateText(const QString &text);
private:
    SquareGraphicsObject *mSquare;
};

#endif // SQUAREGRAPHICSSCENE_H
