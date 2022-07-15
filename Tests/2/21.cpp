/*
Write a template function called GetMax(). The function takes two arguments and returns the value that is the greater of the two. For example:

- If 2 and 3 are passed, then it returns 3.

- if 2.0 and 3.0 are passed, then it return 3.0.

- if "AAA" and "BBB" are passed, then it return "BBB"


The function should throw an exception if both arguments are equal, and the exception should be of the type string. The exception should be caught/handled by the driver program only (main() ). Provide both the function and the driver program calling it.
*/

// Arnav Patri
#include <iostream>

using namespace std;

template <class T>
T GetMax(T var1, T var2){
  if (var1 == var2){
    throw (string) "Exception: Equal arguments";
  }
  else if (var1 > var2){
    return var1;
  }
  else {
    return var2;
  }
}

int main(){
  try {
    cout << GetMax(2, 3);
  }
  catch (string exception){
    cout << exception;
  }
  return 0;
}