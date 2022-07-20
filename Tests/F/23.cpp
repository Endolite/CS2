#include <iostream>

using namespace std;

template <typename T>
void MyFunction(const T& x)
{
   static int count = 0;

   cout << "x = " << x << " count = " << count << endl;

   ++count;

   return;
}


int main()
{
   MyFunction(1);
   cout << endl;

   MyFunction(1);
   cout << endl;

   MyFunction(1.1);
   cout << endl;

   MyFunction('c');
   cout << endl;

   return 0;
}