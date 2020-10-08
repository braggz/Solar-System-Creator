#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void planetDeleter(Center *c, string bodyName);
void focusView(Center *c, string body);
void loadSystem();
void commandParser(Center *c,string command);

void editSystem(Center *c){
  string input;
  string bodyName;
  c->sortByLowestDistance(c->orbiters);
  c->printSystem();
  c->printSystemTextArt();
  cout<< "This is the edit interface.\n";
  cout<< "Type delete \"Planet Name\" to delete a planet and its moons. (You cannot delete your central body.)\n";
  cout<< "Or type focus \"Body Name\" to edit the variables of that body\n";
  cout << "Please be aware that these changes cannot be reversed\n";
  cout << "Enter b to go back\n";
  while (input != "b"){




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
    focusView(c,objectValue);
  }
  else if(command == "apoapsis"){
    string objectName, objectValue;
    cin >> objectName;
    cin >> objectValue;
    int planetIndex = c->findPlanetIndex(objectName);
    vector<int> moonIndex = c->findMoonIndex(objectName);
    cout << c->name <<endl;
    if(objectName == c->name){
      cout << "Your central body does not have an apoapsis.\n";
      cout << "Press enter to continue.\n";

      cin.ignore();

      focusView(c,objectName);
    }

    else if(planetIndex != -1){
      c->orbiters[planetIndex].apoapsis = stod(objectValue);
      systemWriter(c);
      focusView(c,objectName);
    }

    else if(moonIndex.size()>0){
      c->orbiters[moonIndex[0]].orbiters[moonIndex[1]].apoapsis = stod(objectValue);
      systemWriter(c);
      focusView(c,objectName);
    }
    else{
      cout << "That moon or planet does not exist.\n Press enter to continue.\n";
      cin.ignore();
    }

  }
  else if(command == "delete"){
    string objectName;
    cin >> objectName;
    planetDeleter(c,objectName);
    systemWriter(c);
  }
  else if (command != "b"){
    cout << "Command not recognized. Press enter to continue.\n";
    cin.ignore();
  }
}
