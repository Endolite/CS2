// Arnav Patri
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
int main(){
  ifstream inputFile("students.txt");
  string str;
  string str1;
  int count = 0;
  vector<string> data;
  float scores[9][3];
  while (inputFile >> str){
    data.push_back(str);
  }
  inputFile.close();
  for (int i = 0; (i < data.size()) && (count < 8); i++){
    if (i > 5){
      if (i % 5 == 2){
        scores[count][0] = stoi(data[i]);
      }
      else if (i % 5 == 3){
        scores[count][1] = stoi(data[i]);
        scores[count][2] = (scores[count][0] + scores[count][1]) / 2;
        count++;
      }
    }
  }
  float sum[3] = {0, 0, 0};
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 8; j++){
      sum[i] += scores[j][i];
    }
  }
  cout << endl;
  for (int i = 0; i < 3; i++){
    scores[8][i] = sum[i] / 8;
  }
  count = 0;
  for (int i = 0; (i < data.size()) && (count < 8); i++){
    if (data[i] == "?"){
      data[i] = to_string(count);
      count++;
    }
  }
  count = 0;
  for (int i = 0; i < data.size(); i++){
    if (data[i] == "?"){
      data[i] = to_string(count);
      count++;
    }
  }
  int n;
  for (int i = 0; i < data.size(); i++){
    string s = data[i];
    if (s[0] == '-'){
      cout << s << endl;
    }
    else{
      if ((i % 5 == 0) || (i == data.size() - 4)){
        n = 24;
      }
      else{
        n = 16;
      }
      if (i == 3){
        cout << setw(n) << left << s << endl;
      }
      else if ((i % 5 == 0) && (i > 0) && (i < data.size() - 5)){
        i++;
        cout << setw(n) << left << s + " " + data[i];
      }
      else if ((i > data.size() - 4) && (i < data.size())){
        cout << setw(n) << left << scores[8][stoi(data[i])];
      }
      else if (i % 5 == 4){
        cout << setw(n) << left << scores[stoi(data[i])][2];
        if (i % 5 == 4){
          cout << endl;
        }
      }
      else{
        cout << setw(n) << left << s;
      }
    }
  }
  string names[8];
  count = 0;
  for (int i = 5; i < data.size() - 5; i += 5){
    names[(i / 5) - 1] = data[i] + " " + data[i + 1];
  }
  int max1 = 0;
  int max2 = 0;
  float avg = scores[8][2];
  int cavg = 0;
  for (int i = 0; i < 8; i++){
    if (abs(avg - scores[i][2]) < abs(avg - scores[cavg][2])){
      cavg = i;
    }
    if (scores[i][0] > scores[max1][0]){
      max1 = i;
    }
    if (scores[i][1] > scores[max2][1]){
      max2 = i;
    }
  }
  cout << endl << endl << names[max1] << " scored the maximum grade in Exam1." << endl;
  cout << names[max2] << " scored the maximum grade in Exam2." << endl;
  cout << names[cavg] << " was the nearest to the average." << endl;
  string resp;
  cout << endl << "Would you like to save the results back to the file? (Y/N)" << endl;
  cin >> resp;
  if (resp == "Y"){
    ofstream fout("students.txt");
    for (int i = 0; i < data.size(); i++){
      string s = data[i];
      if (s[0] == '-'){
        fout << s << endl;
      }
      else{
        if ((i % 5 == 0) || (i == data.size() - 4)){
          n = 24;
        }
        else{
          n = 16;
        }
        if (i == 3){
          fout << setw(n) << left << s << endl;
        }
        else if ((i % 5 == 0) && (i > 0) && (i < data.size() - 5)){
          i++;
          fout << setw(n) << left << s + " " + data[i];
        }
        else if ((i > data.size() - 4) && (i < data.size())){
          fout << setw(n) << left << scores[8][stoi(data[i])];
        }
        else if (i % 5 == 4){
          fout << setw(n) << left << scores[stoi(data[i])][2];
          if (i % 5 == 4){
            fout << endl;
          }
        }
        else{
          fout << setw(n) << left << s;
        }
      }
    }
    fout << endl << endl << names[max1] << " scored the maximum grade in Exam1." << endl;
    fout << names[max2] << " scored the maximum grade in Exam2." << endl;
    fout << names[cavg] << " was the nearest to the average." << endl;
    fout.close();
    cout << "Saved successfully. Good bye!";
  }
  else{
    cout << "Ok. Good bye!";
  }
  return 0;
}
