#include "GameManager.h"

GameManager::GameManager(int numPlayers){
    this->totalPlayers = numPlayers;
    this->currentPlayer = 0;
}

int GameManager::getCurrentPlayer() {
    return currentPlayer;
}

void GameManager::nextTurn() {
    currentPlayer++;
    if (currentPlayer == totalPlayers) {
        currentPlayer = 0;
    }
}
