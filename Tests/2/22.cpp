/*
Assume you have a text file that has information about a few students. Each student is represented in three lines. Example of a file with two students:


Augustina Aceto
23
313-123-4567
Karl Badaro
21
313-765-4321

 

Provide a class called MyList that represents a sorted-ascending linked list, and a Node struct ListNode that represents a student. The class must have a private member pointer variable called mHead which points at the first node in the list, or null if/when the list is empty. Then, provide the following functions:

- Default Constructor
- InsertNode( string aFullName, int aAge, string aPhoneNum )
- DeleteNode( string aFullName )
- GetMaxAge()
- DestroyList()

 

Demonstrate your program by creating an instance of MyList in main(), and use the ifstream to read from the file into the list. Each student record must be stored in list using the InsertNode() function. Function GetMaxAge() should return the greatest age among all students in the list.

Assume there are no duplicate student names.
*/

// Arnav Patri
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct ListNode {
  string name;
  int age;
  string phone;
  ListNode* next;
};

class MyList {
  private:
    ListNode* mHead;
  public:
    MyList(){
      mHead = nullptr;
    }
    void InsertNode(string aFullName, int aAge, string aPhoneNum){
      cout << aFullName << endl << aAge << endl << aPhoneNum << endl << endl;
      ListNode* ptr = nullptr;
      ListNode* pos = mHead;
      while ((pos != nullptr) && (pos->age < aAge)){
        ptr = pos;
        pos = pos->next;
      }
      cout << ptr << endl << endl;
      ListNode node = {aFullName, aAge, aPhoneNum, ptr};
      if (mHead == nullptr){
        mHead = &node;
        cout << "new head" << endl << endl;
      }
    }
    void DeleteNode(string aFullName){
      ListNode* prev = nullptr;
      ListNode* next = nullptr;
      ListNode* pos = mHead;
      while ((pos != nullptr) && (pos->name != aFullName)){
        prev = pos;
        pos = pos->next;
      }
      if (pos){
        prev->next = pos->next;
        delete pos;
      }
    }
    int GetMaxAge(){
      ListNode n1 = *(*mHead).next;
      cout << n1.name << endl << endl;
      /*
      ListNode* pos = mHead;
      while ((pos != nullptr) && (pos->next != nullptr)){
        pos = pos->next;
      }
      if (pos != mHead){
         return pos->age;
      }
      else {
        return 0;
      }*/
      return 0;
    }
    void DestroyList(){
      ListNode* pos = mHead;
      ListNode* next = nullptr;
      while (pos != nullptr){
        next = pos->next;
        delete pos;
        pos = next;
      }
    }
};


int main(){
  MyList students;
  ifstream fin("students.txt");
  string name;
  string temp;
  int age;
  string phone;
  int count = 0;
  while (fin){
    if (count % 3 == 0){
      fin >> name;
      fin >> temp;
      name += " " + temp;
      //cout << name << endl;
    }
    else if (count % 3 == 1){
      fin >> age;
      //cout << age << endl;
    }
    else {
      fin >> phone;
      //cout << phone << endl << endl;
      students.InsertNode(name, age, phone);
    }
    count++;
  }
  fin.close();
  cout << students.GetMaxAge();
  return 0;
}