/*
The classes for the bodies in the system, more stuff will be added as needed
*/
using namespace std;
class Moon{
  public:
    string name;
    double mass,diameter,distanceFromCenter;
    void loadReadInput(vector <string> input){
      name = input[0];
      mass = stod(input[1]);
      diameter = stod(input[2]);
      distanceFromCenter = stod(input[3]);

    }
};

class Planet{
  public:
    string name;
    double mass,diameter,distanceFromCenter;
    vector<Moon> orbiters;

    void loadReadInput(vector <string> input){
      name = input[0];
      mass = stod(input[1]);
      diameter = stod(input[2]);
      distanceFromCenter = stod(input[3]);

    }
};

class Center{
  public:
    string systemName;
    string name;
    double mass,diameter;
    vector<Planet> orbiters;

    void loadReadInput(vector <string> input){
      systemName = input[0];
      name = input[1];
      mass = stod(input[2]);
      diameter = stod(input[3]);

    }
};
