#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;
void systemDeleter(string s,int i);

void loadSystem(){

  fstream f;

  f.open(systemFile.c_str(), fstream::in);
  string lines;
  while(getline(f,lines,',')){
    systems.push_back(lines);
  }
  f.close();
  for(int i = 0; i < systems.size(); i++){
    cout << i+1 <<". ";
    cout << systems[i] << endl;
  }
  bool b = false;
  if(systems.size() == 0){
    cout << "No systems detected, please create one first!\n";
    cout << "Press anykey to go back to the menu\n";
    string noInput;
    cin >> noInput;
    cin.ignore(10000,'\n');
    b = true;
  }

  string selectionInput1;
  string selectionInput2;
if(!b){
  cin >> selectionInput1;
  cin >> selectionInput2;
  while(stoi(selectionInput1) > systems.size() || selectionInput2.size() !=1){
    if(stoi(selectionInput1) > systems.size())
      cout << "That systen does not exist please try again\n";
    else
      cout << "Please only enter one operation at a time, please try again\n";
    cin >> selectionInput1;
    cin >> selectionInput2;
    cout << selectionInput1 << " " <<selectionInput2 <<endl;
    cin.ignore(10000,'\n');
  }


  if(selectionInput2 == "d"){
    string selection;
    selection = systems[(stoi(selectionInput1)-1)];
    systemDeleter(selection,(stoi(selectionInput1)-1));
  }
}

  systems.clear();
}

void systemDeleter(string s, int i){
  for(int j =0; j < systems.size();j++){
    if(systems[j] == s){
      for(int k = j; k < systems.size()-1;k++){
        systems[k] = systems[k+1];

      }
    }
  }
  systems.pop_back();
  systemWriter(systems);
  s = "rm -rf ./systems/" + s;
  system(s.c_str());
}