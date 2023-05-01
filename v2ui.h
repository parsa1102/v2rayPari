#ifndef V2UI_H
#define V2UI_H

#include <QWidget>
#include <QMap>
class QMenuBar;
class getServerDialog;
class Handler;
class v2Server;

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

    void serverAdded(v2Server *);

    void on_connectButton_clicked();

    void on_pushButton_2_clicked();


    void on_listWidget_doubleClicked(const QModelIndex &index);


    void on_listWidget_clicked(const QModelIndex &index);

    void on_deleteServerButton_clicked();

private:
    Ui::v2Ui *ui;
    getServerDialog * dialog;
    void updateList();
    QMap<QString , v2Server *> listMap;
    v2Server * selectedServer;

};
#endif // V2UI_H
