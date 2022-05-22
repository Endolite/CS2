// Arnav Patri
#include <iostream>

using namespace std;

int main(){
  int n;
  cout << "Enter a number between -5 and 5 excluding -1, 0, and 1" << endl;
    cin >> n;
  while ((n >= -1 && n <= 1) || (n < -5) || (n > 5)){
      cout << "Invalid number. Enter again:" << endl;
      cin >> n;
  }
  if (n < 0){
    n *= -1;
    for (int i = n; i > 0; i--){
      for (int j = 0; j < n - i; j++){
        cout << " ";
      }
      for (int j = 0; j < i; j++){
        cout << "*";
      }
      cout << endl;
    }
  }
  else{
    for(int i = 0; i < n; i++){
      for (int j = 0; j <= i; j++){
        cout << "*";
      }
      cout << endl;
    }
  }
}