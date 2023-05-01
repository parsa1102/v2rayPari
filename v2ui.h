#ifndef V2UI_H
#define V2UI_H

#include <QWidget>
class QMenuBar;
class getServerDialog;
class Handler;

QT_BEGIN_NAMESPACE
namespace Ui { class v2Ui; }
QT_END_NAMESPACE

class v2Ui : public QWidget
{
    Q_OBJECT

public:
    v2Ui(QWidget *parent = nullptr);
    ~v2Ui();
    QMenuBar * menuBar;
    QString jsonString;
    Handler * handler;
    void setV2rayOutput(QString str);


private slots:
    void on_pushButton_clicked();


    void on_connectButton_clicked();

private:
    Ui::v2Ui *ui;
    getServerDialog * dialog;
};
#endif // V2UI_H
