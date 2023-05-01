#include "v2ui.h"
#include "./ui_v2ui.h"
#include <QMenuBar>
#include <getserverdialog.h>
#include <QDebug>
#include <QJsonDocument>
#include <v2server.h>
#include <handler.h>



v2Ui::v2Ui(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::v2Ui)
{
    ui->setupUi(this);
    handler = new Handler(new QObject ,this);
    dialog = new getServerDialog(this);
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

void v2Ui::on_connectButton_clicked()
{
    handler->connectToServer(handler->activeServer);
}
