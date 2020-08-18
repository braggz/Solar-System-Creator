#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

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

  string selectionInput;
  cin >> selectionInput;
  while(selectionInput.size() > 2){
    cout << "Please only enter two characters\n";
    cin >> selectionInput;
  }

  
  systems.clear();
}
