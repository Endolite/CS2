#include <iostream>
#include <iomanip>

using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
};

void bubble(int arr[], int size){
  bool change;
  do {
    change = false;
    for (int i = 0; i < size - 1; i++){
      if (arr[i] > arr[i + 1]){
        swap (arr[i], arr[i + 1]);
        change = true;
      }
    }
  } while (change);
};
/*
void select(int *arr, int size){
  for (int i = 0; i < size - 1; i++){

  }
}
*/

int main(){
  void numbers[5];
  int arr[] = {6, 1, 5, 2, 4, 3};
  int size = 6;
  for (int i = 0; i < size; i++){
    cout << setw(5) << arr[i];
  }
  cout << endl;
  bubble(arr, size);
  for (int i = 0; i < size; i++){
    cout << setw(5) << arr[i];
  }
  return 0;
}
