#pragma once
#include <iostream>
using namespace std;
class Card{
    public:
        string suite;
        string number;
        int value;
    Card(int x,int y,int z){
        getSuite(x);
        getNumber(y);
        value = z;
    };
    Card(){
        suite = "";
        number = "";
        value = 0;
    };
    void getSuite(int x){
        if (x == 0){
            suite =  "hearts";
        } else if (x == 1){
            suite = "diamonds";  
        } else if (x == 2){
            suite = "spades";
        } else if (x == 3){
            suite = "clubs";
        }
    };
    string getSuite(){
        return suite;
    };
    string getNumber(){
        return number;
    };
    void getNumber(int x){
        switch(x){
            case 1:
                number = "Ace";
                break;
            case 2:
                number = "Two";
                break;
            case 3:
                number = "Three";
                break;
            case 4:
                number = "Four";
                break;
            case 5:
                number = "Five";
                break;
            case 6:
                number = "Six";
                break;
            case 7:
                number = "Seven";
                break;
            case 8:
                number = "Eight";
                break;
            case 9:
                number = "Nine";
                break;
            case 10:
                number = "Ten";
                break;
            case 11:
                number = "Jack";
                break;
            case 12:
                number = "Queen";
                break;
            case 13:
                number = "King";
                break;
        
        }
    };
    int getValue(){
        return value;
    };
};