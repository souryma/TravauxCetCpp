/*!
 * \file sup30.cpp
 * \brief définiton de la classe sup30
 * \author Antoine Martin
 *
 */

#include "sup30.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

sup30::sup30(Player *player)
{
    this->player=player;
}


int sup30::attack(int cost) {
    int count =0;
    count = cost;
    player->setHealth(player->getHealth()-cost);
    return count;
}

void sup30::defense(double attack) {
    attack=attack*1;
    player->setHealth(player->getHealth()-attack);
}

void sup30::heal() {
    int alea = 0;
    srand(time(NULL));
    alea = rand() % 101;
    if (30>=alea && alea>=0) {
        player->setHealth(player->getHealth()+10);
        cout<<"Vous regagnez 10 points de vie!"<<endl;
    }
    alea = rand() % 101;
    if (30>=alea && alea>=0) {
        player->setHealth(player->getHealth()+5);
        cout<<"Vous regagnez 5 points de vie!"<<endl;
    }
}
