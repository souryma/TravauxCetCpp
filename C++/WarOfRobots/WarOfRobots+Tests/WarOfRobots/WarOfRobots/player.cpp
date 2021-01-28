/*!
 * \file player.cpp
 * \brief définiton de la classe player
 * \author Antoine Martin
 *
 */

#include "player.h"
#include "sup0.h"
#include "sup30.h"
#include "sup50.h"
#include "sup80.h"
#include "dead.h"

Player::Player(int health, string name)
{
    this->health=health;
    this->name=name;
    this->hisState = new Sup80(this);
}

int Player::attack() {
    int value=0;
    cout<<"De combien voulez vous attaquer ?"<<endl;
    cin>>value;
    while (value>10 or value<0) {
        cout<<"L'attaque doit être comprise entre 0 et 10"<<endl;
        cout<<"De combien voulez vous attaquer ?"<<endl;
        cin>>value;
    }
    int cost = 0;
    cost = hisState->attack(value);
    return cost;
}

void Player::defense(int cost) {
    hisState->defense(cost);
}


void Player::changeState(int health) {
    if(health>=80)
    {
        this->setState(new Sup80(this));
    }

    if(health <=79 && health >=50)
    {
        this->setState(new sup50(this));
    }

    if(health <=49 && health >=30)
    {
        this->setState(new sup30(this));
    }

    if(health <=29 && health >0)
    {
        this->setState(new sup0(this));
    }

    if(health <=0)
    {
        this->setState(new Dead(this));
    }
}

void Player::setState (State * newState) {
    this->hisState = newState;
}

void Player::setHealth (int h) {
    this->health = h;
}

int Player::getHealth() {
    return health;
}

string Player::getName() {
    return name;
}
