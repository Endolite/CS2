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
      mMaxSize = 0;
    }
    MyStack(int aSize){
      mHead = nullptr;
      mMaxSize = aSize;
    }
    ~MyStack(){

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
      try {
        if (mHead == nullptr){
          throw MyException("Empty Stack");
        }
        else {
          delete ptr;
          prev->mNext = nullptr;
        }
      }
      catch (MyException exception){
        cout << exception.mDescription;
      }
    }
    void Push(int aValue){
      MyNode node(aValue);
      MyNode* ptr = nullptr;
      MyNode* pos = mHead;
      while (pos != nullptr){
        ptr = pos;
        pos = pos->mNext;
      }
      if (mHead == nullptr){
        mHead = &node;
      }
      else {
        ptr->mNext = &node;
      }
    }
    int Top(){
      MyNode* ptr = nullptr;
      MyNode* pos = mHead;
      while (pos != nullptr){
        ptr = pos;
        pos = pos->mNext;
      }
      try {
        if (mHead == nullptr){
          throw MyException("Empty Stack");
        }
        else {
          return ptr->mValue;
        }
      }
      catch (MyException exception){
        cout << exception.mDescription;
      }
    }
    bool isEmpty(){

    }
  private:
    MyNode* mHead;
    unsigned int mMaxSize;
};

int main(){
  return 0;
}