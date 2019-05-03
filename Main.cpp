#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include "GameBoard.h"
#include "GameManager.h"
#include "Player.h"
#include "Tile.h"

int main() {
    
    int totalPlayerCount;
    
cout << "Hi! Welcome to Settlers of Catan++" <<endl;
cout << "Please enter the number of people playing: (2-6) " <<endl;
cin >> totalPlayerCount;


Player players[totalPlayerCount];


//Rosa, how do I use the rendering of the gameboard?
GameBoard gameboard;
gameboard.render(5);



//logic for creating players
// for (int i=0; i < totalPlayerCount; i++){
//     string playerName;
//     cout << "Player " << i+1 << ", please enter your name: " << endl;
//     cin << playerName << endl;
    
//     players[i] = new Player(playerName);
    //initialize resources etc.
    //

//Logic for creating game board

//loop for gameplay


    return 0;
}