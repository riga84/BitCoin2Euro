#include <QApplication>
#include <QLabel>
#include <mywidget.h>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QLabel label;
    MyWidget myWidget(&label, "https://www.bitstamp.net/api/v2/ticker/btceur/", 10000);

    return app.exec();
}
