/*!
 * \file sup0.h
 * \brief Etat "faible" d'un joueur (points de vie entre 30 et 0)
 * \author Antoine Martin
 *
 */

#ifndef SUP0_H
#define SUP0_H
#include "state.h"
#include "player.h"

/*! \class sup0
 * \brief Classe héritée de state qui correspond à l'état faible du joueur
 *
 *
 */

class sup0 : public State
{
private:
    Player *player;     /*!< Le joueur*/
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe sup0
     *  \param player : Le joueur qui a cet état
     */
    sup0(Player *player);

    /*!
     *  \brief Attaque
     *
     *  Attaque pour l'état faible (supérieur à 0 points de vie)
     *  \param cost : le coût de l'attaque
     *  \return les dégats infligés par l'attaque
     */
    int attack(int cost) override;

    /*!
     *  \brief Défense
     *
     *  Défense de l'état faible (supérieur à 0 points de vie)
     *  \param attack : L'attaque infligée
     */
    void defense(double attack) override;

    /*!
     *  \brief Soin
     *
     *  Le soin de l'état faible (points de vie supérieurs à 0)
     */
    void heal() override;

};

#endif // SUP0_H
