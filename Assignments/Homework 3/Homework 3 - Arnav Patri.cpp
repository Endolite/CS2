#include <iostream>
#include <cstring>

using namespace std;

int* ShiftByOne(int arr[], int n){
  int* ptr;
  int ans[n];
  ptr = ans;
  ans[0] = arr[n - 1];
  for (int i = 1; i < n; i++){
    ans[i] = arr[i - 1];
  }
  return ptr;
}

int* GetMax(int arr[], int n){
  int* ptr;
  int max = arr[0];
  for (int i = 1; i < n; i++){
    if (arr[i] > max){
      max = arr[i];
      ptr = &arr[i];
    }
  }
  return ptr;
}

unsigned int GetSize(char cstr[]){
  return strlen(cstr);
}

int main(){
  // ShiftByOne
  int n = 3;
  int arr[3] = {1, 2, 3};
  cout << ShiftByOne(arr, n) << endl;
  cout << GetMax(arr, n);
  return 0;
}
