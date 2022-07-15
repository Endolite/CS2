#include <iostream>
#include <map>

using namespace std;
int main(){
  map<int, int> mi;
  mi[1];
  mi.insert(make_pair(1, 1));
  for (auto i : mi){
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}