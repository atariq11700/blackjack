#pragma once
#include "deck.h"

class Blackjack{
    public:
        int players;
        bool dealer;
        vector <vector <Card> > playerHands;
        Deck blackjackDeck;
    Blackjack(int x,bool y){
        players = x;
        dealer = y;
        deal(players);
    };
    void deal(int players){
        blackjackDeck.shuffleDeck();
        //initalize vector
        playerHands.resize(players + 1);
        for (int i = 0; i < (players+1); i++)
        {
            for (int y = 0; y < 2; y++)
            {
                playerHands[i].push_back(Card(blackjackDeck.cardList[2*i+y].getValue()));
            }
            
        }
        for (int i = 0; i < (players +1); i++)
        {
            cout << "Player " << i <<" has cards:" <<endl;
            cout << "Card one: " << playerHands[i][0].number << " of " << playerHands[i][0].suite <<endl;
            cout << "Card two: " << playerHands[i][1].number << " of " << playerHands[i][1].suite <<endl<<endl;
        }
        for (int i = 0; i < (players+1); i++){
            playerHands[i][0].number = blackjackDeck.cardList[i+1].number;
            playerHands[i][0].suite = blackjackDeck.cardList[i+1].suite;
            playerHands[i][0].value = blackjackDeck.cardList[i+1].value;
            playerHands[i][1].number = blackjackDeck.cardList[(players + 1)*i + 1].number;
            playerHands[i][1].suite = blackjackDeck.cardList[(players + 1)*i + 1].suite;
            playerHands[i][1].value = blackjackDeck.cardList[(players + 1)*i + 1].value;
        }
        
    };

    void printHands(){
        for (int i = 0; i < (players + 1); i++){
            cout << "Player " << i << " has cards " << playerHands[i][0].number << " of " << playerHands[i][0].suite << " and " << playerHands[i][1].number << " of " << playerHands[i][1].suite << endl; 
        }
        
    };
};