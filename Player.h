#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player{
    private:
    string playerName;
    
    public:
    int victoryPoints;
    int woodCount;
    int brickCount;
    int grainCount;
    int woolCount;
    int oreCount;
    
    Player();
    Player(string);
    string getName();
}

#endif