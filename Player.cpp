#include "Player.h"

Player::Player() {
    name = "No Name";
    victoryPoints = 1;
    woodCount = 1;
    brickCount = 1;
    grainCount = 1;
    woolCount = 1;
    oreCount = 1;
}

Player::Player(string chosenName) {
    name = chosenName;
    victoryPoints = 1;
    woodCount = 9;
    brickCount = 9;
    grainCount = 9;
    woolCount = 9;
    oreCount = 9;
}

string Player::getName() {
    return name;
}

void Player::printResources() {
    cout << "Resource Total:" << endl;
    cout << "Wood (" << woodCount << "), ";
    cout << "Brick (" << brickCount << "), ";
    cout << "Grain (" << grainCount << "), ";
    cout << "Wool (" << woolCount << "), ";
    cout << "Ore (" << oreCount << "). " << endl;
}

void Player::printVictoryPoints() {
    cout << "Victory Points: "<< victoryPoints << endl;
}