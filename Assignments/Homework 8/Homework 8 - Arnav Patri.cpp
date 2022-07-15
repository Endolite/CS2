// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/

#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long int> nums = {0, 1};

unsigned long long int Fib(int n){
  if (n > nums.size() - 1){
    for (int i = nums.size(); i <= n; i++){
    nums.push_back(nums[i - 1] + nums[i - 2]);
    }
  }
  return nums[n];
}

int main(){ 
  // Breaks after 93
  cout << Fib(94);
  return 0;
}