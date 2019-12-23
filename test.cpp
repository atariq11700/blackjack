#include "blackjack.h"
#include <time.h>


int main(){
  cout << "Welcome to blackjack!! Please enter the numbers of players who want to play." << endl;
  int numOfPLayers;
  cin >> numOfPLayers;
  Blackjack gameOfBlackjack(numOfPLayers);
  gameOfBlackjack.beginGame();      
}