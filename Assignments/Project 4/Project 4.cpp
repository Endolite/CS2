// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/

#include <iostream>

using namespace std;

class MyStack{
  public:
    struct MyNode{
      int mValue;
      MyNode* mNext = nullptr;
      MyNode(int aValue){
        mValue = aValue;
      }
    };
    struct MyException{
      string mDescription;
      MyException(string aDescription){
        mDescription = aDescription;
      }
    };
    MyStack(){
      mHead = nullptr;
      mMaxSize = 10;
    }
    MyStack(int aSize){
      mHead = nullptr;
      mMaxSize = aSize;
    }
    ~MyStack(){
      MyNode* ptr = nullptr;
      MyNode* pos = mHead;
      while (pos != nullptr){
        delete ptr;
        MyNode* ptr = pos;
        pos = pos->mNext;
      }
      delete ptr;
      pos = mHead;
      while (pos != nullptr){
        cout << pos->mValue << "      ";
        pos = pos->mNext;
      }
      cout << endl;
    }
    void Pop(){
      MyNode* prev = nullptr;
      MyNode* ptr = nullptr;
      MyNode* pos = mHead;
      while (pos != nullptr){
        prev = ptr;
        ptr = pos;
        pos = pos->mNext;
      }
      if (mHead == nullptr){
        throw MyException("Empty Stack");
      }
      else {
        delete ptr;
        prev->mNext = nullptr;
      }
    }
    void Push(int aValue){
      MyNode* ptr = nullptr;
      MyNode* pos = mHead;
      int size = 1;
      while (pos != nullptr){
        ptr = pos;
        pos = pos->mNext;
        size++;
      }
      if (size > mMaxSize){
        throw MyException("Maximum Capacity");
      }
      else if (mHead == nullptr){
        mHead = new MyNode(aValue);
      }
      else {
        ptr->mNext = new MyNode(aValue);
      }
    }
    int Top(){
      MyNode* ptr = nullptr;
      MyNode* pos = mHead;
      while (pos != nullptr){
        ptr = pos;
        pos = pos->mNext;
      }
      if (mHead == nullptr){
        throw MyException("Empty Stack");
      }
      else {
        return ptr->mValue;
      }
    }
    bool isEmpty(){
      if (mHead == nullptr){
        return true;
      }
      else {
        return false;
      }
    }
  private:
    MyNode* mHead;
    unsigned int mMaxSize;
};

int main(){
  MyStack stack(2);
  try {
    stack.Pop();
  }
  catch (MyStack::MyException exception){
    cout << exception.mDescription << endl;
  }
  try {
    stack.Top();
  }
  catch (MyStack::MyException exception){
    cout << exception.mDescription << endl;
  }
  cout << stack.isEmpty() << endl;
  stack.Push(1);
  cout << stack.isEmpty() << endl;
  stack.Push(10);
  cout << stack.Top() << endl;
  try {
    stack.Push(0);
  }
  catch (MyStack::MyException exception){
    cout << exception.mDescription << endl;
  }
  stack.~MyStack();
  try {
    stack.Push(0);
  }
  catch (MyStack::MyException exception){
    cout << exception.mDescription << endl;
  }
  cout << stack.Top() << endl;
}