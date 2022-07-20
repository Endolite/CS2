/*
Write a template function that can sort a vector of elements of any data type. Example: double, float, int, char.

Note: Can NOT use STL
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void sort(vector<T>& vec){
  int mI;
  T mV;
  T temp;
  for (int i = 0; i < vec.size() - 1; i++){
    mI = i;
    mV = vec[mI];
    for (int j = mI + 1; j < vec.size(); j++){
      if (vec[j] < mV){
        mV = vec[j];
        mI = j;
      }
    }
    temp = vec[i];
    vec[i] = vec[mI];
    vec[mI] = temp;
  }
}


int main(){
  vector<int> vec;
  vec.push_back(4);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(7);
  sort(vec);
  for (int i : vec){
    cout << i << " ";
  }
  return 0;
}