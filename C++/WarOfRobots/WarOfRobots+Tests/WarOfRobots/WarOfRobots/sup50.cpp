/*!
 * \file sup50.cpp
 * \brief définiton de la classe sup50
 * \author Antoine Martin
 *
 */

#include "sup50.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

sup50::sup50(Player *player)
{
    this->player=player;
}


int sup50::attack(int cost) {
    int count =0;
    count = cost;
    player->setHealth(player->getHealth()-cost);
    return count;
}

void sup50::defense(double attack) {
    attack=attack*1;
    player->setHealth(player->getHealth()-attack);
}

void sup50::heal() {
    int alea = 0;
    srand(time(NULL));
    alea = rand() % 101;
    if (70>=alea && alea>=0) {
        player->setHealth(player->getHealth()+5);
        cout<<"Vous regagnez 5 points de vie!"<<endl;
    }
}
