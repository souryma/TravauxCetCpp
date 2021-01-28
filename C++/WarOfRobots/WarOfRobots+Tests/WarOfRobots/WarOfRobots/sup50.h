/*!
 * \file sup50.h
 * \brief Etat "Bon" d'un joueur (points de vie entre 80 et 50)
 * \author Antoine Martin
 *
 */

#ifndef SUP50_H
#define SUP50_H
#include "state.h"
#include "player.h"

/*! \class sup50
 * \brief Classe héritée de state qui correspond à l'état bon du joueur
 *
 *
 */

class sup50 : public State
{
private:
    Player *player;     /*!< Le joueur*/
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe sup50
     *  \param player : Le joueur qui a cet état
     */
    sup50(Player *player);

    /*!
     *  \brief Attaque
     *
     *  Attaque pour l'état bon (supérieur à 50 points de vie)
     *  \param cost : le coût de l'attaque
     *  \return les dégats infligés par l'attaque
     */
    int attack(int cost) override;

    /*!
     *  \brief Défense
     *
     *  Défense de l'état bon (supérieur à 50 points de vie)
     *  \param attack : L'attaque infligée
     */
    void defense(double attack) override;

    /*!
     *  \brief Soin
     *
     *  Le soin de l'état bon (points de vie supérieurs à 50)
     */
    void heal() override;

};

#endif // SUP50_H
