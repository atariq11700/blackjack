#pragma once
#include <iostream>
using namespace std;
class Card{
    private:
        string ranks[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        string suites[4] = {"Hearts","Spades","Clubs","Diamonds"};
    public:
        string suite;
        string number;
        int value;
        int cardValue;
    Card(int x){
        value = x;
        suite = suites[x / 13];
        number = ranks[ x % 13];
    };
    Card(){
        suite = "defaultSuite";
        number = "defaultNumber";
        value = 0;
    };
    string getSuite(){
        return suite;
    };
    string getNumber(){
        return number;
    };
    int getValue(){
        return value;
    };
    int getCardValue(){
        return value % 13 + 1;
    };
    void printCard(){
        cout << number << " of " << suite << endl;
    };
};