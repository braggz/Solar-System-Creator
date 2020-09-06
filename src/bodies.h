/*
The classes for the bodies in the system, more stuff will be added as needed
*/
using namespace std;
class Moon{
  public:
    string name;
    double mass,diameter,periapsis,apoapsis;
    void loadReadInput(vector <string> input){
      name = input[0];
      mass = stod(input[1]);
      diameter = stod(input[2]);
      apoapsis = stod(input[3]);
      periapsis = stod(input[4]);

    }
};

class Planet{
  public:
    string name;
    double mass,diameter,periapsis,apoapsis;
    vector<Moon> orbiters;

    void loadReadInput(vector <string> input){
      name = input[0];
      mass = stod(input[1]);
      diameter = stod(input[2]);
      apoapsis = stod(input[3]);
      periapsis = stod(input[4]);

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
    void printSystem(){
      cout << "System Name: " << systemName <<endl;
      cout << "   Central Object Name: " << name <<endl;
      for(int i = 0; i < orbiters.size(); i++){
        cout << "       Planet Name: " << orbiters[i].name <<endl;
        for(int j=0; j < orbiters[i].orbiters.size(); j++){
          cout << "           Moon Name: " << orbiters[i].orbiters[j].name << endl;
        }
      }
    }
    void printSystemTextArt(){

      int size = (name.size()/2)+6;
      for(int i =0; i < size;i++)
        cout <<" ";

      cout << "0";
      for(int i =0; i < size;i++)
        cout <<"-";

      for(int i =0; i < orbiters.size();i++){
        size = (orbiters[i].name.size()/2)+6;
        if(i == orbiters.size()-1){
          for(int j =0; j < size;j++)
            cout << "-";
          cout << "o";
        }
        else{
          cout <<"o";
          for(int j =0; j < size;j++){
            cout << "-";
          }
        }

      }
      cout << endl;
       size = (name.size()/2)+6;
      for(int i =0; i < size;i++)
        cout <<" ";

      cout << "^";
      for(int i =0; i < size;i++)
        cout <<" ";

      for(int i =0; i < orbiters.size();i++){
        size = (orbiters[i].name.size()/2)+6;
        if(i == orbiters.size()-1){
          for(int j =0; j < size;j++)
            cout << " ";
          cout << "^";
        }
        else{
          cout <<"^";
          for(int j =0; j < size;j++){
            cout << " ";
          }
        }

      }
      cout << endl;
      size = (name.size()/2)+3;
     for(int i =0; i < size;i++)
       cout <<" ";

     cout << name;
     for(int i =0; i < size;i++)
       cout <<" ";

     for(int i =0; i < orbiters.size();i++){
       size = (orbiters[i].name.size()/2)+3;
       if(i == orbiters.size()-1){
         for(int j =0; j < size;j++)
           cout << " ";
         cout << orbiters[i].name;
       }
       else{
         cout <<orbiters[i].name;
         for(int j =0; j < size;j++){
           cout << " ";
         }
       }

     }
     cout << endl;

  }

  vector<Planet> sortByLowestDistance(vector<Planet> p){
    vector<Planet> sorted;
    Planet temp;
    for(int i =0; i<p.size();i++){
      double adverageDist = (p[i].apoapsis+p[i].periapsis)/2;
      for(int j =i;j<p.size();j++){
        if(adverageDist > (p[j].apoapsis+p[j].periapsis)/2){
          temp = p[j];
          p[j] = p[i];
          p[i] = temp;
        }
      }
    }
    return p;

  }

};
