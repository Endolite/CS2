#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int main(){
  fstream file("input.txt");
  vector<string> data;
  string str;
  while (file >> str){
    file >> str;
    data.push_back(str);
  }
  map<char, int> vowels{{'A', 0}, {'B', 0}, {'C', 0}};
  for (string s : data){
    for (char c : s){
      for (pair<char, int> p: vowels){
        if ((c == p.first) || (c == p.first - 32)){
          p.second++;
        }
      }
    }
  }
  for (pair<char, int> p : vowels){
    file << p.first << ": " << p.second << endl;
  }
  file.close();
  return 0;
}