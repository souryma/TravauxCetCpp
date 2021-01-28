/*!
 * \file state.h
 * \brief définit les états
 * \author Antoine Martin
 *
 */

#ifndef STATE_H
#define STATE_H
#include "player.h"

/*! \class State
 * \brief Classe abstraite des différents états
 *
 *
 */

class State
{
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe State
     *
     */
    State();

    /*!
     *  \brief Attaque
     *
     *  Attaque propre à chaque état
     *  \param cost : le coût de l'attaque
     *  \return les dégats infligés par l'attaque
     */
    virtual int attack(int cost) = 0;

    /*!
     *  \brief Défense
     *
     *  Défense propre à chaque état
     *  \param attack : L'attaque infligée
     */
    virtual void defense(double attack) = 0;

    /*!
     *  \brief Soin
     *
     *  Le soin propre à chaque état
     */
    virtual void heal() = 0;

};

#endif // STATE_H
