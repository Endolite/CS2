// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/
#include <iostream>
#include <iomanip>
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
      const tm* lnow = localtime(&now);
      char buffer[256];
		  strftime(buffer, sizeof(buffer), "%H:%M:%S %m/%d/%Y", lnow);
      mTime = buffer;
		}
		ExceptionClass(string aMsg){
			mMsg = aMsg;
      time_t now = time(0);
			const tm* lnow = localtime(&now);
      char buffer[256];
		  strftime(buffer, sizeof(buffer), "%H:%M:%S %m/%d/%Y", lnow);
      mTime = buffer;
		}
    void DisplayInfo(){
      cout << "error: " <<  mMsg << endl;
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
   return aContainer.at(aIndex);
  }
  catch (out_of_range){
    ExceptionClass exception = ExceptionClass("Out of range");
    exception.DisplayInfo();
    exception.LogInfo();
  }
}

int main(){
  char response;
  bool valid = true;
  bool cont = true;
  cout << "divide (D) or GetElement (E)? ";
  while (true){
    cin >> response;
    if (response == 'D'){
      cout << "int (I) or double (D)? ";
      while (true){
        cin >> response;
        if (response == 'I'){
          int i1, i2;
          while (true){
            cout << "int 1: ";
            cin >> i1;
            cout << "int 2: ";
            cin >> i2;
            if (i2 != 0){
              cout << "int 1 / int 2: " << setprecision(15) << divide(i1, i2) << endl << endl;
            }
            else {
              divide(i1, i2);
            }
          }
        }
        else if (response == 'D'){
          double d1, d2;
          while (true){
            cout << "double 1: ";
            cin >> d1;
            cout << "double 2: ";
            cin >> d2;
            if (d2 != 0){
              cout << "double 1 / double 2: " << setprecision(15) << divide(d1, d2) << endl << endl;
            }
            else {
              divide(d1, d2);
            }
          }
        }
        cout << "Invalid. Try again: ";
      }
      break;
    }
    else if (response == 'E'){
      cout << "integers (I) or doubles (D)? ";
      while (true){
        cin >> response;
        if (response == 'I'){
          vector<int> vec;
          string data;
          string datum;
          int i;
          int j;
          while (true){
            j = 0;
            vec.clear();
            cout << "data (separated by spaces): ";
            cin >> datum;
            vec.push_back(stoi(datum));
            getline(cin, data);
            for (int k = 1; k <= data.length(); k++){
              if ((data[k] == ' ') || (k == data.length())){
                vec.push_back(stoi(data.substr(j, k)));
                j = k + 1;
              }
            }
            cout << " index: ";
            cin >> i;
            if ((i >= 0) && (i < vec.size())){
              cout << "item at " << i << " is " << GetElement(vec, i) << endl << endl;
            }
            else {
              GetElement(vec, i);
              cout << endl;
            }
          }
        }
        else if (response == 'D'){
          vector<double> vec;
          string datum;
          string data;
          int i;
          int j = 0;
          while (true){
            j = 0;
            vec.clear();
            cout << "data (separated by spaces): ";
            cin >> datum;
            vec.push_back(stod(datum));
            getline(cin, data);
            for (int k = 1; k <= data.length(); k++){
              if ((data[k] == ' ') || (k == data.length())){
                vec.push_back(stod(data.substr(j, k)));
                j = k + 1;
              }
            }
            cout << "index: ";
            cin >> i;
            if ((i >= 0) && (i < vec.size())){
              cout << "item at " << i << " is " << GetElement(vec, i) << endl << endl;
            }
            else {
              GetElement(vec, i);
              cout << endl;
            }
          }
        }
        cout << "Invalid. Try again: ";
      }
      break;
    }
    cout << "Invalid. Try again:";
  }
  return 0;
}