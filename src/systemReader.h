#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string parseLines(string s);
Center systemReader(string s){
  Center c;
  fstream f;
  vector <string> readCenter;
  vector <string> readPlanets;
  vector <string> readMoons;
  string extension = "./systems/"+ s + "/center";
  cout<< extension<<endl;
  f.open(extension.c_str(), fstream::in);
  string lines;
  cout << "Loading Center\n";
  while(getline(f,lines)){
    readCenter.push_back(parseLines(lines));
    cout << parseLines(lines) << endl;
  }
  f.close();
  c.loadReadInput(readCenter);
  cout << "Center Loaded\n";
  for(int i =4;i<readCenter.size();i++){
    Planet p;
    extension = "./systems/"+ s + "/" + readCenter[i];
    cout << "Loading "<<readCenter[i]<<endl;
    f.open(extension.c_str(), fstream::in);
    while(getline(f, lines)){
        readPlanets.push_back(parseLines(lines));
    }
    f.close();
    p.loadReadInput(readPlanets);

    for(int j =5;j<readPlanets.size();j++){
      cout << "Loading "<<readCenter[i] <<"'s Moon, "<<readPlanets[j]<<endl;
      Moon m;
      extension = "./systems/"+ s + "/" + readPlanets[j];
      f.open(extension.c_str(), fstream::in);
      while(getline(f, lines)){
        readMoons.push_back(parseLines(lines));
        //cout << parseLines(lines)<<endl;
      }
      f.close();
      m.loadReadInput(readMoons);
      readMoons.clear();
      p.orbiters.push_back(m);

    }
    c.orbiters.push_back(p);
    cout << readCenter[i] << " Loaded\n";
    readPlanets.clear();



  }


  cout << "System Loaded!\n";
  return c;
}
string parseLines(string s){
  for(int i=0; i<s.size();i++){
    if(s[i]==':'){
      return s.substr(i+1,s.size());
    }
  }
  return s;
}
