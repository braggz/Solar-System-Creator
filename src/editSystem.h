#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void planetDeleter(Center *c, string bodyName);
void focusView(Center *c, string body);
void loadSystem();
void commandParser(Center *c,string command);
void setApoapsis(Center *c, string objectName, string objectValue);
bool isDouble(string s);
bool collisionDetectionPlanets(Center *c,string name,double newVal,double diameter);
void setPeriapsis(Center *c, string objectName, string objectValue);
bool collisionDetectionMoons(Center *c,string name,double newVal, double diameter);
void setMass(Center *c, string objectName, string objectValue);

void editSystem(Center *c){
  string input;
  string bodyName;
  c->sortByLowestDistance(c->orbiters);
  c->printSystem();
  c->printSystemTextArt();

  while (input != "b"){
    cout<< "This is the edit interface.\n";
    cout<< "Type delete \"Planet Name\" to delete a planet and its moons. (You cannot delete your central body.)\n";
    cout<< "Or type focus \"Body Name\" to edit the variables of that body\n";
    cout << "Please be aware that these changes cannot be reversed\n";
    cout << "Enter b to go back\n";



    string value;
    cin >> input;
    if(input != "b")
      commandParser(c,input);


  }
}


void planetDeleter(Center *c, string bodyName){
  string path = "./systems/" + c->systemName;
  for(int i =0; i < c->orbiters.size();i++){
    for(int j =0; j < c->orbiters[i].orbiters.size();j++){
      if(c->orbiters[i].orbiters[j].name == bodyName){
        path = path + "/" + c->orbiters[i].orbiters[j].name;
        remove(path.c_str());
        for(int k =j; k < c->orbiters[i].orbiters.size()-1;k++){
          c->orbiters[i].orbiters[k]=c->orbiters[i].orbiters[k+1];
        }
        c->orbiters[i].orbiters.pop_back();
        return;

      }
    }
    if(c->orbiters[i].name == bodyName){
      path = path + "/" + c->orbiters[i].name;
      remove(path.c_str());
      for(int n =0; n < c->orbiters[i].orbiters.size(); n++){
        path = "./systems/" + c->systemName + "/" + c->orbiters[i].orbiters[n].name;
        remove(path.c_str());
      }
      for(int k =i; k < c->orbiters.size()-1;k++){
        c->orbiters[k]=c->orbiters[k+1];
      }
      c->orbiters.pop_back();
      return;
    }
  }
  if(bodyName == c->name){
    cout << "You cannot delete your central body!\n Press enter to continue\n";
    cin.ignore();
  }
  else{
  cout << "Could not find any body by that name!\n Press enter to continue.\n";
  cin.ignore();
  }
}

void focusView(Center *c, string bodyName){

  Planet p;
  Moon m;
  p = c->findPlanet(bodyName);
  m = c->findMoon(bodyName);

  if(bodyName == c->name){
    bool b = true;
    string command, object;
    cout << "\n\nCentral Body Name: " << c->name << endl;
    cout << "Mass: " << c->mass <<endl;
    cout << "Diameter: " <<c->diameter <<endl;
    cout << "Orbiters: ";
    for(int i =0; i < c->orbiters.size() ; i++){
      if(i == c->orbiters.size()-1)
        cout << c->orbiters[i].name << ".";
      else
        cout << c->orbiters[i].name <<", ";

    }

  }
  else if(p.name.size() > 0){
    string command, object;
    cout << "\n\nPlanet Name: " << p.name << endl;
    cout << "Mass: " << p.mass <<endl;
    cout << "Diameter: " <<p.diameter <<endl;
    cout << "Apoapsis: " <<p.apoapsis <<endl;
    cout << "Periapsis: "<<p.periapsis<<endl;
    cout << "Moons: ";
    for(int i =0; i < p.orbiters.size() ; i++){
      if(i == p.orbiters.size()-1)
        cout << p.orbiters[i].name << ".";
      else
        cout << p.orbiters[i].name <<", ";
      }


  }
  //need to make sure people cant name moons and planets the same name!
  else if(m.name.size() > 0){
    string command, object;
    cout << "\n\nMoon Name: " << m.name << endl;
    cout << "Mass: " << m.mass <<endl;
    cout << "Diameter: " <<m.diameter <<endl;
    cout << "Apoapsis: " <<m.apoapsis <<endl;
    cout << "Periapsis: "<<m.periapsis<<endl;

  }
  else{
    cout << "Planet or moon not found! Press enter to continue.\n";
    cin.ignore();
  }
}

void commandParser(Center *c, string command){

  if(command == "focus"){
    string objectValue;
    cin >> objectValue;
    cin.ignore(10000,'\n');
    focusView(c,objectValue);
  }
  else if(command == "apoapsis"){
    string objectName, objectValue;
    cin >> objectName;
    cin >> objectValue;
    cin.ignore(10000,'\n');
    setApoapsis(c,objectName,objectValue);
  }
  else if(command == "periapsis"){
    string objectName, objectValue;
    cin >> objectName;
    cin >> objectValue;
    cin.ignore(10000,'\n');
    setPeriapsis(c,objectName,objectValue);
  }
  else if(command == "delete"){
    string objectName;
    cin >> objectName;
    cin.ignore(10000,'\n');
    planetDeleter(c,objectName);
    systemWriter(c);
  }
  else if(command == "mass"){
    string objectName,objectValue;
    cin >> objectName;
    cin >> objectValue;
    cin.ignore(10000,'\n');
    setMass(c,objectName,objectValue);
    systemWriter(c);
    focusView(c,objectName);

  }
  else if (command != "b"){
    cout << "Command not recognized. Press enter to continue.\n";
    cin.ignore();
  }
}

void setApoapsis(Center *c, string objectName, string objectValue){

//  cin.ignore(10000,'\n');
  int planetIndex = c->findPlanetIndex(objectName);
  vector<int> moonIndex = c->findMoonIndex(objectName);
  cout << c->name <<endl;
  if(objectName == c->name){
    cout << "Your central body does not have an apoapsis.\n";
    cout << "Press enter to continue.\n";

    cin.ignore();

    focusView(c,objectName);
  }
//Need to finish this
  else if(planetIndex != -1){
    if(isDouble(objectValue)){
        if(stod(objectValue) > c->orbiters[planetIndex].periapsis){
          if(!collisionDetectionPlanets(c,objectName,stod(objectValue),c->orbiters[planetIndex].diameter)){
            c->orbiters[planetIndex].apoapsis = stod(objectValue);
            systemWriter(c);
            focusView(c,objectName);
            return;
          }
          else{
            cout << "There was a collision detected.\nPress enter to continue.\n";
            cin.ignore();
          }
        }
        else{
          cout<<"Your apoapsis must be greater than your periapsis!\nPress enter to continue.\n";
          cin.ignore();
        }
    }
    else{
      cout << "That was not a number!\nPress enter to continue\n";
      cin.ignore();
    }

  }

  else if(moonIndex.size()>0){
    if(isDouble(objectValue)){
        if(stod(objectValue) > c->orbiters[moonIndex[0]].orbiters[moonIndex[1]].periapsis){
          if(!collisionDetectionMoons(c,objectName,stod(objectValue),c->orbiters[moonIndex[0]].orbiters[moonIndex[1]].diameter)){
            c->orbiters[moonIndex[0]].orbiters[moonIndex[1]].apoapsis = stod(objectValue);
            systemWriter(c);
            focusView(c,objectName);
            return;
          }
          else{
            cout << "There was a collision detected.\nPress enter to continue.\n";
            cin.ignore();
          }
        }
        else{
          cout<<"Your apoapsis must be greater than your periapsis!\nPress enter to continue.\n";
          cin.ignore();
        }
    }
    else{
      cout << "That was not a number!\nPress enter to continue\n";
      cin.ignore();
    }


  }
  else{
    cout << "That moon or planet does not exist.\n Press enter to continue.\n";
    cin.ignore();
  }
}

void setPeriapsis(Center *c, string objectName, string objectValue){

//  cin.ignore(10000,'\n');
  int planetIndex = c->findPlanetIndex(objectName);
  vector<int> moonIndex = c->findMoonIndex(objectName);
  cout << c->name <<endl;
  if(objectName == c->name){
    cout << "Your central body does not have an apoapsis.\n";
    cout << "Press enter to continue.\n";

    cin.ignore();

    focusView(c,objectName);
  }
//Need to finish this
  else if(planetIndex != -1){
    if(isDouble(objectValue)){
        if(stod(objectValue) < c->orbiters[planetIndex].apoapsis){
          if(!collisionDetectionPlanets(c,objectName,stod(objectValue),c->orbiters[planetIndex].diameter)){
            c->orbiters[planetIndex].periapsis = stod(objectValue);
            systemWriter(c);
            focusView(c,objectName);
            return;
          }
          else{
            cout << "There was a collision detected.\nPress enter to continue.\n";
            cin.ignore();
          }
        }
        else{
          cout<<"Your periapsis must be less than your apoapsis!\nPress enter to continue.\n";
          cin.ignore();
        }
    }
    else{
      cout << "That was not a number!\nPress enter to continue\n";
      cin.ignore();
    }

  }

  else if(moonIndex.size()>0){
    if(isDouble(objectValue)){
        if(stod(objectValue) < c->orbiters[moonIndex[1]].orbiters[moonIndex[1]].apoapsis){
          if(!collisionDetectionMoons(c,objectName,stod(objectValue),c->orbiters[moonIndex[0]].orbiters[moonIndex[1]].diameter)){
            c->orbiters[moonIndex[0]].orbiters[moonIndex[1]].apoapsis = stod(objectValue);
            systemWriter(c);
            focusView(c,objectName);
            return;
          }
          else{
            cout << "There was a collision detected.\nPress enter to continue.\n";
            cin.ignore();
          }
        }
        else{
          cout<<"Your apoapsis must be greater than your periapsis!\nPress enter to continue.\n";
          cin.ignore();
        }
    }
    else{
      cout << "That was not a number!\nPress enter to continue\n";
      cin.ignore();
    }

  }
  else{
    cout << "That moon or planet does not exist.\n Press enter to continue.\n";
    cin.ignore();
  }
}
void setMass(Center *c, string objectName, string objectValue){
  if(isDouble(objectValue)){
    if(stod(objectValue) >= 0){
      int planetIndex = c->findPlanetIndex(objectName);
      vector<int> moonIndex = c->findMoonIndex(objectName);
      if(c->name == objectName)
        c->mass = stod(objectValue);
      else if(planetIndex != -1){
        c->orbiters[planetIndex].mass = stod(objectValue);
      }
      else if(moonIndex.size()>0){
        c->orbiters[moonIndex[0]].orbiters[moonIndex[1]].mass = stod(objectValue);
      }
      else
        cout << "Could find no body by that name\n";
      }
      else
        cout << "The value must not be a negative number\n";
    }
    else
      cout << "Please enter a number\n";


}
