// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
int main(){
  srand(time(NULL));
  string cards[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
  string suites[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
  string pn[2] = {"one", "two"};
  int players[2][2];
  do {
    for (int i = 0; i < 2; i++){
      players[i][0] = rand() % 13;
      players[i][1] = rand() % 4;
    }
    while ((players[0][0] == players[1][0]) && (players[0][1] == players[1][1])){
      players[1][0] = rand() % 13;
      players[1][1] = rand() % 4;
    }
    for (int i = 0; i < 2; i++){
      cout << "Player " + pn[i] + " card is " + cards[players[i][0]] + " " +  suites[players[i][1]] + "!" << endl;
    }
    string c1 = "Player One Wins!";
    string c2 = "Player Two Wins!";
    string c3 = "It's a Draw!";
    if (players[0][1] == 1){
      if (players[1][1] == 1){
        if (players[0][0] < players[1][0]){
          cout << c2;
        }
        else{
          cout << c1;
        }
      }
      else{
        cout << c1;
      }
    }
    else if (players[1][1] == 1){
      cout << c2;
    }
    else if (players[0][0] == players[1][0]){
      cout << c3;
    }
    else if (players[0][0] < players[1][0]){
      cout << c2;
    }
    else{
      cout << c1;
    }
    cout << endl << "Press any key to continue... ";
    cin.get();
  } while (cin.get() != '\n');
  return 0;
}
