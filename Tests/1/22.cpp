/*
Build a program that does the following instructions:
  - Generates a random integer between 1 and 5 without showing it to the user
  - Displays to the user if the generated integer is an odd or an even number
  - Asks the user to guess a number
  - Reads the user’s guess
  - Displays if the entered number was less than or greater than the generated integer
  - Once the user guesses the number, then display a congratulations message.
*/

#include <iostream>

using namespace std;

int main(){
  srand(time(NULL));
  int n = (rand() % 5) + 1;
  int guess;
  if (n % 2 == 0){
    cout << "The number is even.";
  }
  else {
    cout << "The number is odd.";
  }
  cout << endl << "Guess: ";
  do {
    cin >> guess;
    if (guess != n){
      if (guess > n){
        cout << "Too high! ";
      }
      else {
        cout << "Too low! ";
      }
      cout << "Try again: ";
    }
  } while (guess != n);
  cout << "Congratulations! Your guess is correct." << endl;
  return 0;
}
