// Arnav Patri
#include <iostream>
#include <vector>

using namespace std;

class Employee {
  private:
    string name;
    string hireDate;
  public:
    Employee(string nm, string hD){
      name = nm;
      hireDate = hD;
    }
    string getHireDate(){
      return hireDate;
    }
    string getName(){
      return name;
    }
};

class ProductionWorker : public Employee {
  private:
    int shift;
  public: 
    ProductionWorker(string nm, string hD, int n) : Employee(nm, hD) {
      shift = n;
    }
    int getShift(){
      return shift;
    }
};

int main(){
  int noW;
  cout << "How many workers? ";
  cin >> noW;
  string hireDate;
  string shiftS;
  int shift;
  vector<ProductionWorker> workers;
  string name;
  for (int i = 0; i < noW; i++){
    cout << "Name: ";
    cin >> name;
    cout << "Hire date (mm-dd-yyyy): ";
    cin >>  hireDate;
    cout << "Shift (day/night): ";
    cin >> shiftS;
    if (shiftS[0] == 'd'){
      shift = 1;
    }
    else {
      shift = 2;
    }
    workers.push_back(ProductionWorker(name, hireDate, shift));
  }
  for (ProductionWorker worker : workers){
    if ((worker.getShift() == 1) && (stoi(worker.getHireDate().substr(6)) < 2019)){
      cout << worker.getName() << endl;
    }
  }
  return 0;
}