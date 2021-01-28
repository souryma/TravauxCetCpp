/*!
 * \file sup0.cpp
 * \brief définiton de la classe sup0
 * \author Antoine Martin
 *
 */

#include "sup0.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

sup0::sup0(Player *player)
{
    this->player=player;
}


int sup0::attack(int cost) {
    int count =0;
    count = cost;
    player->setHealth(player->getHealth()-cost);
    return count;
}

void sup0::defense(double attack) {
    attack=attack*1;
    player->setHealth(player->getHealth()-attack);
}

void sup0::heal() {
    int alea = 0;
    srand(time(NULL));
    alea = rand() % 101;
    if (10>=alea && alea>=0) {
        player->setHealth(player->getHealth()+20);
        cout<<"Vous regagnez 20 points de vie!"<<endl;
    }
    alea = rand() % 101;
    if (10>=alea && alea>=0) {
        player->setHealth(player->getHealth()+10);
        cout<<"Vous regagnez 10 points de vie!"<<endl;
    }
    alea = rand() % 101;
    if (10>=alea && alea>=0) {
        player->setHealth(player->getHealth()+5);
        cout<<"Vous regagnez 5 points de vie!"<<endl;
    }
}
