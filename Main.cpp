#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#include "GameBoard.h"
#include "GameManager.h"
#include "Player.h"

bool victory = false;
bool revert;

string winner;

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
<<<<<<< HEAD
                int n=(rand() % 11)+ 2 ;
=======
                int n=(rand() % 12)+ 1 ;
>>>>>>> 1e5eca9a556e4e0d6d91bc960bce9a6bed869687
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

void setPlayerStart(vector<Player*> players, vector<Tile*> tiles, int row, int column) {
    for (int i = 0; i<players.size(); i++) {
        int homeRow = rand() % row;
        int homeColumn = rand() % column;
        string name = players[i]->getName();
        updateBoard(tiles, name, column, homeRow, homeColumn, 0);
    }
}

void takeTurn(GameManager &gameManager, vector<Player*> players, vector<Tile*> tiles, int row, int col) {
    int rowInput;
    int colInput;
    int offset;
    int aLoc;
    int dice1;
    int dice2;
    int diceTot;
    int x = gameManager.getCurrentPlayer();
    if (revert == false) {
        renderBoard(tiles, row, col);
        cout << players[x]->getName() << "'s turn." << endl;
        players[x]->printVictoryPoints();
        //players[x]->printResources();
    }
    else {
        revert = false;
    }
    
    //dice roll
    dice1 = ((rand()%6)+1);
    srand(time(0));
    dice2 = ((rand()%6)+1);
    
    diceTot = dice1 + dice2;
    cout<<"A(n) "<<diceTot<<" was rolled"<<endl;
    
    
    
    
    for (int tileCnt = 0; tileCnt < tiles.size(); tileCnt++){
        //if tile.num == dice
        if (tiles[tileCnt]->getNumber() == diceTot){
            for (int playCnt = 0; playCnt < players.size(); playCnt++){
                
                
                // cout<<"Tile Cnt "<<tileCnt<<endl;
                // cout<<"playCnt "<<playCnt<<endl;
                // cout<<"tiles[tileCnt]->getLand() "<<tiles[tileCnt]->getLand()<<endl;
                // cout<<"tiles[tileCnt]->getSettOrCity() "<<tiles[tileCnt]->getSettOrCity()<<endl;
                // cout<<"players[playCnt]->getName() "<<players[playCnt]->getName()<<endl;
                // cout<<"tiles[tileCnt]->getPlayer() "<<tiles[tileCnt]->getPlayer()<<endl;
                
                
                //checks if owner is playCnt
                if (players[playCnt]->getName() == tiles[tileCnt]->getPlayer()){ 
                    //check if tile is wood
                    if (tiles[tileCnt]->getLand() == 0){
                        //checks if tile is sett or city
                        if (tiles[tileCnt]->getSettOrCity() == 0){
                            players[playCnt]->woodCount += 1;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 1 Wood"<<endl;
                        } else if (tiles[tileCnt]->getSettOrCity() == 1){
                            players[playCnt]->woodCount += 2;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 2 Wood"<<endl;
                        }
                    }
                    if (tiles[tileCnt]->getLand() == 1){
                        if (tiles[tileCnt]->getSettOrCity() == 0){
                            players[playCnt]->brickCount += 1;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 1 Brick"<<endl;
                        } else if (tiles[tileCnt]->getSettOrCity() == 1){
                            players[playCnt]->brickCount += 2;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 2 Brick"<<endl;
                        }
                    }
                    if (tiles[tileCnt]->getLand() == 2){
                        if (tiles[tileCnt]->getSettOrCity() == 0){
                            players[playCnt]->grainCount += 1;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 1 Grain"<<endl;
                        } else if (tiles[tileCnt]->getSettOrCity() == 1){
                            players[playCnt]->grainCount += 2;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 2 Grain"<<endl;
                        }
                    }
                    if (tiles[tileCnt]->getLand() == 3){
                        if (tiles[tileCnt]->getSettOrCity() == 0){
                            players[playCnt]->woolCount += 1;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 1 Wool"<<endl;
                        } else if (tiles[tileCnt]->getSettOrCity() == 1){
                            players[playCnt]->woolCount += 2;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 2 Wool"<<endl;
                        }
                    }
                    if (tiles[tileCnt]->getLand() == 4){
                        if (tiles[tileCnt]->getSettOrCity() == 0){
                            players[playCnt]->oreCount += 1;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 1 Ore"<<endl;
                        } else if (tiles[tileCnt]->getSettOrCity() == 1){
                            players[playCnt]->oreCount += 2;
                            cout<<"Player "<<players[playCnt]->getName()<<" received 2 Ore"<<endl;
                        }
                    }
                }
            }
        }
    }
    
    players[x]->printResources();
    
    
    
    
    int playerDecision = 0;
    cout << "Do you want to 1: Buy, 2: Trade, or 3: End Turn" << endl;
    cin >> playerDecision;
    if (playerDecision == 1) {
        cout << "What would you like to do?" << endl;
        cout << "1: Build a settlement? (Costs 1 wood, 1 brick, 1 grain, and 1 wool)" << endl;
        cout << "2: Build a city? (Costs 2 ore and 3 grain)" << endl;
        cout << "3: Buy a development card (Costs 1 ore, 1 grain, and 1 wool)" << endl;
        cout << "4: Quit buying" << endl;
        cin >> playerDecision;
        switch (playerDecision) {
            case 1:
                strt:
                if (players[x]->woodCount > 0 && players[x]->brickCount > 0 
                    && players[x]->grainCount > 0 && players[x]->woodCount > 0){    
                    // Check resource requirements
                    cout << "Where would you like to place a settlement? (You must own an adjacent settlement or city)" << endl;
                    cout << "Enter desired row: ";
                    cin >> rowInput;
                    cout << "Enter desired column: ";
                    cin >> colInput;
                    
                    offset = col;
                    aLoc = ((rowInput-1)*col)+(colInput-1);
                    //cout<<"offset: "<<offset<<endl;
                    //cout<<"aLoc: "<<aLoc<<endl;
                    //cout<<"."<<tiles[aLoc]->getPlayer()<<"."<<endl;
                    //cout<<"."<<players[gameManager.getCurrentPlayer()]->getName()<<"."<<endl;
                    
                    
                    //checks resources
                
                    //checks if location has no set or city
                    if (rowInput > row || rowInput < 1 || colInput > col || colInput < 1){
                        cout<<"Location out of bounds, try again..."<<endl;
                        goto strt;
                    //checks to see if existing city/ sett in target
                     
                    } else if (tiles[aLoc]->getSettOrCity() == 0 ||
                        tiles[aLoc]->getSettOrCity() == 1) 
                    {
                        cout<<"There is already a structure in that location, try again..."<<endl;
                        goto strt;
                        
                    //if target is in first row
                    } else if (rowInput == 1){
                        
                        if (colInput == 1){
                            //cout<<"Target in first column"<<endl;
                            //checks to the right and down if choice is 1,1
                            if (tiles[aLoc+1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc+offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()){
                                //build settlement
                               tiles[aLoc]->setSettOrCity(0);
                               //set name
                               tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                               players[x]->woodCount -= 1;
                               players[x]->brickCount -= 1; 
                               players[x]->grainCount -= 1;
                               players[x]->woolCount -= 1;
                               players[x]->victoryPoints++;
                            }
                            else {
                                cout<<"Can't build there..."<<endl;
                                goto strt;
                            }
                        }
                        //if col selection all the way to the right
                        else if (colInput == col){
                            //checks to the left and down
                            if (tiles[aLoc-1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc+offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()){
                                //build settlement
                               tiles[aLoc]->setSettOrCity(0);
                               //set name
                               tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                               players[x]->woodCount -= 1;
                               players[x]->brickCount -= 1; 
                               players[x]->grainCount -= 1;
                               players[x]->woolCount -= 1;
                               players[x]->victoryPoints++;
                            }
                            else {
                                cout<<"Can't build there..."<<endl;
                                goto strt;
                            }
                        //middle columns (first row)    
                        } else {
                            //checks left, right, below
                            if (tiles[aLoc-1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc+1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName() ||
                            tiles[aLoc+offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName())
                            {
                                //build settlement
                               tiles[aLoc]->setSettOrCity(0);
                               //set name
                               tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                               players[x]->woodCount -= 1;
                               players[x]->brickCount -= 1; 
                               players[x]->grainCount -= 1;
                               players[x]->woolCount -= 1;
                               players[x]->victoryPoints++;
                            }
                            else {
                                cout<<"Can't build there..."<<endl;
                                goto strt;
                            }
                            
                        }
                    //target in final row
                    } else if (rowInput == row){
                        if (colInput == 1){
                            //checks to the right and up if choice is max,1
                            if (tiles[aLoc+1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc-offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()){
                                //build settlement
                               tiles[aLoc]->setSettOrCity(0);
                               //set name
                               tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                               players[x]->woodCount -= 1;
                               players[x]->brickCount -= 1; 
                               players[x]->grainCount -= 1;
                               players[x]->woolCount -= 1;
                               players[x]->victoryPoints++;
                            }
                            else {
                                cout<<"Can't build there..."<<endl;
                                goto strt;
                            }
                        }
                        //if col selection all the way to the right
                        else if (colInput == col){
                            //checks to the left and up
                            if (tiles[aLoc-1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc-offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()){
                                //build settlement
                               tiles[aLoc]->setSettOrCity(0);
                               //set name
                               tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                               players[x]->woodCount -= 1;
                               players[x]->brickCount -= 1; 
                               players[x]->grainCount -= 1;
                               players[x]->woolCount -= 1;
                               players[x]->victoryPoints++;
                            }
                            else {
                                cout<<"Can't build there..."<<endl;
                                goto strt;
                            }
                        //middle columns (first row)    
                        } else {
                            //checks left, right, above
                            if (tiles[aLoc-1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc+1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName() ||
                            tiles[aLoc-offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName())
                            {
                                //build settlement
                               tiles[aLoc]->setSettOrCity(0);
                               //set name
                               tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                               players[x]->woodCount -= 1;
                               players[x]->brickCount -= 1; 
                               players[x]->grainCount -= 1;
                               players[x]->woolCount -= 1;
                               players[x]->victoryPoints++;
                            }
                            else {
                                cout<<"Can't build there..."<<endl;
                                goto strt;
                            }
                        }
                        
                    
                    //if target is in middle rows
                    } else if (rowInput < row && rowInput > 0){
                        //first col
                        if (colInput == 1){
                            //checks to the right, down and up if choice is max,1
                            if (tiles[aLoc+1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc-offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc+offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()) {
                                //build settlement
                               tiles[aLoc]->setSettOrCity(0);
                               //set name
                               tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                               players[x]->woodCount -= 1;
                               players[x]->brickCount -= 1; 
                               players[x]->grainCount -= 1;
                               players[x]->woolCount -= 1;
                               players[x]->victoryPoints++;
                            }
                            else {
                                cout<<"Can't build there..."<<endl;
                                goto strt;
                            }
                        }
                        //if col selection all the way to the right
                        else if (colInput == col){
                            //checks to the left, up and down
                            if (tiles[aLoc-1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc-offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName() ||
                            tiles[aLoc+offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()){
                                //build settlement
                               tiles[aLoc]->setSettOrCity(0);
                               //set name
                               tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                               players[x]->woodCount -= 1;
                               players[x]->brickCount -= 1; 
                               players[x]->grainCount -= 1;
                               players[x]->woolCount -= 1;
                               players[x]->victoryPoints++;
                            }
                            else {
                                cout<<"Can't build there..."<<endl;
                                goto strt;
                            }
                        //middle columns (first row)    
                        } else {
                            //checks left, right, above, below
                            if (tiles[aLoc-1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName()  ||
                            tiles[aLoc+1]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName() ||
                            tiles[aLoc-offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName() ||
                            tiles[aLoc+offset]->getPlayer() == players[gameManager.getCurrentPlayer()]->getName())
                            {
                                //build settlement
                               tiles[aLoc]->setSettOrCity(0);
                               //set name
                               tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                               players[x]->woodCount -= 1;
                               players[x]->brickCount -= 1; 
                               players[x]->grainCount -= 1;
                               players[x]->woolCount -= 1;
                               players[x]->victoryPoints++;
                            }
                            else {
                                cout<<"Can't build there..."<<endl;
                                goto strt;
                            }
                        }
                    }
                }
                else {
                    cout<<"You do not have enough resources to build a settlement."<<endl;
                    revert = true;
                    return;
                }
                    break;
            case 2:
                //Check resource requirements
                
                if (players[x]->oreCount > 1 && players[x]->grainCount > 2){ 
                
                    cout << "Where would you like to place a city? (You must own an a settlement on the requested tile)" << endl;
                    cout << "Enter desired row: ";
                    cin >> rowInput;
                    cout << "Enter desired column: ";
                    cin >> colInput;
                    
                    offset = col;
                    aLoc = ((rowInput-1)*col)+(colInput-1);
                    
                    if (rowInput > row || rowInput < 1 || colInput > col || colInput < 1){
                        cout<<"Location out of bounds, try again..."<<endl;
                        goto strt;
                        //checks to see if existing city/ sett in target
                    } else if (tiles[aLoc]->getSettOrCity() != 0){
                        cout<<"You can only build a city onto an existing settlement."<<endl;
                        revert = true;
                        return;
                    } else if (
                        (tiles[aLoc]->getSettOrCity() == 0) && (tiles[aLoc]->getPlayer() != players[x]->getName())
                        ||
                        (tiles[aLoc]->getSettOrCity() == 1)) {
                            cout<<"There is already a structure in that location, try again..."<<endl;
                            cout<<"You can only build a city onto an existing settlement."<<endl;
                            goto strt;
                    } else {
                         //build settlement
                        tiles[aLoc]->setSettOrCity(1);
                        //set name
                        tiles[aLoc]->setPlayer(players[gameManager.getCurrentPlayer()]->getName());
                        players[x]->oreCount -= 2;
                        players[x]->grainCount -= 3; 
                        players[x]->victoryPoints++;
                    }  
                        
                } else {
                    cout<<"You do not have enough resources to build a city."<<endl;
                    revert = true;
                    return;
                }
                break;
            case 3:
                if (players[x]->oreCount > 0 && players[x]->grainCount > 0 &&
                players[x]->woolCount > 0){
                    cout<<"in dev card area"<<endl;
                    int randDevCard = ((rand()%5));
                    //Library
                    cout<<"randDevCard: "<<randDevCard<<endl;
                    if (randDevCard == 0){
                        cout<<"You built a Library and gained 1 victory point!"<<endl;
                        players[x]->victoryPoints++;
                        players[x]->printVictoryPoints();
                    }
                    //University
                    if (randDevCard == 1){
                        cout<<"You built a University and gained 1 victory point!"<<endl;
                        players[x]->victoryPoints++;
                        players[x]->printVictoryPoints();
                    }
                    //Town Hall
                    if (randDevCard == 2){
                        cout<<"You built a Town Hall and gained 1 victory point!"<<endl;
                        players[x]->victoryPoints++;
                        players[x]->printVictoryPoints();
                    }
                    //Harvest Bounty
                    if (randDevCard == 3){
                        cout<<"You drew Harvest Bounty and gained 1 of each resource type!"<<endl;
                        players[x]->woodCount++;
                        players[x]->woolCount++;
                        players[x]->grainCount++;
                        players[x]->oreCount++;
                        players[x]->brickCount++;
                        players[x]->printResources();
                    }
                    //Knight
                    if (randDevCard == 4){
                        int playerChoice;
                        int randRes = rand()%5;
                        cout<<"You drew Knight and May now steal a random resource from a player of your choice!"<<endl;
                        cout<<"Who would you like to steal from? "<<endl;
                        for (int i = 0; i<players.size(); i++){
                            cout<<i<<": "<<players[i]->getName()<<" "<<endl;
                        }
                        cin>>playerChoice;
                        //Wood
                        if (randRes == 0){
                            players[playerChoice]->woodCount--;
                            players[x]->woodCount++;
                            cout<<"You stole 1 wood from "<<players[playerChoice]->getName()<<"!"<<endl;
                        }
                        //Bricks
                        if (randRes == 1){
                            players[playerChoice]->brickCount--;
                            players[x]->brickCount++;
                            cout<<"You stole 1 brick from "<<players[playerChoice]->getName()<<"!"<<endl;
                        }
                        //Grain
                        if (randRes == 2){
                            players[playerChoice]->grainCount--;
                            players[x]->grainCount++;
                            cout<<"You stole 1 grain from "<<players[playerChoice]->getName()<<"!"<<endl;
                        }
                        //Wool
                        if (randRes == 3){
                            players[playerChoice]->woolCount--;
                            players[x]->woolCount++;
                            cout<<"You stole 1 wool from "<<players[playerChoice]->getName()<<"!"<<endl;
                        }
                        //Ore
                        if (randRes == 4){
                            players[playerChoice]->oreCount--;
                            players[x]->oreCount++;
                            cout<<"You stole 1 ore from "<<players[playerChoice]->getName()<<"!"<<endl;
                        }
                        players[x]->printResources();
                    }
                }
                // Check resource requirements
                // cout << "You have drawn a " << developmentCard[topPosition].cardName << ". It does " << (effect based on card) << "." << endl;
                // If card is a Knight, choose who to steal resources from.
                else {
                    cout<< "You can not afford a development card!"<<endl;
                    revert = true;
                    return;
                }
                
                break;
            case 4:
                revert = true;
                return;
            default:
                revert = true;
                return;
        }
    }
    else if (playerDecision == 2) {
        cout << "Which Resource would you like to trade in? (You need 3 of one resource to trade for 1 of another)" << endl;
        cout << "1: Wood, 2: Bricks, 3: Grain, 4: Wool, 5: Ore, or 6: Quit trading" << endl;
        cin >> playerDecision;
        switch (playerDecision) {
            case 1:
                if (players[x]->woodCount >= 3) {
                    players[x]->woodCount = players[x]->woodCount - 3;
                }
                else {
                    cout << "You do not have enough of this resource." << endl;
                    revert = true;
                    return;
                }
                break;
            case 2:
                if (players[x]->brickCount >= 3) {
                    players[x]->brickCount = players[x]->brickCount - 3;
                }
                else {
                    cout << "You do not have enough of this resource." << endl;
                    revert = true;
                    return;
                }
                break;
            case 3:
                if (players[x]->grainCount >= 3) {
                    players[x]->grainCount = players[x]->grainCount - 3;
                }
                else {
                    cout << "You do not have enough of this resource." << endl;
                    revert = true;
                    return;
                }
                break;
            case 4:
                if (players[x]->woolCount >= 3) {
                    players[x]->woolCount = players[x]->woolCount - 3;
                }
                else {
                    cout << "You do not have enough of this resource." << endl;
                    revert = true;
                    return;
                }
                break;
            case 5:
                if (players[x]->oreCount >= 3) {
                    players[x]->oreCount = players[x]->oreCount - 3;
                }
                else {
                    cout << "You do not have enough of this resource." << endl;
                    revert = true;
                    return;
                }
                break;
            case 6:
                revert = true;
                return;
            default:
                cout << "Invalid response" << endl;
                revert = true;
                return;
        }
        cout << "Which resource would you like to receive?" <<endl;
        cout << "1: Wood, 2: Bricks, 3: Grain, 4: Wool, or 5: Ore" << endl;
        cin >> playerDecision;
        switch (playerDecision) {
            case 1:
                players[x]->woodCount++;
                break;
            case 2:
                players[x]->brickCount++;
                break;
            case 3:
                players[x]->grainCount++;
                break;
            case 4:
                players[x]->woolCount++;
                break;
            case 5:
                players[x]->oreCount++;
                break;
            default:
                cout << "Invalid response. Your resources have been lost." << endl;
                revert = true;
                return;
        }
        revert = true;
        return;
    }
    else if (playerDecision == 3){
        cout << "You have chosen to end your turn" << endl << endl;
    }
    else {
        cout<< "Invalid Response"<<endl;
        revert = true;
        return;
    }
    gameManager.nextTurn();
}

int main() {
    srand(time(0));
    vector<Tile*> tiles;
    
    int row;
    int col;
    cout<<"How many rows do you want on your game board?"<<endl;
    cin>>row;
    cout<<"How many columns do you want on your game board?"<<endl;
    cin>>col;
    
    
    int totalPlayerCount;
    
    cout << "Hi! Welcome to Settlers of Catan++" <<endl;
    cout << "Please enter the number of people playing: (2-6) " <<endl;
    cin >> totalPlayerCount;
    
    int randSetLoc[totalPlayerCount];
    
    //makes an array with locations of first random settlements for each player
    for (int i = 0; i<totalPlayerCount; i++){
        cnt:
        int temp = rand() % (row*col);
        for (int j = 0; j<i; j++){
            if (randSetLoc[j] == temp){
                goto cnt;
            }
        }
        randSetLoc[i] = temp;
    }
    
    GameManager gameManager(totalPlayerCount);
    
    vector<Player*> players;
    for (int i = 0; i < totalPlayerCount; i++) {
        string tempName;
        cout << "Enter a name for player " << i+1 << ": ";
        cin >> tempName;
        players.push_back(new Player(tempName));
    }
    
    
    
    
    
    buildBoard(tiles, row, col);
    cout<<"Number of tiles: "<<tiles.size()<<endl;
    
    
    for (int i = 0; i<totalPlayerCount;i++){
        tiles[randSetLoc[i]]->setSettOrCity(0);
        tiles[randSetLoc[i]]->setPlayer(players[i]->getName());
        
        cout<<"Player "<<players[i]->getName()<<
        " Has a settlement at location "<< floorf(randSetLoc[i]/col)+1 <<", "<<(randSetLoc[i]%col)+1<<endl;
        
        // tiles[((rowInput-1)*col)+(colInput-1)]->getSettOrCity()
    }
    
    
    //cout<<tiles[0]->getLand() <<endl;
    
    //setPlayerStart(players, tiles, row, col);
    revert = false;
    while (victory == false) {
        takeTurn(gameManager, players, tiles, row, col);
        for (int i = 0; i < totalPlayerCount; i++){
            if (players[i]->victoryPoints >= 10){
                victory = true;
                winner = players[i]->getName();
            }
        }
    }

    cout<<"Congradualtions "<<winner<<", you won the game!  You are the king of Catan!"<<endl;


    return 0;
}

//g++ Main.cpp GameBoard.cpp Player.cpp Tile.cpp GameManager.cpp -o test -std=c++11


