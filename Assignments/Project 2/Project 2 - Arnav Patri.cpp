#include <fstream>
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
    unsigned int zip;
    string phone;
    unsigned int customerNumber = CURR;
    bool mailingList;
  public:
    static unsigned int CURR;
    // Constructor
    PersonData(){
      lastName = "";
      firstName = "";
      address = "";
      city = "";
      state = "";
      zip = 0;
      phone = "";
      customerNumber = 0;
      mailingList = false;
    }
    PersonData(string lN, string fN, string a, string c, string s, unsigned int z, string ph, bool ml){
      lastName = lN;
      firstName = fN;
      address = a;
      city = c;
      state = s;
      zip = z;
      phone = ph;
      customerNumber = CURR;
      CURR++;
      mailingList = ml;
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
    unsigned int getZip() const{
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
    void setZip(unsigned int z){
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
  ifstream inputFile("CustomerInfo.txt");
  string str;
  vector<string> data;
  while (inputFile >> str){
      data.push_back(str);
  }
  string form[data.size()][8];
  int row = 0;
  for (int i = 0; i < data.size(); i++){
    form[row][i % 8] = data[i];
    if (i + 1 % 8 == 0){
      row++;
    }
  }
  bool mL[sizeof(form)];
  for (int i = 0; i < sizeof(form); i++){
    if (form[i][7][1] == 't'){
      mL[i] = true;
    }
    else{
      mL[i] = false;
    }
  }
  PersonData ppl[sizeof(form)];
  int n;
  for (int i = 0; i < sizeof(ppl); i++){
    ppl[i] = PersonData(form[i][0], form[i][1], form[i][2], form[i][3], form[i][4], (unsigned int) stoi(form[i][5]), form[i][6], mL[i]);
  }
  for (PersonData p : ppl){
    cout << p.to_string();
  }
  return 0;
}
