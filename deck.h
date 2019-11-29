#pragma once
#include <cstdlib>
#include "card.h"
#include <time.h>

class Deck{
    public:
        Card cardList[52];
    Deck(){
        for (int i = 0; i < 13; i++){
            cardList[i].getSuite(0);
            cardList[i].getNumber(i+1);
            if (i <= 10){
                cardList[i].value = i;
            } else if( i > 10){
                cardList[i].value = 10;
            }
        }
        for (int i = 0; i < 13; i++){
            cardList[i+13].getSuite(1);
            cardList[i+13].getNumber(i+1);
            if (i <= 10){
                cardList[i+13].value = i;
            } else if( i > 10){
                cardList[i+13].value = 10;
            }
        }
        for (int i = 0; i < 13; i++){
            cardList[i+26].getSuite(2);
            cardList[i+26].getNumber(i+1);
            if (i <= 10){
                cardList[i+26].value = i;
            } else if( i > 10){
                cardList[i+26].value = 10;
            }
        }
        for (int i = 0; i < 13; i++){
            cardList[i+39].getSuite(3);
            cardList[i+39].getNumber(i+1);
            if (i <= 10){
                cardList[i+39].value = i;
            } else if( i > 10){
                cardList[i+39].value = 10;
            }
        }
    };
    void newDeck(){
        for (int i = 0; i < 13; i++){
            cardList[i].getSuite(0);
            cardList[i].getNumber(i+1);
            if (i <= 10){
                cardList[i].value = i;
            } else if( i > 10){
                cardList[i].value = 10;
            }
        }
        for (int i = 0; i < 13; i++){
            cardList[i+13].getSuite(1);
            cardList[i+13].getNumber(i+1);
            if (i <= 10){
                cardList[i+13].value = i;
            } else if( i > 10){
                cardList[i+13].value = 10;
            }
        }
        for (int i = 0; i < 13; i++){
            cardList[i+26].getSuite(2);
            cardList[i+26].getNumber(i+1);
            if (i <= 10){
                cardList[i+26].value = i;
            } else if( i > 10){
                cardList[i+26].value = 10;
            }
        }
        for (int i = 0; i < 13; i++){
            cardList[i+39].getSuite(3);
            cardList[i+39].getNumber(i+1);
            if (i <= 10){
                cardList[i+39].value = i;
            } else if( i > 10){
                cardList[i+39].value = 10;
            }
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
        cout << "done shuffling";
    };
};