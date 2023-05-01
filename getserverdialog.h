#ifndef GETSERVERDIALOG_H
#define GETSERVERDIALOG_H

#include <QDialog>
class v2Ui;


namespace Ui {
class getServerDialog;
}

class getServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit getServerDialog(QWidget *parent = nullptr);
    QString jsonString;
    ~getServerDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::getServerDialog *ui;
};

#endif // GETSERVERDIALOG_H
