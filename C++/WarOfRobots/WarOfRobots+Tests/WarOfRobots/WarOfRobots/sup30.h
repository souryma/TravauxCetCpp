/*!
 * \file sup30.h
 * \brief Etat "moyen" d'un joueur (points de vie entre 50 et 30)
 * \author Antoine Martin
 *
 */

#ifndef SUP30_H
#define SUP30_H
#include "state.h"
#include "player.h"

/*! \class sup30
 * \brief Classe héritée de state qui correspond à l'état moyen du joueur
 *
 *
 */

class sup30 : public State
{
private:
    Player *player;     /*!< Le joueur*/
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe sup30
     *  \param player : Le joueur qui a cet état
     */
    sup30(Player *player);

    /*!
     *  \brief Attaque
     *
     *  Attaque pour l'état moyen (supérieur à 30 points de vie)
     *  \param cost : le coût de l'attaque
     *  \return les dégats infligés par l'attaque
     */
    int attack(int cost) override;

    /*!
     *  \brief Défense
     *
     *  Défense de l'état moyen (supérieur à 30 points de vie)
     *  \param attack : L'attaque infligée
     */
    void defense(double attack) override;

    /*!
     *  \brief Soin
     *
     *  Le soin de l'état moyen (points de vie supérieurs à 30)
     */
    void heal() override;

};

#endif // SUP30_H
