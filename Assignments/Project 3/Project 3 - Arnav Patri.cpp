// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ExceptionClass {
  private:
    string mMsg;
    string mTime;
    void _setTime(string str){
      mTime = str;
    }
  public: 
		ExceptionClass(){
			mMsg = "";
			mTime = "1";
		}
		ExceptionClass(string aMsg){
			mMsg = aMsg;
			mTime = to_string(time(0));
		}
    void DisplayInfo(){
      cout << mTime << ": " << mMsg;
    }
};

template <typename T>
double divide(T aNumerator, T aDenominator){
  if (aDenominator == 0){
    throw ExceptionClass("Denominator cannot be zero");
  }
  else {
    return ((float) aNumerator) / aDenominator;
  }
}

template <typename T>
T GetElement(vector<T> &aContainer, int aIndex){
  try {
    return aContainer[aIndex];
  }
  catch(out_of_range){
    throw ExceptionClass("Out of Range");
  }
}

int main(){
  return 0;
}