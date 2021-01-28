/*!
 * \file sup80.h
 * \brief Etat "Excellent" d'un joueur (points de vie supérieurs à 80)
 * \author Antoine Martin
 *
 */

#ifndef SUP80_H
#define SUP80_H
#include "state.h"
#include "player.h"

/*! \class sup80
 * \brief Classe héritée de state qui correspond à l'état excellent d'un joueur
 *
 *
 */

class Sup80 : public State
{
private:
    Player *player;     /*!< Le joueur*/
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe sup80
     *  \param player : Le joueur qui a cet état
     */
    Sup80(Player *player);

    /*!
     *  \brief Attaque
     *
     *  Attaque pour l'état excellent (supérieur à 80 points de vie)
     *  \param cost : le coût de l'attaque
     *  \return les dégats infligés par l'attaque
     */
    int attack(int cost) override;

    /*!
     *  \brief Défense
     *
     *  Défense de l'état excellent (supérieur à 80 points de vie)
     *  \param attack : L'attaque infligée
     */
    void defense(double attack) override;

    /*!
     *  \brief Soin
     *
     *  Le soin de l'état excellent (points de vie supérieurs à 80)
     */
    void heal() override;

};

#endif // SUP80_H
