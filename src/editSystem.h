#include <iostream>
#include <string>
#include <fstream>

using namespace std;
Center planetDeleter(Center c, string bodyName);
void focusView(Center c, string body);

void editSystem(Center c){


  string input;
  string bodyName;
  c.orbiters = c.sortByLowestDistance(c.orbiters);
  while (input != "b"){

    c.printSystem();
    c.printSystemTextArt();
    cout<< "This is the edit interface.\n";
    cout<< "Type delete \"Planet Name\" to delete a planet and its moons. (You cannot delete your central body.)\n";
    cout<< "Or type focus \"Body Name\" to edit the variables of that body\n";
    cout << "Please be aware that these changes cannot be reversed\n";
    cout << "Enter b to go back to\n";

    cin >> input;
    cin >> bodyName;
    cin.ignore(10000,'\n');
    if(input == "delete")
      c = planetDeleter(c, bodyName);
      systemWriter(c);

    if(input == "focus")
      focusView(c, bodyName);
    }



}
Center planetDeleter(Center c, string bodyName){
  string path = "./systems/" + c.systemName;
  for(int i =0; i < c.orbiters.size();i++){
    for(int j =0; j < c.orbiters[i].orbiters.size();j++){
      if(c.orbiters[i].orbiters[j].name == bodyName){
        path = path + "/" + c.orbiters[i].orbiters[j].name;
        remove(path.c_str());
        for(int k =j; k < c.orbiters[i].orbiters.size()-1;k++){
          c.orbiters[i].orbiters[k]=c.orbiters[i].orbiters[k+1];
        }
        c.orbiters[i].orbiters.pop_back();
        return c;
      }
    }
    if(c.orbiters[i].name == bodyName){
      path = path + "/" + c.orbiters[i].name;
      remove(path.c_str());
      for(int n =0; n < c.orbiters[i].orbiters.size(); n++){
        path = "./systems/" + c.systemName + "/" + c.orbiters[i].orbiters[n].name;
        remove(path.c_str());
      }
      for(int k =i; k < c.orbiters.size()-1;k++){
        c.orbiters[k]=c.orbiters[k+1];
      }
      c.orbiters.pop_back();

      return c;
    }
  }
  cout << "Could not find any body by that name!\n";
  return c;
}

void focusView(Center c, string bodyName){
  Planet p;
  p = c.findPlanet(bodyName);
  if(p.name.size() > 0){
    cout << "succ\n";
  }
  else
    cout << ":(\n";
  string test;




}
