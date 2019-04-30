for bordgame.h

#include <iostream>
#include <sstream>
#include <string>
//#include "tile.h"

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
    

    virtual string render(int); 
   
};

class Tile : public GameBoard{
    public:
    Tile(LandType, ResourcesType, int, string);
    string render(int);
};

#endif