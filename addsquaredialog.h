#ifndef ADDSQUAREDIALOG_H
#define ADDSQUAREDIALOG_H

#include <QDialog>

class SquareGraphicsScene;

namespace Ui
{
class AddSquareDialog;
}

class AddSquareDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddSquareDialog(QWidget *parent = nullptr);
    ~AddSquareDialog();
    QString squareText() const;
    QSize squareSize() const;
private slots:
    void on_widthSlider_valueChanged(int value);
    void on_heightSlider_valueChanged(int value);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_plainTextEdit_textChanged();
private:
    Ui::AddSquareDialog *ui;
    SquareGraphicsScene *mScene;
};

#endif // ADDSQUAREDIALOG_H
