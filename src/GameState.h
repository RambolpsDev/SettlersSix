#pragma once

#include "Card.h"
#include "ResourceCard.h"
#include "DevelopmentCard.h"
#include "LongestRoadCard.h"
#include "LargestArmyCard.h"
#include "Skyscraper.h"
#include "House.h"
#include "Road.h"
#include "Thief.h"

class GameState {

    ResourceCard resourceCards[95];
    DevelopmentCard developmentCards[25];
    LongestRoadCard longestRoadCard;
    LargestArmyCard largestArmyCard;


    Skyscraper skyscrapers[16];

    House houses[20];
    Road roads[60];

    Thief thief;

    int playerTurn = 0;
};


