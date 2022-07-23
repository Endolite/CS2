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
        pos = pos->mNext;
      }
      mHead = nullptr;
    }
    void Pop(){
      if (mHead == nullptr){
        throw MyException("Empty Stack");
      }
      else if (this->Top() == mHead->mValue){
        this->~MyStack();
      }
      else {
        MyNode* prev = mHead;
        MyNode* ptr = mHead->mNext;
        while (ptr->mNext != nullptr){
          prev = ptr;
          ptr = ptr->mNext;
        }
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
  stack.Push(2);
  cout << stack.Top() << endl;
  try {
    stack.Push(0);
  }
  catch (MyStack::MyException exception){
    cout << exception.mDescription << endl;
  }
  stack.~MyStack();
  try {
    stack.Push(3);
  }
  catch (MyStack::MyException exception){
    cout << exception.mDescription << endl;
  }
  cout << stack.Top() << endl;
  stack.Push(4);
  stack.Pop();
  stack.Pop();
  try {
    cout << stack.Top();
  }
  catch (MyStack::MyException exception){
    cout << exception.mDescription << endl;
  }
}