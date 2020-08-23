/*
TO DO: I need to parse the input of these responses to prevernt errors!


*/
#include <iostream>
#include <string>
#include "planets.h"
void createMoons(Planet p);
using namespace std;
vector <Planet> planets;
void systemCreator(){
  Planet center;
  cout << "First you must create the center or your system, the heavier it is, the more gravity will affect other bodies\n";
  cout << "Please name your central body\n";
  cin >> center.name;
  cin.ignore(10000,'\n');
  cout << "Now enter the mass of your central body\n";
  cin >> center.mass;
  cin.ignore(10000,'\n');
  cout << "What is the diameter of this body ?\n";
  cin >> center.diameter;
  cin.ignore(10000,'\n');


  string input;
  cout << "Do you want to add bodies to orbit your central? Hit y if yes and any other key if no\n";
  cin >> input;
  cin.ignore(10000,'\n');
  while(input != "y"){
    Planet planet;
    cout << "Please name your the body\n";
    cin >> planet.name;
    center.orbitersNames.push_back(planet.name);
    cin.ignore(10000,'\n');
    cout << "Now enter the mass of the body\n";
    cin >> planet.mass;
    cin.ignore(10000,'\n');
    cout << "What is the diameter of this body ?\n";
    cin >> planet.diameter;
    cin.ignore(10000,'\n');
    cout << "How far is this planet from the central object of your system\n";
    cin >> planet.distanceFromCenter;
    cout << "Do you want to add moons to this planet? y/n\n";
    cin >> input;
    cin.ignore(10000,'\n');
    if(input == "y"){
      createMoons(planet);
    }
    cout << "Add another planet? y/n\n";
    cin >> input;
    cin.ignore(10000,'\n');
  }
}

void createMoons(Planet p){

}
