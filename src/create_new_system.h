#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <vector>
#include "systemCreator.h"
using namespace std;
string getPath();
bool checkDuplicate(string s, vector<string> v);
const string systemFile = "./systems/systems";
vector<string> systems;
void systemWriter(vector<string> v);


void createNewSystem(){
  bool b = false;
  cout << "Please enter system name (No spaces allowed!)\n";
  cout << "System Name: ";
  string input;
  cin >> input;
  cin.ignore(10000,'\n');;

  if(input == "b"){
    b = true;
  }
  while(input.size() > 20){
    cout << "Please keep system names below 20 characters\n";
    cout << "Press 'b' to go back to main menu\n";
    cout << "System Name: ";
    cin >> input;
    cin.ignore(10000,'\n');;
    if(input == "b")
      b = true;
  }
  if(!b){
    fstream f;

    f.open(systemFile.c_str(), fstream::in);
    string lines;
    while(getline(f,lines,',')){
      systems.push_back(lines);
    }
    f.close();
  }


  while(!checkDuplicate(input,systems) && !b){
    cout << "There is already a system with that name, please try again\n";
    cout << "Press 'b' to go back to main menu\n";
    cout << "System Name: ";
    cin >> input;
    cin.ignore(10000,'\n');;
    if(input == "b")
      b = true;
  }
  string systemName;
  if(!b){
    systemName = input;
    systems.push_back(input);
    systemWriter(systems);
    systems.clear();
    string pathName = getPath();

    pathName = pathName + "/systems/" + input;
    if(mkdir(pathName.c_str(),0777) == -1){
      wcerr << "Could not create folder" ;
    }
  }

if(!b)
  systemCreator(systemName);
}

//gets the path to the exe and removes the exe name
string getPath(){
  char buff[10000];
  ssize_t len = readlink("/proc/self/exe",buff,sizeof(buff)-1);
  string path;

  if(len != -1 ){
    buff[len] = '\0';
    string pathWithExe = string(buff);
    for(int i =pathWithExe.size(); i > 0 ;i--){
        if(pathWithExe[i] == '/'){
          path = pathWithExe.substr(0,i);
          return path;
        }

    }

  }

  return "";

};

bool checkDuplicate(string s, vector<string> v){
  for(int i = 0; i < v.size(); i++){
    if(v[i] == s){
      return false;
    }
  }
  return true;
}

void systemWriter(vector<string> v){
  fstream f;
  f.open(systemFile.c_str(), fstream::out);
  for(int i =0; i < v.size(); i++){
    f << v[i] << ',';
  }
  f.close();

}
