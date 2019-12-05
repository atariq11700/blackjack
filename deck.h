#pragma once
#include <cstdlib>
#include "card.h"
#include <time.h>
#include <vector>

class Deck{
    public:
         vector <Card> cardList;
    Deck(){
        for (int i = 0; i < 52; i++)
        {
            cardList.push_back(Card(i));
        }
    };
    void printDeck(){
        for (int i = 0; i < 52; i++){
            cout << "Card number "<< i+1 << " is " << cardList[i].getNumber() << " of " << cardList[i].getSuite() << endl;
        }
        
    };
    void shuffleDeck(){
        Card tempCard;
        srand(time(0));
        for (int i = 0; i < 52; i++){
            int randIndex =  rand() % 52;
            tempCard.number = cardList[randIndex].number;
            tempCard.suite = cardList[randIndex].suite;
            tempCard.value = cardList[randIndex].value;
            cardList[randIndex].number = cardList[i].number;
            cardList[randIndex].suite = cardList[i].suite;
            cardList[randIndex].value = cardList[i].value;
            cardList[i].number = tempCard.number;
            cardList[i].suite = tempCard.suite;
            cardList[i].value = tempCard.value;
        }
        srand(time(0));
        for (int i = 0; i < 52; i++){
            int randIndex = rand() % 52;
            tempCard.number = cardList[i].number;
            tempCard.suite = cardList[i].suite;
            tempCard.value = cardList[i].value;
            cardList[i].number = cardList[randIndex].number;
            cardList[i].suite = cardList[randIndex].suite;
            cardList[i].value = cardList[randIndex].value;
            cardList[randIndex].number = tempCard.number;
            cardList[randIndex].suite = tempCard.suite;
            cardList[randIndex].value = tempCard.value;
        }
    };
};