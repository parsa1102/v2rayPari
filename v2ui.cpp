#include "v2ui.h"
#include "./ui_v2ui.h"
#include <QMenuBar>
#include <getserverdialog.h>
#include <QDebug>
#include <QJsonDocument>
#include <v2server.h>
#include <handler.h>
#include <QStringList>
#include <QMap>





v2Ui::v2Ui(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::v2Ui)
{
    ui->setupUi(this);
    handler = new Handler(new QObject ,this);
    dialog = new getServerDialog(this);
    connect(handler , &Handler::serverAdded , this , &v2Ui::serverAdded);
}

v2Ui::~v2Ui()
{
    delete ui;
}

void v2Ui::setV2rayOutput(QString str)
{
    ui->v2rayOutput->setText(str);
}


void v2Ui::on_pushButton_clicked()
{
    dialog->exec();
    QString jsonString = dialog->jsonString;
    QJsonDocument * doc = new QJsonDocument(QJsonDocument::fromJson(jsonString.toUtf8()));
    v2Server * serverToBeAdded = new v2Server(this, doc);
    handler->addServer(serverToBeAdded);
    //tmp to be updated (having a list of servers with the ability to choose active server)
    handler->setActiveServer(serverToBeAdded);

}

void v2Ui::serverAdded(v2Server *)
{
    updateList();
}

void v2Ui::on_connectButton_clicked()
{
    handler->connectToServer(handler->activeServer);
}

void v2Ui::updateList()
{
    QStringList list;
    foreach(v2Server* server , handler->serverList){
        listMap[server->serverIP + ":" + server->serverPort] = server;
        list.append(server->serverIP + ":" + server->serverPort);
    }
    ui->listWidget->clear();
    ui->listWidget->addItems(list);
}

void v2Ui::on_pushButton_2_clicked()
{
    handler->disconnect();
}

void v2Ui::on_listWidget_doubleClicked(const QModelIndex &index)
{
    v2Server * tempServer = listMap[index.data(Qt::DisplayRole).toString()];
    handler->activeServer = tempServer;
}
