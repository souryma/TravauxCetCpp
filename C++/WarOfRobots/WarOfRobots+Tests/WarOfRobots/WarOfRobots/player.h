/*!
 * \file player.h
 * \brief Un joueur
 * \author Antoine Martin
 *
 */


#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "state.h"

using namespace std;

/*! \class Player
 * \brief classe qui représente un joueur
 *
 *
 */

class Player
{
private:
    int health;         /*!< La vie du joueur*/
    string name;        /*!< Le nom du joueur*/
    State * hisState;    /*!< L'état du joueur*/

public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe player
     *  \param health : vie du joueur
     *  \param nom : nom du joueur
     */

    Player(int health, string name);

    /*!
     *  \brief Attaque
     *
     *  Attaque du joueur en fonction de son état (+ dégâts infligés à lui même par sa propre attaque)
     *  \return les dégâts que le joueur souhaite infliger
     */
    int attack ();

    /*!
     *  \brief Défense
     *
     *  Encaissement des dégâts une fois la défense appliquée en fonction de l'état du joueur
     *  \param cost : les dégâts infligés par l'attaque
     */
    void defense(int cost);

    /*!
     *  \brief Soin
     *
     *  Le soin attribué au joueur
     */
    void heal();

    /*!
     *  \brief Attribution de l'état
     *
     *  Permet d'attribuer le bon état au joueur en fonction de son nombre de points de vie
     *  \param health : les points de vie du joueur
     */
    void changeState(int health);

    /*!
     *  \brief Setter de l'état du joueur
     */
    void setState (State * newState);

    /*!
     *  \brief Getter de la santé du joueur
     */
    int getHealth();

    /*!
     *  \brief Setter de l'état du joueur
     */
    void setHealth (int h);

    /*!
     *  \brief Getter du nom du joueur
     */
    string getName();

};

#endif // PLAYER_H
