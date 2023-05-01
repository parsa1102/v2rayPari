#include "handler.h"
#include <v2server.h>

#include <algorithm>
#include <QDebug>
#include <QJsonDocument>
#include <QFile>
#include <QProcess>
#include <QTimer>
#include <QTextStream>
#include <v2ui.h>

Handler::Handler(QObject *parent, v2Ui * ui) : QObject(parent)
{
    qInfo()<<"handler started";
    Ui = ui;
    process = new QProcess;


}

void Handler::addServer(v2Server * server)
{
    serverList.append(server);
    emit serverAdded(server);
}

void Handler::removeServer(v2Server * server)
{
    // finding index number of the v2Server object
    QList<v2Server*>::iterator index_iter = std::find(serverList.begin(), serverList.end(), server);

    int index_number = 0;
    if (serverList.end() != index_iter)
        index_number = std::distance(serverList.begin(), index_iter);
    else
        throw std::runtime_error("the server doesn't exist in the list");

    serverList.removeAt(index_number);
    emit serverRemoved(server);
}

void Handler::setActiveServer(v2Server * server)
{
    activeServer = server;
}

void Handler::connectToServer(v2Server * serverToConnect)
{
    //QJsonDocument * json = activeServer->serverJson;
    QJsonDocument * json = serverToConnect->serverJson;
    QString jsonString = QString(json->toJson());
    QFile config("/home/arad/proj/v2rayParsa/v2rayRunner/config.json");
    config.open(QFile::ReadWrite);
    config.resize(0);
    config.write(jsonString.toUtf8());
    config.flush();
    //process->start();
    connect(process , &QProcess::readyReadStandardOutput , this , &Handler::readyReadStandardOutput);
    process->setWorkingDirectory("/home/arad/proj/v2rayParsa/v2rayRunner");
    process->start("/home/arad/proj/v2rayParsa/v2rayRunner/v2ray" , QStringList() << "run");
    process->waitForStarted();
    //connect(process , &QProcess::readyReadStandardError , this , &Handler::readyReadStandardOutput);
    //process->waitForFinished();
    qInfo()<<"finished";
    //qInfo()<<process->errorString();
}

void Handler::readyReadStandardOutput()
{
    qInfo()<<"readyReadStandardOutput";
    Ui->setV2rayOutput(process->readAllStandardOutput());
}
