#include <iostream>
#include <string>
#include <fstream>

using namespace std;
Center planetDeleter(Center c, string bodyName);

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
    }
}
Center planetDeleter(Center c, string bodyName){
  for(int i =0; i < c.orbiters.size();i++){
    for(int j =0; j < c.orbiters[i].orbiters.size();j++){
      if(c.orbiters[i].orbiters[j].name == bodyName){
        for(int k =j; k < c.orbiters[i].orbiters.size()-1;k++){
          c.orbiters[i].orbiters[k]=c.orbiters[i].orbiters[k+1];
        }
        c.orbiters[i].orbiters.pop_back();
        return c;
      }
    }
    if(c.orbiters[i].name == bodyName){
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
