// Arnav Patri
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
int main(){
  srand(time(0));
  string cards[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
  string suites[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
  string players[2][3];
    players[0][0] = "one";
    players[1][0] = "two";
    for (int i = 0; i < 2; i++){
      players[i][1] = cards[rand() % 13];
      players[i][2] = suites[rand() % 4];
    }
  for (int i = 0; i < 2; i++){
    cout << "Player " + players[i][0] + " card is " + players[i][1] + " " +  players[i][2] + "!" << endl;
  }
  string c1 = "Player One Wins!";
  string c2 = "Player Two Wins!";
  string c3 = "It's a Draw!";
  if (players[0][2] == players[1][2]){
    if (players[0][1] == players[1][1]){
      cout << c3;
    }
    else if (stoi(players[0][1]) > stoi(players[1][1])){
      cout << c1;
    }
    else{
      cout << c2;
    }
  }
  else if (players[0][0] == "Hearts"){
    cout << c1;
  }
  else if (players[0][0] == "Hearts"){
    cout << c2;
  }
  else if (stoi(players[0][1]) < stoi(players[1][1])){
    cout << c2;
  }
  else{
    cout << c1;
  }
  if (players[0][2] == "Hearts"){
    if (players[2][2] == "Hearts"){
      
    }
    else cout << c1;
  }
  else if (players[2][2] == "Hearts"){
    cout << c2;
  }