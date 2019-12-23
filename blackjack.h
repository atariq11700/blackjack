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
        for (int d = 0; d < 2; d++)
        {
            for (int i = 0; i < players+1; i++)
            {
                playerHands[i].push_back(blackjackDeck.deal());
            }
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
            cout << "The dealers second card is the ";
            playerHands[dealer][1].printCard();
            for (int i = 0; i < players; i++)
            {
                bool playerDone = false;
                while (not playerDone)
                {
                    cout << "Player " << i+1 << " you have the cards:" << endl;
                    int tempval = 0;
                    for (int h = 0; h < playerHands[i].size(); h++)
                    {
                        playerHands[i][h].printCard();
                        tempval += playerHands[i][h].getCardValue();
                    }
                    cout << tempval << endl;
                    int tempChoice = 0;
                    cout << "1) Hit" << endl;
                    cout << "2) Hold" << endl;
                    cin >> tempChoice;
                    if (tempChoice == 1)
                    {
                        playerHands[i].push_back(blackjackDeck.deal());
                        int tempSum = 0;
                        for (int y = 0; y < playerHands[i].size(); y++)
                        {
                            tempSum += playerHands[i][y].getCardValue();
                        }
                        if (tempSum > 21){
                            cout << "Player Busts!!!" << endl;
                            playersBusted.push_back(i);
                            break;
                        }
                    }else if (tempChoice == 2)
                    {
                        cout << "Player " << i+1 << " holds" << endl;
                        playerDone = true;
                    }
                }
            }
            cout << "The dealer has the cards: " << endl;
            cout << playerHands[dealer][0].number << " of " << playerHands[dealer][0].suite << endl;
            cout << playerHands[dealer][1].number << " of " << playerHands[dealer][1].suite << endl;            
            break;
        }        
    };
};