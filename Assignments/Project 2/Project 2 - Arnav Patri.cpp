// Arnav Patri
/*I HAVE NEITHER GIVEN NOR RECEIVED UNAUTHORIZED
AID IN COMPLETING THIS WORK, NOR HAVE I PRESENTED
SOMEONE ELSE’S WORK AS MY OWN.*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PersonData{
  private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    unsigned int customerNumber;
    bool mailingList;
  public:
    static unsigned int CURR;
    // Constructors
    PersonData(){
      lastName = "";
      firstName = "";
      address = "";
      city = "";
      state = "";
      zip = "";
      phone = "";
      customerNumber = CURR;
      CURR++;
      mailingList = false;
    }
    PersonData(string lN, string fN, string a, string c, string s, string z, string ph, bool mL){
      lastName = lN;
      firstName = fN;
      address = a;
      city = c;
      state = s;
      zip = z;
      phone = ph;
      customerNumber = CURR;
      CURR++;
      mailingList = mL;
    }
    // Getters
    string getLastName() const{
      return lastName;
    }
    string getFirstName() const{
      return firstName;
    }
    string getAddress() const{
      return address;
    }
    string getCity() const{
      return city;
    }
    string getState() const{
      return state;
    }
    string getZip() const{
      return zip;
    }
    string getPhone() const{
      return phone;
    }
    unsigned int getCustomerNumber() const{
      return customerNumber;
    }
    bool getMailingList() const{
      return mailingList;
    }
    // Setters
    void setLastName(string str){
      lastName = str;
    }
    void setFirstName(string str){
      firstName = str;
    }
    void setAddress(string str){
      address = str;
    }
    void setCity(string str){
      city = str;
    }
    void setState(string str){
      state = str;
    }
    void setZip(string z){
      zip = z;
    }
    void setPhone(string str){
      phone = str;
    }
    void setMailingList(bool b){
      mailingList = b;
    }
    // to_string
};
unsigned int PersonData::CURR = 1;

int main(){
  ifstream inputFile("CutomerInfo.txt");
  string str;
  vector<string> data;
  while (inputFile >> str){
      data.push_back(str);
  }
  inputFile.close();
  string form[5][8];
  int row = 0;
  int col = 0;
  for (int i = 0; i < data.size(); i++){
    if (col == 2){
      while ((data[i - 1] != "Rd") && (data[i - 1] != "Hwy")){
        form[row][col] += data[i] + " ";
       i++;
      }
      col++;
      form[row][col] = data[i];
    }
    else if (col == 6){
      form[row][col] = data[i] + data[i + 1];
      i++;
    }
    else {
      form[row][col] = data[i];
      if (col == 7){
        col = -1;
        row++;
      }
    }
    col++;
  }
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 8; j++){
      cout << setw(25) << form[i][j];
    }
    cout << endl;
  }
  bool mL[5];
  for (int i = 0; i < 5; i++){
    if (form[i][7] == "true"){
      mL[i] = true;
    }
    else{
      mL[i] = false;
    }
  }
  PersonData people[5];
  for (int i = 0; i < 5; i++){
    people[i].setLastName(form[i][0]);
    people[i].setFirstName(form[i][1]);
    people[i].setAddress(form[i][2]);
    people[i].setCity(form[i][3]);
    people[i].setState(form[i][4]);
    people[i].setZip(form[i][5]);
    people[i].setPhone(form[i][6]);
    people[i].setMailingList(mL[i]);
  }
  for (int i = 0; i < 5; i++){
    if (people[i].getMailingList()){
      cout << setw(10) << people[i].getLastName() << setw(10) << people[i].getFirstName() << setw(25) << people[i].getAddress() << setw(4) << people[i].getState() << setw(7) << people[i].getZip() << setw(15) << people[i].getPhone() << setw(5) << people[i].getCustomerNumber() << endl;
    }
  }
  return 0;
}
