#include "addsquaredialog.h"
#include "ui_addsquaredialog.h"
#include "squaregraphicsscene.h"

AddSquareDialog::AddSquareDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddSquareDialog)
{
    ui->setupUi(this);
    mScene = new SquareGraphicsScene(this);
    ui->graphicsView->setScene(mScene);

    ui->widthSlider->setRange(0, 600);
    ui->heightSlider->setRange(0, 600);
    ui->widthSlider->setValue(200);
    ui->heightSlider->setValue(200);
}

AddSquareDialog::~AddSquareDialog()
{
    delete ui;
}

QString AddSquareDialog::squareText() const
{
    return ui->plainTextEdit->toPlainText();
}

QSize AddSquareDialog::squareSize() const
{
    return QSize(ui->widthSlider->value(), ui->heightSlider->value());
}

void AddSquareDialog::on_widthSlider_valueChanged(int value)
{
    mScene->updateWidth(value);
}

void AddSquareDialog::on_heightSlider_valueChanged(int value)
{
    mScene->updateHeight(value);
}

void AddSquareDialog::on_buttonBox_accepted()
{
    accept();
}

void AddSquareDialog::on_buttonBox_rejected()
{
    reject();
}

void AddSquareDialog::on_plainTextEdit_textChanged()
{
    mScene->updateText(ui->plainTextEdit->toPlainText());
}
