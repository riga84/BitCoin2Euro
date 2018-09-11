#include "mywidget.h"


//params:
//lab = label show data
//strLink = link get data
//intDelay = delay refresh data
MyWidget::MyWidget(QLabel * lab, QString strLink, int intDelay)
{
    try
    {
        //label conf
        label = lab;
        label->resize(200, 50);
        label->setWordWrap(true);

        //obj get data link
        Bit2Eu = new BitCoin2Euro();
        Bit2Eu->setLink(strLink);

        //get first data
        refreshData();
        label->show();

        //set timer refresh
        timer = new QTimer(this);
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refreshData()));
        timer->start(intDelay);

    }catch (...)
    {
        qDebug() << "Exception occurred [MyWidget]";
    }
}

// refresh label data
void MyWidget::refreshData()
{
    try
    {
        label->clear();
        label->setText(
                        QDate::currentDate().toString() + " - " +
                        QTime::currentTime().toString() +
                        " BitCoin2Euro: "+ Bit2Eu->getData());

    } catch (...)
    {
        qDebug() << "Exception occurred [refreshData]";
    }
}

