//#include <iostream>
//#include <string>
//#include "create_new_system.h"
using namespace std;
class Moon{
  public:
    string name;
    double mass,diameter,distanceFromCenter;
};

class Planet{
  public:
    //string systemName;
    string name;
    double mass,diameter,distanceFromCenter;
    vector<Moon> orbiters;
};

class Center{
  public:
    string systemName;
    string name;
    double mass,diameter;
    vector<Planet> orbiters;
};
