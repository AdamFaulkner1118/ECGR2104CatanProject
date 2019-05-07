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

vector<int> land;
vector<int> resorces;
vector<int> num;
vector<string> names;
vector<int> settOrCity;
void buildBoard(vector<Tile*> &tiles, int row, int col){
        //Tile* t=NULL;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int L=rand() % 5;
                int R=L;
                int n=(rand() % 12)+ 1 ;
                string name="Null";
                int choice=-1;
                settOrCity.push_back(-1);
                tiles.push_back(new Tile((LandType)L, (ResourcesType)R, n, name, choice));
                //tiles.push_back(t);
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

void updateBoard(vector<Tile*> &tiles, string name, int col, int rowNum, int colNum, int choice){
    int tileNum=((rowNum-1)*col)+(colNum-1);
    tiles.push_back(new Tile((LandType)land.at(tileNum), (ResourcesType)resorces.at(tileNum), num.at(tileNum), name, choice));
    tiles[tileNum]=tiles.at(tiles.size()-1);
    names.at(tileNum)=name;
    settOrCity.at(tileNum)=choice;
    //To delete index just made
    tiles.pop_back();
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
    
    //To update board: need string name, row number and column number
    //The col variable is the total number of columns
    string name ="PersonName";
    cout<<"Enter row number";
    int rowNum;
    cin>>rowNum;
    cout<<"Enter column number";
    int colNum;
    cin>>colNum;
    cout<<"Enter 0:Settelment or 1:City: ";
    int choice;
    cin>>choice;
    updateBoard(tiles, name, col, rowNum, colNum, choice);
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


