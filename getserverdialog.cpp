#include "getserverdialog.h"
#include "ui_getserverdialog.h"
#include <v2ui.h>

getServerDialog::getServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getServerDialog)
{
    ui->setupUi(this);
}

getServerDialog::~getServerDialog()
{
    delete ui;
}

void getServerDialog::on_pushButton_clicked()
{
    jsonString = ui->textEdit->toPlainText();
    this->close();
}
