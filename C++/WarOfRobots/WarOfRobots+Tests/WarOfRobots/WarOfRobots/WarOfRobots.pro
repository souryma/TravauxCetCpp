QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        dead.cpp \
        game.cpp \
        main.cpp \
        player.cpp \
        state.cpp \
        sup0.cpp \
        sup30.cpp \
        sup50.cpp \
        sup80.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    dead.h \
    game.h \
    player.h \
    state.h \
    sup0.h \
    sup30.h \
    sup50.h \
    sup80.h
