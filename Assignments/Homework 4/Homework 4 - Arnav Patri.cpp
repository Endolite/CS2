// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/
#include <iostream>

using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
};

void sort(int arr[], int size){
  bool change = true;
  while (change){
    change = false;
    for (int i = 0; i < size - 1; i++){
      if (*(arr + i) > *(arr + i + 1)){
        swap(*(arr + i), *(arr + i + 1));
        change = true;
      }
    }
  }
};

int main(){
  string str;
  cout << "Enter the size of your list: ";
  cin >> str;
  const int size = stoi(str);
  int scores[size];
  for (int i = 0; i < size; i++){
    cout << "Enter a score: ";
    cin >> *(scores + i);
    while ((*(scores + i) < 1) || (*(scores + i) > 100)){
      cout << "Invalid score; Please enter a value between 1 and 100: ";
      cin >> *(scores + i);
    }
  }
  sort(scores, size);
  cout << endl << "List of scores in ascending order:" << endl;
  for (int i = 0; i < size; i++){
    cout << *(scores + i) << " ";
  }
  return 0;
}
