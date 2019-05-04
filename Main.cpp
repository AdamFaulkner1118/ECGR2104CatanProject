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

void buildBoard(vector<Tile*> &tiles, int row, int col){
        Tile* t=NULL;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int L=rand() % 4;
                int R=0;
                int n=(rand() % 12)+ 1 ;
                string name="Null";
                t= new Tile((LandType)L, (ResourcesType)R, n, name);
                tiles.push_back(t);
            }
        }
}

void renderBoard(vector<Tile*> &tiles, int row, int col){
    int t=0;
    if(tiles.size()>0){
        //For the number of rows
        for(int n=0; n<row; n++){
            //For the number of string lines
            for(int i=0; i<=8; i++){
                //For the number of columns
                        int j=(((n+1)-1)*col);
                        int j2=(((n+1)-1)*col)+col;
                        for(j; j<j2; j++){
                            cout<<tiles.at(j)->render(i);
                        }
                cout<< endl;
            }
        }
    }
    else{
        for(int i = 0; i < row; i++)
            cout << endl;
    }
}


int main() {
    srand(time(0));
    vector<Tile*> tiles;
    
    int row=5;
    int col=7;
    
    int totalPlayerCount;
    
cout << "Hi! Welcome to Settlers of Catan++" <<endl;
cout << "Please enter the number of people playing: (2-6) " <<endl;
cin >> totalPlayerCount;


Player players[totalPlayerCount];


//Rosa, how do I use the rendering of the gameboard?
buildBoard(tiles, row, col);
    cout<<"Number of tiles: "<<tiles.size()<<endl;
    
    renderBoard(tiles, row, col);
    cout<<endl;




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

//g++ Main.cpp GameBoard.cpp Player.cpp Tile.cpp GameManager.cpp -o test -std=c++11