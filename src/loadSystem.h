#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include "systemReader.h"
#include "editSystem.h"
#include "utilities.h"

using namespace std;
void systemDeleter(string s,int i);
Center systemReader(string s);
void editSystem(Center *c);
bool isInt(string s);
void loadSystem(){


  fstream f;

  f.open(systemFile.c_str(), fstream::in);
  string lines;
  while(getline(f,lines,',')){
    systems.push_back(lines);
  }
  f.close();




string command,value;

if(systems.size() != 0){
  while(command != "b"){
    for(int i = 0; i < systems.size(); i++){
      cout << i+1 <<". ";
      cout << systems[i] << endl;
    }
    cout << "Enter b to go back to the main menu.\n";
    cout << "Type help to view commands\n";
    cin >> command;
    if(command != "b")
      cin >> value;
    cin.ignore(10000,'\n');
    if(!isInt(value) && command !="b"){
      cout << "That is not a number!.\nPress Enter to continue.\n";
      cin.ignore();
      systems.clear();
      loadSystem();
      return;
    }
    if(stoi(value) > systems.size() && command != "b"){
      cout << "That is not a valid system!\nPress Enter to continue.\n";
      cin.ignore();
      systems.clear();
      loadSystem();
      return;
    }
    if(command == "delete"){
      string selection;
      selection = systems[(stoi(value)-1)];
      systemDeleter(selection,(stoi(value)-1));
    }
    else if(command == "load"){
      string selection;
      selection = systems[(stoi(value)-1)];
      Center c = systemReader(selection);
      c.orbiters = c.sortByLowestDistance(c.orbiters);
      c.printSystem();
      c.printSystemTextArt();
    }
    else if(command == "edit"){
      string selection;
      selection = systems[(stoi(value)-1)];
      Center c = systemReader(selection);
      editSystem(&c);
    }
    else if(command != "b"){
      cout << "Command not recognized.\nPress Enter to continue.\n";
      cin.ignore();
    }

  }

 }
 else{
   cout << "No systems detected, please create one first!\n";
   cout << "Press enter to go back to the menu\n";
   cin.ignore();
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
