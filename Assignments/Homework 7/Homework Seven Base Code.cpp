#include <iostream>
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

