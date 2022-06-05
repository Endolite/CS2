// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/
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
  return 0;
}
