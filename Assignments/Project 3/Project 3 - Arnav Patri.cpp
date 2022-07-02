// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

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
      time_t now = time(0);
			mTime = ctime(&now);
		}
		ExceptionClass(string aMsg){
			mMsg = aMsg;
			mTime = to_string(time(0));
		}
    void DisplayInfo(){
      cout << mMsg << endl;
    }
    void LogInfo(){
      ofstream log("log.txt", ios::app);
      log << mTime << ": " << mMsg << endl;
      log.close();
    }
};

template <typename T>
double divide(T aNumerator, T aDenominator){
  try {
    if (aDenominator == 0){
      throw ExceptionClass("Denominator cannot be zero");
    }
    else {
      return ((float) aNumerator) / aDenominator;
    }
  }
  catch (ExceptionClass exception){
    exception.DisplayInfo();
    exception.LogInfo();
  }
}

template <typename T>
T GetElement(vector<T> &aContainer, int aIndex){
  try {
    if (aIndex >= aContainer.size()){
      throw ExceptionClass("Out of range");
    }
    else {
      return aContainer[aIndex];
    }
  }
  catch (ExceptionClass exception){
    exception.DisplayInfo();
    exception.LogInfo();
  }
}

int main(){
  divide(1, 0);
  vector<int> vec;
  for (int i = 0; i < 3; i++){
    vec.push_back(i);
  }
  GetElement(vec, 3);
  return 0;
}