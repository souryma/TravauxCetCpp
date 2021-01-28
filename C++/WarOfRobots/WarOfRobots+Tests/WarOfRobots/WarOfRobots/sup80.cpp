/*!
 * \file sup80.cpp
 * \brief définiton de la classe sup80
 * \author Antoine Martin
 *
 */

#include "sup80.h"
#include "sup50.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



Sup80::Sup80(Player *player)
{
    this->player=player;
}


int Sup80::attack(int cost) {
    int count =0;
    count = cost * 1.5;
    player->setHealth(player->getHealth()-cost);
    return count;
}

void Sup80::defense(double attack) {
    attack=attack*0.75;
    player->setHealth(player->getHealth()-attack);
}

void Sup80::heal() {
    int alea = 0;
    srand(time(NULL));
    alea = rand() % 101;
    if (20>=alea && alea>=0) {
        player->setHealth(player->getHealth()+10);
        cout<<"Vous regagnez 10 points de vie!"<<endl;
    }
    alea = rand() % 101;
    if (40>=alea && alea>=0) {
        player->setHealth(player->getHealth()+5);
        cout<<"Vous regagnez 5 points de vie!"<<endl;
    }
}
