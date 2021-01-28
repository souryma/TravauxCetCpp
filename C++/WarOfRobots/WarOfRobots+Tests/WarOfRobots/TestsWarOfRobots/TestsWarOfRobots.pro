QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += tst_unittest.cpp \
    ../WarOfRobots/dead.cpp \
    ../WarOfRobots/game.cpp \
    ../WarOfRobots/player.cpp \
    ../WarOfRobots/state.cpp \
    ../WarOfRobots/sup0.cpp \
    ../WarOfRobots/sup30.cpp \
    ../WarOfRobots/sup50.cpp \
    ../WarOfRobots/sup80.cpp

HEADERS += \
    ../WarOfRobots/dead.h \
    ../WarOfRobots/game.h \
    ../WarOfRobots/player.h \
    ../WarOfRobots/state.h \
    ../WarOfRobots/sup0.h \
    ../WarOfRobots/sup30.h \
    ../WarOfRobots/sup50.h \
    ../WarOfRobots/sup80.h
