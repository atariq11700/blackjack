#include "blackjack.h"
#include <time.h>

int main(){
    Blackjack newBlackjackGame(5,false);
    newBlackjackGame.blackjackDeck.printDeck();
    newBlackjackGame.printHands();
}