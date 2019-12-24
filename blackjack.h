#pragma once
#include "deck.h"
#include "windows.h"

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
            blackjackDeck = Deck();
            playerHands.clear();
            vector <int> bets;
            vector <bool> playersBusted;
            playersBusted.resize(players);
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
            //loop through all the players and ask to hit or hold
            for (int i = 0; i < players; i++)
            {
                bool playerDone = false;
                while (not playerDone)
                {
                    cout << "Player " << i+1 << " you have the cards:" << endl;
                    for (int h = 0; h < playerHands[i].size(); h++)
                    {
                        playerHands[i][h].printCard();
                    }
                    int tempChoice = 0;
                    cout << "1) Hit" << endl;
                    cout << "2) Hold" << endl;
                    cin >> tempChoice;
                    if (tempChoice == 1)
                    {
                        Card tempCard = blackjackDeck.deal();
                        cout << "Player " << i+1 << " is dealt a ";
                        tempCard.printCard();
                        playerHands[i].push_back(tempCard);
                        int tempSum = 0;
                        for (int y = 0; y < playerHands[i].size(); y++)
                        {
                            tempSum += playerHands[i][y].getCardValue();
                        }
                        //check to see if bust
                        if (tempSum > 21){
                            Sleep(1000);
                            cout << "Player Busts!!!" << endl;
                            playersBusted[i] = true;
                            break;
                        }
                    }else if (tempChoice == 2)
                    {
                        cout << "Player " << i+1 << " holds" << endl;
                        playerDone = true;
                    }
                    Sleep(1500);
                }
            }
            Sleep(1000);
            //dealer turn
            cout << "The dealer has the cards: " << endl;
            playerHands[dealer][0].printCard();
            playerHands[dealer][1].printCard();
            //dealer draws
            bool dealerDone = false;
            bool dealerBust = false;
            int dealerValue;
            while (not dealerDone)
            {
                dealerValue = 0;
                for (int z = 0; z < playerHands[dealer].size(); z++)
                {
                    dealerValue += playerHands[dealer][z].getCardValue();
                }
                if (dealerValue < 17){
                    Card tempCard = blackjackDeck.deal();
                    cout << "Dealer draws a ";
                    tempCard.printCard();
                    playerHands[dealer].push_back(tempCard);
                    Sleep(1500);
                }else if(dealerValue > 21){
                    cout << "Dealer busts" << endl;
                    dealerBust = true;
                    Sleep(1500);
                    break;
                }else if(dealerValue >= 17){
                    cout << "Dealer holds" << endl;
                    dealerDone = true;
                    Sleep(1500);
                }
            }
            //payout
            if(dealerBust){
                for (int z = 0; z < players; z++)
                {
                    if(not playersBusted[z]){
                        cout << "Player" << z+1 << " wins " << bets[z] << " dollars " << endl;
                        playerBalance[z] += bets[z];
                    }else{
                        cout << "Player " << z+1 << "busts and wins nothing" <<endl;
                    }
                }
            }else{
                for (int i = 0; i < players; i++)
                {
                    if(playersBusted[i]){
                        cout << "Player " << i+1 << " busted and loses " << bets[i] << " dollars" << endl;
                        playerBalance[i] -= bets[i];
                    }else{
                        int playerValue;
                        for (int f = 0; f < playerHands[i].size(); f++)
                        {
                            playerValue += playerHands[i][f].getCardValue();
                        }
                        if(playerValue > dealerValue){
                            cout << "Player " << i+1 << " wins " << bets[i] << " dollars " << endl;
                            playerBalance[i] += bets[i];
                        }else if(dealerValue == playerValue){
                            cout << "Player " << i+1 << " ties with the dealer and neither wins nor loses money" << endl;
                        }else if(dealerValue > playerValue){
                            cout << "Player " << i+1 << " loses " << bets[i] << " dollars" << endl;
                            playerBalance[i] -= bets[i];
                        }
                    }
                }
            }
            cout << "Play again?" << endl;;
            string playAgain;
            cin >> playAgain;
            if(playAgain == "n"){
                done = true;
                cout << "Thanks for playing" << endl;
            }
        }        
    };
};