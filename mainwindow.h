#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class DocumentGraphicsScene;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum Option
    {
        NEW_DOCUMENT,
        ADD_SQUARE,
        QUIT_APPLICATION
    };

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Q_INVOKABLE void executeOption(int option);
    Q_INVOKABLE QSize quickWidgetSize() const;
private:
    Ui::MainWindow *ui;
    DocumentGraphicsScene *mScene;
};

#endif // MAINWINDOW_H
