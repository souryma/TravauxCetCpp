/*!
 * \file main.cpp
 * \brief programme principal du projet
 * \author Antoine Martin
 *
 */

#include <QCoreApplication>
#include <iostream>
#include "game.h"

using namespace std;

int main() {
    Game * game = new Game();

    // On demande le nombre de joueurs dans la partie
    int nbPlayers=0;
    cout<<"Nombre de joueurs dans la partie (entre 3 et 10)? -> ";
    cin>>nbPlayers;
    while (nbPlayers>10 or nbPlayers<3) {
        cout<<"Le nombre de joueurs DOIT être entre 1 et 10, nombre de joueurs : ";
        cin>>nbPlayers;
    }
    cout<<endl;

    // On demande le nom pour chaque joueur
    string * name[nbPlayers];
    for (int I=0; I<nbPlayers; I++) {
        cout<<"Entrez nom joueur "<<I+1<<" : ";
        cin>>* name[I];
    }

    // On créé et on ajoute chaque joueur souhaité
    Player *playerOne = new Player(100,* name[0]);
    game->addPlayer(playerOne);
    Player *playerTwo= new Player(100,* name[1]);
    game->addPlayer(playerTwo);
    Player *playerThree = new Player(100,* name[2]);
    game->addPlayer(playerThree);
    if (nbPlayers == 4) {
        Player *playerFour = new Player(100,* name[3]);
        game->addPlayer(playerFour);
    }
    if (nbPlayers == 5) {
        Player *playerFour = new Player(100,* name[3]);
        game->addPlayer(playerFour);
        Player *playerFive = new Player(100,* name[4]);
        game->addPlayer(playerFive);
    }
    if (nbPlayers == 6) {
        Player *playerFour = new Player(100,* name[3]);
        game->addPlayer(playerFour);
        Player *playerFive = new Player(100,* name[4]);
        game->addPlayer(playerFive);
        Player *playerSix = new Player(100,* name[5]);
        game->addPlayer(playerSix);
    }
    if (nbPlayers == 7) {
        Player *playerFour = new Player(100,* name[3]);
        game->addPlayer(playerFour);
        Player *playerFive = new Player(100,* name[4]);
        game->addPlayer(playerFive);
        Player *playerSix = new Player(100,* name[5]);
        game->addPlayer(playerSix);
        Player *playerSeven = new Player(100,* name[6]);
        game->addPlayer(playerSeven);
    }
    if (nbPlayers == 8) {
        Player *playerFour = new Player(100,* name[3]);
        game->addPlayer(playerFour);
        Player *playerFive = new Player(100,* name[4]);
        game->addPlayer(playerFive);
        Player *playerSix = new Player(100,* name[5]);
        game->addPlayer(playerSix);
        Player *playerSeven = new Player(100,* name[6]);
        game->addPlayer(playerSeven);
        Player *playerEight = new Player(100,* name[7]);
        game->addPlayer(playerEight);
    }
    if (nbPlayers == 9) {
        Player *playerFour = new Player(100,* name[3]);
        game->addPlayer(playerFour);
        Player *playerFive = new Player(100,* name[4]);
        game->addPlayer(playerFive);
        Player *playerSix = new Player(100,* name[5]);
        game->addPlayer(playerSix);
        Player *playerSeven = new Player(100,* name[6]);
        game->addPlayer(playerSeven);
        Player *playerEight = new Player(100,* name[7]);
        game->addPlayer(playerEight);
        Player *playerNine = new Player(100,* name[8]);
        game->addPlayer(playerNine);
    }
    if (nbPlayers == 10) {
        Player *playerFour = new Player(100,* name[3]);
        game->addPlayer(playerFour);
        Player *playerFive = new Player(100,* name[4]);
        game->addPlayer(playerFive);
        Player *playerSix = new Player(100, *name[5]);
        game->addPlayer(playerSix);
        Player *playerSeven = new Player(100,* name[6]);
        game->addPlayer(playerSeven);
        Player *playerEight = new Player(100,* name[7]);
        game->addPlayer(playerEight);
        Player *playerNine = new Player(100,* name[8]);
        game->addPlayer(playerNine);
        Player *playerTen = new Player(100,* name[9]);
        game->addPlayer(playerTen);
    }

    // Explication d'un tour de jeu

    // le joueur 1 attaque le joueur 2 et le joueur 3
    playerTwo->defense(playerOne->attack());
    playerThree->defense(playerOne->attack());

    // les joueurs 2 et 3 se soignent
    playerTwo->heal();
    playerThree->heal();

    // On vérifie si les joueurs doivent changer d'état
    playerOne->changeState(playerOne->getHealth());
    playerTwo->changeState(playerTwo->getHealth());
    playerThree->changeState(playerThree->getHealth());

    // On vérifie si un joueur est mort
    game->checkAlive(playerOne->getName());
    game->checkAlive(playerTwo->getName());
    game->checkAlive(playerThree->getName());

    // On recommence : les joueurs 2, 3, etc,  attaquent, les joueurs attaqués se défendent, etc ...

    // La partie s'arrête lorsqu'il ne reste plus qu'un joueur en vie.


}
