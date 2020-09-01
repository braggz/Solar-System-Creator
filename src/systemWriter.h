#include <iostream>
#include <string>
#include <fstream>
//#include "bodies.h"


using namespace std;

void systemWriter(Center c){
    fstream f;
    string extension = "./systems/"+c.systemName + "/center"  ;
    cout << "Writting Center\n";
    f.open(extension.c_str(), fstream::out);
    f <<"System Name:"<<c.systemName <<endl;
    f <<"Body Name:"<<c.name <<endl;
    f <<"Body Mass:"<< c.mass <<endl;
    f <<"Body Diameter:"<< c.diameter <<endl;
    for(int i =0; i < c.orbiters.size() ; i++){
      f << "Orbiter " << i <<":";
      f << c.orbiters[i].name <<endl;
    }
    cout << "Center Written\n";
    f.close();

    for(int i =0; i < c.orbiters.size(); i++){
      cout << "Writting Planet " << c.orbiters[i].name << endl;
      extension = "./systems/"+c.systemName + "/" +c.orbiters[i].name;
      f.open(extension.c_str(), fstream::out);
      f << "Body Name:"<<c.orbiters[i].name <<endl;
      f << "Body Mass:"<<c.orbiters[i].mass <<endl;
      f << "Body Diameter:"<<c.orbiters[i].diameter <<endl;
      f << "Distance From Orbital Body:"<<c.orbiters[i].distanceFromCenter <<endl;
      f.close();
      cout << "c size "<<c.orbiters[i].orbiters.size()<<endl;
      for(int j =0; j< c.orbiters[i].orbiters.size(); j++){
        cout << "Writting Moon "<< c.orbiters[i].orbiters[j].name <<endl;
        extension = "./systems/"+c.systemName + "/" +c.orbiters[i].name;
        f.open(extension.c_str(), fstream::app);
        f << "Moon "<<j<<":"<<c.orbiters[i].orbiters[j].name;
        f.close();
        extension = "./systems/"+c.systemName + "/" +c.orbiters[i].orbiters[j].name;
        f.open(extension.c_str(), fstream::out);
        f << "Body Name:"<<c.orbiters[i].orbiters[j].name <<endl;
        f << "Body Mass:"<<c.orbiters[i].orbiters[j].mass <<endl;
        f << "Body Diameter:"<<c.orbiters[i].orbiters[j].diameter <<endl;
        f << "Distance From Orbital Body:"<<c.orbiters[i].orbiters[j].distanceFromCenter <<endl;
        f.close();
        cout << "Moon "<< c.orbiters[i].orbiters[j].name <<" Written"<<endl;
        }
      cout << "Planet " << c.orbiters[i].name <<" Written"<< endl;
    }


}
