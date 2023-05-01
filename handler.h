#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>


class v2Server;
class QProcess;
class v2Ui;

class Handler : public QObject
{
    Q_OBJECT
public:
    explicit Handler(QObject *parent = nullptr, v2Ui * ui = nullptr);
    QList<v2Server*> serverList;
    void addServer(v2Server * server);
    void removeServer(v2Server * server);
    v2Server * activeServer=nullptr;
    void setActiveServer(v2Server * server);
    void connectToServer(v2Server * serverToConnect);
    void disconnect();

private:
    QProcess * process;
    v2Ui * Ui;

signals:
    void serverAdded(v2Server * server);
    void serverRemoved(v2Server * server);

public slots:
    void readyReadStandardOutput();


signals:

};

#endif // HANDLER_H
