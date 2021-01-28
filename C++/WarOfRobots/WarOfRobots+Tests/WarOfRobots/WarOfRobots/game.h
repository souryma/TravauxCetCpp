/*!
 * \file game.h
 * \brief classe qui contient le joueurs
 * \author Antoine Martin
 *
 */

#ifndef GAME_H
#define GAME_H
#include <list>
#include "player.h"

/*! \class Game
 * \brief classe qui représente le jeu (elle contient les joueurs)
 *
 *
 */

class Game
{
    std::list<Player *>* gameList; /*!< Liste des joueurs*/
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Game
     *
     */

    Game();

    /*!
     *  \brief Ajout d'un joueur au jeu
     *
     *  Methode qui permet d'ajouter un joueur à la liste du jeu
     *
     *  \param player : le joueur à ajouter
     */
    void addPlayer(Player * player);

    /*!
     *  \brief Vérifie si toujours vivant
     *
     *  Regarde dans la liste des joueurs si le joueur demandé est toujours vivant
     *
     *  \param name : le nom du joueur à vérifier
     */
    bool checkAlive(string name);

    /*!
     *  \brief Renvoie la liste des joueurs de la partie
     *
     *
     */
    list<Player*> getPlayers();
};

#endif // GAME_H
