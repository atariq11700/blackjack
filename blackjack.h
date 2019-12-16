#pragma once
#include "deck.h"

class Blackjack{
    public:
        int players;
        bool dealer;
        vector <vector <Card> > playerHands;
        vector <int> playerBalance;
        vector <int> cardsAvalible;
        Deck blackjackDeck;
    Blackjack(int x){
        players = x;
        for (int i = 0; i < 52; i++)
        {
            cardsAvalible.push_back(i);
        }
        
    };
    void deal(int players){
        bool not_in_deck = true;
        srand(time(0));
        blackjackDeck.shuffleDeck();
        //initalize vector
        playerHands.resize(players + 1);
        for (int i = 0; i < (players+1); i++)
        {
            for (int y = 0; y < 2; y++)
            {   
                int temp_card_index = rand() % 52;
                while (true)
                {
                    for (int x = 0; x < 52; x++)
                    {
                        if (cardsAvalible[x] == temp_card_index)
                        {
                            not_in_deck = false;
                            cardsAvalible.erase(cardsAvalible.begin() + x);
                            break;
                        }else
                        {
                            temp_card_index = rand() % 52;
                        }
                    }
                    if (not not_in_deck)
                    {
                        break;
                    }
                }
                playerHands[i].push_back(Card(temp_card_index));
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
                bool playerDone = false;
                while (not playerDone)
                {
                    cout << "Player " << i+1 << " you have the cards:" << endl;
                    for (int h = 0; h < playerHands[i].size(); h++)
                    {
                        cout << playerHands[i][h].number << " of " << playerHands[i][h].suite << endl;
                    }
                    int tempChoice = 0;
                    cout << "1) Hit" << endl;
                    cout << "2) Hold" << endl;
                    cin >> tempChoice;
                    if (tempChoice == 1)
                    {
                        bool not_in_deck = true;
                        int temp_card_index = rand() % 52;
                        while (true);
                        {
                            for (int x = 0; x < 52; x++)
                            {
                                if (cardsAvalible[x] == temp_card_index)
                                {
                                    not_in_deck = false;
                                    cardsAvalible.erase(cardsAvalible.begin() + x);
                                    break;
                                }else
                                {
                                    temp_card_index = rand() % 52;
                                }
                            }
                            if (not not_in_deck)
                            {
                                break;
                            }
                        }
                        playerHands[i].push_back(Card(temp_card_index));
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