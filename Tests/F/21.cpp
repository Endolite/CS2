#include <iostream>

using namespace std;

class Person
{
private:
    int mAge;
    string mName;
public:
    Person() { mAge = 0; mName = "Any"; }

    // postfix operator overload
    Person operator++(int){
      Person temp = *this;
      mAge++;
      return temp;
    }
    Person operator--(int){
      Person temp = *this;
      mAge--;
      return temp;
    }

    // prefix operator overload:
    Person& operator++(){
      mAge++;
      return *this;
    }
    Person& operator--(){
      mAge--;
      return *this;
    }
};

int main(){
  Person p();
  
}