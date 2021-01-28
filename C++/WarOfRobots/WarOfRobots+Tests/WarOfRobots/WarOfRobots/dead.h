/*!
 * \file dead.h
 * \brief etat "mort" d'un joueur
 * \author Antoine Martin
 *
 */

#ifndef DEAD_H
#define DEAD_H
#include "state.h"
#include "player.h"

/*! \class Dead
 * \brief classe qui représente l'état "mort" pour un joueur (points de vie inférieurs à 0)
 *
 *
 */

class Dead : public State
{
private:
    Player *player; /*!< Le joueur en question*/
public:

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Dead
     *  \param player : le joueur mort
     */
    Dead(Player *player);

    /*!
     *  \brief Attaque
     *
     *  La méthode ne renvoie rien (les morts n'attaquent pas)
     *  \param cost : le coût de l'attaque
     *  \return les dégats infligés par l'attaque
     */
    int attack(int cost) override;

    /*!
     *  \brief Défense
     *
     *  La méthode ne renvoie rien (les morts ne se défendent pas)
     *  \param attack : L'attaque infligée
     */
    void defense(double attack) override;

    /*!
     *  \brief Soin
     *
     *  La méthode ne renvoie rien (les morts ne peuvent pas re-vivre pas)
     */
    void heal() override;
};

#endif // DEAD_H
