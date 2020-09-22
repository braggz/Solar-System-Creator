#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include "systemReader.h"
#include "editSystem.h"

using namespace std;
void systemDeleter(string s,int i);
Center systemReader(string s);
void editSystem(Center c);
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
  cin.ignore(10000,'\n');
  while(stoi(selectionInput1) > systems.size() || selectionInput2.size() !=1){
    if(stoi(selectionInput1) > systems.size())
      cout << "That system does not exist please try again\n";
    else
      cout << "Please only enter one operation at a time, please try again\n";
    cin >> selectionInput1;
    cin >> selectionInput2;

    cin.ignore(10000,'\n');
  }


  if(selectionInput2 == "d"){
    string selection;
    selection = systems[(stoi(selectionInput1)-1)];
    systemDeleter(selection,(stoi(selectionInput1)-1));
  }
  else if(selectionInput2 == "l"){
    string selection;
    selection = systems[(stoi(selectionInput1)-1)];
    Center c = systemReader(selection);
    c.orbiters = c.sortByLowestDistance(c.orbiters);
    c.printSystem();
    c.printSystemTextArt();

    // cout << c.orbiters[2].orbiters[3].name<<endl;
  }
  else if(selectionInput2 == "e"){
    string selection;
    selection = systems[(stoi(selectionInput1)-1)];
    Center c = systemReader(selection);
    editSystem(c);

  }
}

  systems.clear();
}
//Need to work on this so it does not need to loop through to find the system, use i
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
