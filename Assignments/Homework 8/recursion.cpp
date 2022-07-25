// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/

#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long int> nums = {0, 1};

unsigned long long int Fib(int n){
  try {
    nums[n];
  }
  catch (out_of_range){
    nums[n] = Fib(n - 1) + Fib(n - 2);
  }
  return nums[n];
}

int main(){ 
  cout << Fib(2);
  return 0;
}