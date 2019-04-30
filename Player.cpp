#include "Player.h"

Player::Player() {
    playerName = "Null";
}

Player::Player(string name) {
    playerName = name;
}

string Player::getName() {
    return playerName;
}