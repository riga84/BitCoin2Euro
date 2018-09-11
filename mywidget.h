#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QTimer>
#include<QLabel>
#include <bitcoin2euro.h>

class MyWidget : public QObject
{
    Q_OBJECT

    private:
        QTimer *timer;
        QLabel *label;
        BitCoin2Euro *Bit2Eu;
    //
    public:
        MyWidget(QLabel *, QString, int);

    //slots
    public slots:
        void refreshData();
};

#endif // MYWIDGET_H
