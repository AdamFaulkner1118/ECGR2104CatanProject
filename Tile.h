#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Tile {
    private:
    string landType;
    int diceNum;
    
    public:
    int owner;
    string settleType;
    Tile(); // Includes random number generators for landType and diceNum. Also initializes owner and settleType.
}


#endif