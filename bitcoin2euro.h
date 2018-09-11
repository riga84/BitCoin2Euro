#ifndef BITCOIN2EURO_H
#define BITCOIN2EURO_H

#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

class BitCoin2Euro
{
    //
    private:
        QString link = "", html = "";
        QNetworkAccessManager manager;
        QNetworkRequest request;
        QNetworkReply *response;
        QEventLoop event;
        QJsonDocument doc;
        QJsonObject jObject;
        QVariantMap mainMap;

    //Methods
    public:
        void setLink(QString);
        QString getLink();
        void connect2Page();
        QString getData();
};

#endif // BITCOIN2EURO_H
