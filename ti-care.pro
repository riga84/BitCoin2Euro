SOURCES      = main.cpp \
    bitcoin2euro.cpp \
    mywidget.cpp

QT += widgets
QT += network
LIBS += -lssl -lcrypto

simulator: warning(This example might not fully work on Simulator platform)

HEADERS += \
    bitcoin2euro.h \
    mywidget.h
