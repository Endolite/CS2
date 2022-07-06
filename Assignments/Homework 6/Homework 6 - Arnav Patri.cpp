// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/

#include <iostream>
#include <fstream>
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
void WriteToBinary(vector<MyStruct> &aVec){
   ofstream fout("bin.dat");
   for (MyStruct MS: aVec){
      fout.write(reinterpret_cast<char*>(&MS.mAge), sizeof(int));
      fout.write(reinterpret_cast<char*>(&MS.mGrade), sizeof(double));
      fout.write(&MS.mGender, sizeof(char));
   }
   fout.close();
}
vector<MyStruct> ReadFromFile(){
   ifstream fin("bin.dat");
   vector<MyStruct> ret;
   MyStruct read(0, 0.0, 'A');
   string age;
   string grade;
   char c;
   while (fin){
      fin.read(reinterpret_cast<char*>(&read.mAge), sizeof(int));
      fin.read(reinterpret_cast<char*>(&read.mGrade), sizeof(double));
      fin.read(reinterpret_cast<char*>(&read.mGender), sizeof(char));
      ret.push_back(read);
   }
   ret.pop_back();
   fin.close();
   return ret;
}
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