// Arnav Patri
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
int main(){
  srand(time(0));
  string cards[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
  string suites[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
  string pn[2] = {"one", "two"};
  int players[2][2];
    int cases[4][2][2] = {
      {
        {2, 1}, {7, 0}
      },
      {
        {12, 0}, {2, 1}
      },
      {
        {2, 2}, {9, 3}
      },
      {
        {9, 1}, {10, 3}
      }
    };
  for (int a = 0; a < 4; a++){
    for (int b = 0; b < 2; b++){
      players[b][0] = cases[a][b][0];
      players[b][1] = cases[a][b][1];
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
    cout << endl << endl;
  }
}
