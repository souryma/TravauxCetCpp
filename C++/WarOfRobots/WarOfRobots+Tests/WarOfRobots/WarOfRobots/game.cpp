/*!
 * \file game.cpp
 * \brief définiton de la classe game
 * \author Antoine Martin
 *
 */

#include "game.h"

Game::Game()
{

}

void Game::addPlayer(Player * player) {
    gameList->push_back(player);
}

bool Game::checkAlive(string name) {
    bool alive = false;

    for(Player * player : *gameList)
    {
        if(player->getName() == name)
        {
            if (player->getHealth()>0) {
                alive = true;
            }
        }
    }
    return alive;
}

list<Player*> Game::getPlayers(){
    return *this->gameList;
}
