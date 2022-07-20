#include <iostream>
#include <stack>

using namespace std;

class MyClass{
private:
   stack<int> mStack;

public:
   void pop(){
    stack<int> temp;
    for (int i = 0; i < mStack.size(); i++){
      temp.push(mStack.top());
      mStack.pop();
    }
    stack<int> ans;
    for (int i = 0; i < temp.size() + 1; i++){
      ans.push(temp.top());
      temp.pop();
    }
    mStack = ans;
   }
   int top(){
    stack<int> temp = mStack;
    for (int i = 0; i < temp.size(); i++){
      temp.pop();
    }
    return temp.top();
   }
   void push(int aVal){
    mStack.push(aVal);
   }
   bool isEmpty(){
    return mStack.empty();
   }
};

int main(){
   MyClass lQueue;
   lQueue.push(1);
   lQueue.push(2);
   lQueue.push(3);
   cout << lQueue.top() << endl;     // this line should display 1
   lQueue.pop();                                // this line should remove 1
   cout << lQueue.top() << endl;    // this line should display 2

   return 0;
}