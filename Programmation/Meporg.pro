QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11,console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = MePorg

SOURCES += \
    aboutwindow.cpp \
    demon.cpp \
    enemydemon.cpp \
    enemyhuman.cpp \
    enemywerewolf.cpp \
    enemywolf.cpp \
    entity.cpp \
    game.cpp \
    herodemon.cpp \
    herohuman.cpp \
    herowerewolf.cpp \
    herowolf.cpp \
    human.cpp \
    job.cpp \
    item.cpp \
    level.cpp \
    main.cpp \
    mainwindow.cpp \
    werewolf.cpp \
    wolf.cpp

HEADERS += \
    aboutwindow.h \
    demon.h \
    enemydemon.h \
    enemyhuman.h \
    enemywerewolf.h \
    enemywolf.h \
    entity.h \
    game.h \
    herodemon.h \
    herohuman.h \
    herowerewolf.h \
    herowolf.h \
    human.h \
    job.h \
    item.h \
    level.h \
    mainwindow.h \
    werewolf.h \
    wolf.h

RC_FILE = settings.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Meporg.pro.user \
    TODO \
    icon.ico \
    settings.rc
