/*
Write code that does the following:
  - Opens a file called "Numbers.txt" which has integer values, one integer on each line
  - Reads the values from the file
  - Computes the sum of values read from the file and their count
  - Finally, the program writes the results (Sum and Count) to a new file called "Results.txt"
*/

#include <fstream>
#include <iostream>

using namespace std;

int main(){
  string n;
  int sum = 0;
  int count = 0;
  ifstream inputFile("Numbers.txt");
  if (inputFile){
    while (inputFile >> n){
      sum += stoi(n);
      count++;
    }
    ofstream outputFile("Results.txt");
    outputFile << "Sum: " << sum << endl << "Count: " << count;
  }
  else {
    cout << "File Numbers.txt could not be opened." << endl;
  }
  return 0;
}
