#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <vector>
using namespace std;
string getPath();
bool checkDuplicate(string s, vector<string> v);
const string systemFile = "./systems/systems";
vector<string> systems;
void systemWriter(vector<string> v);

void createNewSystem(){
  cout << "Please enter system name\n";
  cout << "System Name: ";
  string systemName;
  cin >> systemName;
  fstream f;

  f.open(systemFile.c_str(), fstream::app);
  if(!f.is_open())
    wcerr << "Could not open the systems file\n";
  f.close();
  f.open(systemFile.c_str(), fstream::in);
  string lines;
  while(getline(f,lines,',')){
    systems.push_back(lines);
  }
  f.close();
  while(!checkDuplicate(systemName,systems)){
    cout << "There is already a system with that name, please try again\n";
    cin >> systemName;
  }
  systems.push_back(systemName);
  systemWriter(systems);
  systems.clear();

  string pathName = getPath();
  pathName = pathName + "/systems/" + systemName;


  if(mkdir(pathName.c_str(),0777) == -1){
    cout << "dsfsdf";
  }
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
