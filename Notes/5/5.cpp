#include <fstream>
#include <iostream>

using namespace std;
int main(){
  ifstream inputFile("input.txt");
  ofstream outputfile("Notes\\5\\output.txt");
  for (int i = 0; i < 0; i++){
    outputfile << i;
  }
  outputfile.close();
  return 0;
}
