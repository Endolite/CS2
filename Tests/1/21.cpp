/*
Build a program that does the following instructions:

- Takes two integers from the user
- Displays the inclusive range of values between the two integers in an ascending order

Example:

If the user enters 10 and 5, the output is:

5, 6, 7, 8, 9, 10
*/

#include <iostream>

using namespace std;

int main(){
  int min;
  int max;
  cout << "Enter two integers: ";
  cin >> min >> max;
  if (min > max){
    int temp = max;
    max = min;
    min = temp;
  }
  cout << endl;
  for (int i = min; i < max; i++){
    cout << i << ", ";
  }
  cout << max << endl;
  return 0;
}
