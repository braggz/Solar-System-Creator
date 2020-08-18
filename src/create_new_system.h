#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;
string getPath();

void createNewSystem(){
  cout << "Please enter system name\n";
  cout << "System Name: ";
  string systemName;
  cin >> systemName;
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
