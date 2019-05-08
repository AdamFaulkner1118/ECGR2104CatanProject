#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Player{
    private:
    string name;
    
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
    void printResources();
    void printVictoryPoints();
    
};

#endif