/*!
 * \file tst_unittest.cpp
 * \brief Tests unitaires
 * \author Antoine Martin
 *
 */

// add necessary includes here
#include <QtTest/QtTest>
#include <QObject>
#include "../WarOfRobots/game.h"
#include "../WarOfRobots/player.h"
#include "../WarOfRobots/sup80.h"
#include "../WarOfRobots/sup50.h"
#include "../WarOfRobots/sup30.h"
#include "../WarOfRobots/sup0.h"


class UnitTest : public QObject
{
    Q_OBJECT

public:
    UnitTest();
    ~UnitTest();

private slots:

    // Test de Game
    void testGameCheckAlive();

    // Tests de Player
    void testPlayerAttack();
    void testPlayerGetHealth();
    void testPlayerGetName();

    // Test de Sup80
    void testSup80Attack();

    // Test de sup50
    void testSup50Attack();

    // Test de sup30
    void testSup30Attack();

    // Test de sup0
    void testSup0Attack();

};


void UnitTest::testGameCheckAlive(){
    Game * gameTest = new Game();
    Player * playerTest = new Player(100, "robot");
    gameTest->addPlayer(playerTest);
    QCOMPARE(gameTest->checkAlive("robot"), true);
}

void UnitTest::testPlayerAttack(){
    Player * playerTest = new Player(100, "robot");
    QCOMPARE(playerTest->attack(), 10);
}

void UnitTest::testPlayerGetHealth(){
    Player * playerTest = new Player(100, "robot");
    QCOMPARE(playerTest->getHealth(), 100);
}

void UnitTest::testPlayerGetName(){
    Player * playerTest = new Player(100, "robot");
    QCOMPARE(playerTest->getName(), "robot");
}

void UnitTest::testSup80Attack(){
    Player * playerTest = new Player(100, "robot");
    Sup80 * stateExcellent = new Sup80(playerTest);
    QCOMPARE(stateExcellent->attack(4), 6);
}

void UnitTest::testSup50Attack(){
    Player * playerTest = new Player(100, "robot");
    sup50 * stateGood = new sup50(playerTest);
    QCOMPARE(stateGood->attack(4), 4);
}

void UnitTest::testSup30Attack(){
    Player * playerTest = new Player(100, "robot");
    sup30 * stateMedium = new sup30(playerTest);
    QCOMPARE(stateMedium->attack(4), 4);
}

void UnitTest::testSup0Attack(){
    Player * playerTest = new Player(100, "robot");
    sup0 * stateBad = new sup0(playerTest);
    QCOMPARE(stateBad->attack(4), 4);
}

QTEST_APPLESS_MAIN(UnitTest)

