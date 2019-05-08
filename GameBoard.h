#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

enum LandType{FOREST, HILLS, FIELD, PASTURE, MOUNTAIN};
enum ResourcesType{WOOD, BIRCKS, GRAIN, WOOL, ORE};

class GameBoard{
    protected:
    //describes type of land
    LandType land;
    //describes type of resource
    ResourcesType resources;
    //describe number associated
    int num;
    string name;
    //Choice of settlement or city
    int choice;
    
    
    public:
    void setLand(LandType);
    void setResource(ResourcesType);
    void setNumber(int);
    LandType getLand();
    ResourcesType getResource();
    int getNumber();
    //Need to set player
    void setPlayer(string);
    string getPlayer();
    //Need to set if its a settlement or city
    void setSettOrCity(int);
    int getSettOrCity();
    int nameNum;

    virtual string render(int);
    
    int getChoice();
   
};

class Tile : public GameBoard{
    public:
    Tile(LandType, ResourcesType, int, string, int);
    string render(int);
};

#endif