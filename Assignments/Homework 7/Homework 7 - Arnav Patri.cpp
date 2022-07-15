// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

// classes that you need to implement:
class Student
{
private:
   int mID;
   string mName;
   double mGPA;
   map<string, int> mGrades;
   void CalculateGPA();

public:
   Student();
   Student(int aID, string aName, map<string, int> aGrades);

   bool AddGrade(string aCourse, int aGrade);

   void setID(int aID);
   int getID();

   void setName(string aName);
   string getName();

   void setGradesMap(map<string, int> aMap);
   map<string, int> getGradesMap();

   double getGPA();
};
class StudentContainer
{
private:
   map<int, Student> mStudents;
   unsigned int mSize;

public:
   StudentContainer();
   StudentContainer(map<int, Student> aStudents);

   bool AddStudent(Student aStudent);
   bool RemoveStudent(int aID);
   bool ChangeStudent(Student aStudent);
   bool Clear();
   void ViewStudentInfo(int aID);
   void setMap(map<int, Student> aStudents);

   unsigned int getSize();
};

// implemetation example: Default constructor for class Student
Student::Student()
{
   mID = -1;
   mName = "";
   mGPA = 0;

   map<string, int> temp;
   mGrades = temp;
}
Student::Student(int aID, string aName, map<string, int> aGrades){
  mID = aID;
  mName = aName;
  mGrades = aGrades;
  CalculateGPA();
}
bool Student::AddGrade(string aCourse, int aGrade){
  map<string, int> temp = mGrades;
  mGrades.insert(make_pair(aCourse, aGrade));
  return (temp.erase(aCourse) == 0);
}

void Student::setID(int aID){
  mID = aID;
}
int Student::getID(){
  return mID;
}

void Student::setName(string aName){
  mName = aName;
}
string Student::getName(){
  return mName;
}

void Student::setGradesMap(map<string, int> aMap){
  mGrades = aMap;
}
map<string, int> Student::getGradesMap(){
  return mGrades;
}

void Student::CalculateGPA(){
  double sum = 0;
  // I wasn't sure how GPA was being calculated, but this is how it would work at my school.
  for (pair<string, int> si : mGrades){
    if (si.second >= 90){
      sum += 4;
    }
    else if (si.second >= 80){
      sum += 3;
    }
    else if (si.second >= 70){
      sum += 2;
    }
    else if (si.second >= 60){
      sum++;
    }
  }
  mGPA = sum / mGrades.size();
}

double Student::getGPA(){
  CalculateGPA();
  return mGPA;
}


StudentContainer::StudentContainer(){
  mSize = 0;
}
StudentContainer::StudentContainer(map<int, Student> aStudents){
  mStudents = aStudents;
  mSize = mStudents.size();
}

bool StudentContainer::AddStudent(Student aStudent){
  map<int, Student> temp(mStudents);
  mStudents.insert(make_pair(aStudent.getID(), aStudent));
  return (temp.erase(aStudent.getID()) == 0);
}
bool StudentContainer::RemoveStudent(int aID){
  return mStudents.erase(aID);
}
bool StudentContainer::ChangeStudent(Student aStudent){
  if (mStudents.erase(aStudent.getID())){
    mStudents[aStudent.getID()] = aStudent;
    return true;
  }
  else {
    return false;
  }
}
bool StudentContainer::Clear(){
  mStudents.clear();
  return true;
}
void StudentContainer::ViewStudentInfo(int aID){
  Student s = mStudents[aID];
  cout << "Name: " << s.getName() << endl << "GPA: " << setprecision(2) << s.getGPA() << endl;
  for (pair<string, int> si : s.getGradesMap()){
    cout << "Course: " << si.first << " -> grade: " << si.second << endl;
  }
}
void StudentContainer::setMap(map<int, Student> aStudents){
  mStudents = aStudents;
}

unsigned int StudentContainer::getSize(){
  return mStudents.size();
}

// sample testing code
int main()
{
   Student FirstStudent;

   FirstStudent.setID(1);
   FirstStudent.setName("First");
   map<string, int> FirstStudentGrades;
   FirstStudentGrades["CS2"] = 80;
   FirstStudentGrades["Alg"] = 90;
   FirstStudent.setGradesMap(FirstStudentGrades);
   FirstStudent.AddGrade("Math", 100);

   map<string, int> SecondStudentGrades;
   SecondStudentGrades["CS2"] = 50;
   SecondStudentGrades["Alg"] = 60;
   SecondStudentGrades["Math"] = 70;
   Student SecondStudent(2, "Second", SecondStudentGrades);

   map<int, Student> StudentsMap;
   StudentsMap[FirstStudent.getID()] = FirstStudent;

   StudentContainer MyContainer;
   MyContainer.setMap(StudentsMap);
   MyContainer.AddStudent(SecondStudent);

   cout << "The size of the container is " << MyContainer.getSize() << endl;

   cout << "\nDisplaying Info:\n\nStudent ID: " << 2 << endl;
   MyContainer.ViewStudentInfo(2);

   MyContainer.RemoveStudent(2);
   cout << "\nThe size after removing student id=2: " << MyContainer.getSize() << endl;

   Student temp;
   temp.setID(1);
   temp.setName("Mark");
   map<string, int> grades;
   grades["CS2"] = 10;
   grades["Alg"] = 20;
   grades["Math"] = 30;
   temp.setGradesMap(grades);

   cout << "\nStudent ID=1 before change: " << endl;
   MyContainer.ViewStudentInfo(1);

   MyContainer.ChangeStudent(temp);

   cout << "\nStudent ID=1 after change: " << endl;
   MyContainer.ViewStudentInfo(1);

   cout << "\nsize before clear: " << MyContainer.getSize()  << endl;
   
   cout << "size after clear: ";
   MyContainer.Clear();
   cout << MyContainer.getSize() << endl;


   system("pause");
   return 0;
}

