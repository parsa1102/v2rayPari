#include "v2server.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

v2Server::v2Server(QObject *parent, QJsonDocument *doc) : QObject(parent)
{
    serverJson = doc;
    IpPortSetter();
}

v2Server::~v2Server()
{
    qInfo()<<"server deleted";
}

void v2Server::IpPortSetter()
{
    QJsonDocument * doc = serverJson;
    if(doc->isObject()){
        QJsonObject jsonObject = doc->object();

        auto list_of_keys = jsonObject.keys();

        QJsonArray outboundObj = jsonObject.value("outbounds").toArray();
        for (auto const& array_value : outboundObj)
        {
            auto obj_value = array_value.toObject();

            auto keys = obj_value.keys();

            if (keys.contains("settings"))
            {
                auto settings_obj_value = obj_value.value("settings").toObject();
                auto vnext_value = settings_obj_value.value("vnext").toArray();
                auto vnext_inner_array = vnext_value.takeAt(0).toObject();
                auto address = vnext_inner_array.value("address").toString();
                auto port = vnext_inner_array.value("port").toInt();

                if (!address.isEmpty() && 0 != port)
                {
                    serverIP = address;
                    serverPort = QString::number(port);
                }
            }
        }


    }
}
