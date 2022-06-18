// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/
#include <iostream>

using namespace std;
class StudentClass {
  private:
    string mName;
  public:
    StudentClass(){
      mName = "";
    }
    StudentClass(string mN){
      mName = mN;
    }
    const StudentClass operator=(const StudentClass &right){
      if (this != &right){
        mName = right.mName;
      }
      return *this;
    }
    StudentClass operator+(const StudentClass &right){
      mName += " " + right.mName;
      return *this;
    }
    char operator[](const int i){
      return mName[i];
    }
    friend istream &operator>>(istream &strm, StudentClass &obj);
    friend ostream &operator<<(ostream &strm, StudentClass &obj);
    unsigned int CountLetters(char c){
      unsigned int count = 0;
      for (int i = 0; i < mName.length(); i++){
        if (mName[i] == c){
          count++;
        }
      }
      return count;
    }
    void Reverse(){
      string temp = mName;
      for (int i = 0; i < mName.length(); i++){
        mName[i] = temp[temp.length() - 1 - i];
      }
    }
};

istream &operator>>(istream &strm, StudentClass &obj){
  strm >> obj.mName;
  return strm;
}
ostream &operator<<(ostream &strm, StudentClass &obj){
  strm << obj.mName;
  return strm;
}

using namespace std;
int main(){
  return 0;
}