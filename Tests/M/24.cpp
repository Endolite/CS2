// Arnav Patri
#include <iostream>

using namespace std;

class HumanClass {
  private:
    int mAge;
    string mName;
  public:
    HumanClass(int ma, string mn){
      mAge = ma;
      mName = mn;
    }
    HumanClass operator++(int){
      HumanClass temp = HumanClass(mAge, mName);
      mAge++;
      return temp;
    }
    bool operator==(const HumanClass &right){
      if (mAge == right.mAge){
        return true;
      }
      else {
        return false;
      }
    }
    char operator[](int n){
      return mName[n];
    }
};

int main(){
  return 0;
}