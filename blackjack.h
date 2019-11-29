#pragma once
#include "deck.h"
#include <vector>

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
        //newGame(players,dealer);
    };
    //void newGame(int num_of_players, bool is_there_dealer){
        
    //};
    void deal(int players){
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