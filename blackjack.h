#pragma once
#include "deck.h"

class Blackjack{
    public:
        int players;
        bool dealer;
        vector <vector <Card> > playerHands;
        vector <int> playerBalance;
        Deck blackjackDeck;
    Blackjack(int x){
        players = x;
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
    };
        
    void printHands(){
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
    void beginGame(){
        bool done = false;
        int dealer = players;
        while (not done)
        {
            vector <int> bets;
            vector <int> playersBusted;
            //set player balances
            for (int i = 0; i < players; i++)
            {
                playerBalance.push_back(100);
            }
            //deal out the cards to the players
            deal(players);
            // collect bets from the players
            for (int i = 0; i < players; i++)
            {
                cout << "Player " << i+1 << " your balance is " << playerBalance[i] << " dollars" << endl;
                cout << "Enter your bet: ";
                int tempBet;
                cin >> tempBet;
                bets.push_back(tempBet);
            }
             cout << "The dealers second card is the " << playerHands[dealer][1].number << " of " << playerHands[dealer][1].suite << endl;
             for (int i = 0; i < players; i++)
             {
                 cout << "Player " << i+1 << " you have cards: "<<endl;
                 cout << playerHands[i][0].number << " of " << playerHands[dealer][0].suite << endl;
                 cout << playerHands[i][1].number << " of " << playerHands[dealer][1].suite << endl;
                 bool playerDone = false;
                 while (not playerDone)
                 {
                    int tempChoice = 0;
                    cout << "1) Hit" << endl;
                    cout << "2) Hold" << endl;
                    cin >> tempChoice;
                    if (tempChoice == 1)
                    {
                        
                    }else if (tempChoice == 2)
                    {
                        
                    }
                }
            }
        }        
    };
};