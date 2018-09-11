#include <bitcoin2euro.h>

//
void BitCoin2Euro::setLink(QString strLink)
{
    try
    {
        link = strLink;
        request.setUrl(QUrl(link));
    } catch (...) {
         qDebug() << "Exception occurred [setLink]";
    }

}

QString BitCoin2Euro::getLink()
{
    return link;
}

void BitCoin2Euro::connect2Page()
{
    try
    {
        response = manager.get(request);
    } catch (...) {
        qDebug() << "Exception occurred [connect2Page]";
    }

}

QString BitCoin2Euro:: getData()
{
    try
    {
        connect2Page();
        QObject::connect(response,SIGNAL(finished()),&event,SLOT(quit()));
        event.exec();
        html = response->readLine();
        doc = QJsonDocument::fromJson(html.toUtf8());
        jObject = doc.object();
        mainMap = jObject.toVariantMap();
        return mainMap["last"].toString();
    } catch (...) {
        qDebug() << "Exception occurred [getData]"; //Date:" << QDate::currentDate();
        return "";
    }
}
