/*!
 * \file dead.cpp
 * \brief définiton de la classe dead
 * \author Antoine Martin
 *
 */

#include "dead.h"

Dead::Dead(Player * player)
{
    this->player=player;
}


int Dead::attack(int cost) {
    return 0;
}

void Dead::defense(double attack) {

}

void Dead::heal() {

}
