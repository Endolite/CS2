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
      customerNumber = 0;
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
    string to_string(){
      return "a";
    }
};
unsigned int PersonData::CURR = 1;

int main(){
  ifstream inputFile("CutomerInfo.txt");
  string str;
  //cout << (inputFile >> str);
  vector<string> data;
  while (inputFile >> str){
      data.push_back(str);
  }
  string form[5][8];
  int row = 0;
  int j;
  for (int i = 0; i < data.size(); i++){
    if (j == 3){
      while ((data[i] != "Rd") && (data[i] != "Hwy")){
        form[row][j] += data[i];
        i++;
      }
    }
    else if (j == 7){
      form[row][j] = data[i] + data[i + 1];
      i++;
    }
    else{
      form[row][j] = data[i];
      if (j == 8){
        j = -1;
        row++;
      }
    }
    j++;
  }
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 9; j++){
      cout << setw(20) << left << form[i][j];
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
  PersonData* people[5];
  /*
  for (int i = 0; i < 5; i++){
    people[i] = new PersonData(form[i][0], form[i][1], form[i][2], form[i][3], form[i][4], form[i][5], form[i][6], mL[i]);
    //cout << form[i][0] << form[i][2] << form[i][3] << form[i][4] << form[i][5] << form[i][6] << form[i][7];
  }
  for (PersonData* p : people){
    cout << p -> to_string();
  }
  */
  return 0;
}
