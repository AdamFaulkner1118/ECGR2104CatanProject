#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Player.h"

class GameManager {
    private:
    int totalPlayers;
    int currentPlayer;
    int choiceIndex;
    
    public:
    GameManager(int); //Constructor, int totalPlayers
    void nextTurn();
    int getCurrentPlayer();
    //void buyDevelopmentCard(/*Passed player class info*/); //Should check resource totals.
    void updateResourcesPost(int /*Scanario (settlement, city, dev cards)*/); // Updates resources after the player's action.
    void updateResourcesCheck(int /*dice roll*/); // Should compare dice roll with the numbers associated with owned land plots, determining to give resources or not.
};

class DevelopmentCards {
    private:
    string cardName;
    int cardID;
    
    public:
    string cardType(); // Rand (stored in card effect) determines card type in switch case, returning name.
    string render(int); // Built similar to UNO rendering.
    void cardFunction(int); // Does what is required based on the card drawn.
    void cardCaseKnight(); // Steals random resource from selected player.
};

#endif