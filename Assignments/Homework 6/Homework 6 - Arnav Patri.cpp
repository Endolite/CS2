#include <iostream>
#include <vector>

using namespace std;

struct MyStruct
{
   int mAge;
   double mGrade;
   char mGender;
   MyStruct(int aAge, double aGrade, char aGender)
   {
      mAge = aAge;
      mGrade = aGrade;
      mGender = aGender;
   }
};
void WriteToBinary(vector<MyStruct> &aVec);
vector<MyStruct> ReadFromFile();
int main()
{
   vector<MyStruct> lVecToWrite = { MyStruct(10, 90, 'M'),
                                    MyStruct(20, 80, 'M'),
                                    MyStruct(30, 70, 'F'),
                                    MyStruct(40, 60, 'F') };
   cout << "Vector to write to the binary file:\n";
   for (auto& item : lVecToWrite)
      cout << item.mAge << " " << item.mGender << " " << item.mGrade << endl;
   WriteToBinary(lVecToWrite);
   vector<MyStruct> lVecToRead;
   lVecToRead = ReadFromFile();
   cout << "\nVector read from the binary file:\n";
   for (auto &item : lVecToRead)
      cout << item.mAge << " " << item.mGender << " " << item.mGrade << endl;
   system("pause");
   return 0;
}