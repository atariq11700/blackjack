#pragma once
#include "deck.h"

class Blackjack{
    public:
        int players;
        bool dealer;
    Blackjack(int x,bool y){
        players = x;
        dealer = y;
        newGame(players,dealer);
    };
    void newGame(int num_of_players, bool is_there_dealer){
        
    }
};