#include "GameBoard.h"

void GameBoard::setLand(LandType L){
    land = L;
}
void GameBoard::setResource(ResourcesType R){
    resources = R;
}
void GameBoard::setNumber(int n){
    num = n;
}

void GameBoard::setPlayer(string pname){
    name=pname;
}

LandType GameBoard::getLand(){
    return land;
}

ResourcesType GameBoard::getResource(){
    return resources;
}
int GameBoard::getNumber(){
    return num;
}

string GameBoard::getPlayer(){
    return name;
}


string GameBoard::render(int line){
    stringstream ss;
    switch(line){
        case 0: return " ------------- ";
        case 1: return "|             |";
        case 2: return "|             |";
        case 3: return "|             |";
        case 4: return "|             |";
        case 5: return "|             |";
        case 6: return "|             |";
        case 7: return " ------------- ";
        default:
            return " ";
    }
}

Tile::Tile(LandType L, ResourcesType R, int n, string pname){
    setLand(L);
    setResource(R);
    setNumber(n);
    setPlayer(pname);
}

string Tile::render(int line){
    stringstream ss;
    switch(line){
        case 0: return " ------------- ";
        case 1: 
            switch(land){
            case FOREST:
                return "|Forest       |";
                break;
            case HILLS:
                return "|Hills        |";
                break;
            case FIELD:
                return "|Field        |";
                break;
            case PASTURE:
                return "|Pasture      |";
                break;
            case MOUNTAIN:
                return "|Mountain     |";
                break;
            default:
                return "|             |";
                break;
            break;
            }
        case 2:
            if(num<=9){
            ss <<  "|            "<<num<<"|";
            return ss.str();
            break;
            }
            if(num>9){
            ss <<  "|           "<<num<<"|";
            return ss.str();
            break;
            }
                
        case 3: return "|             |";
        case 4: return "|             |";
        case 5: return "|             |";
        case 6: return "|             |";
        case 7: return " ------------- ";
        default:
            return " ";
    } 
}