#ifndef V2SERVER_H
#define V2SERVER_H

#include <QObject>
class QJsonDocument;

class v2Server : public QObject
{
    Q_OBJECT
public:
    explicit v2Server(QObject *parent = nullptr , QJsonDocument * doc = nullptr);
    ~v2Server();
    QString serverIP;
    QString serverPort;

    QJsonDocument * serverJson;

private:
    void IpPortSetter();

signals:

};

#endif // V2SERVER_H
