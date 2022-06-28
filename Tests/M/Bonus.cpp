// Arnav Patri
#include <iostream>
#include <cstring>

using namespace std;

// Arnav Patri
void reverseString(char* Input){
  char* end = Input;
  while (*end){
    end++;
  }
  while (Input < end){
    char temp = *Input;
    *Input = *end;
    *end = temp;
    Input++;
    end--;
  }
}

int main(){
  char cstr[] = "abcdef";
  cout << &cstr << endl;
  reverseString(cstr);
  for (char c : cstr){
    cout << c;
  }
  cout << endl << &cstr;
  return 0;
}