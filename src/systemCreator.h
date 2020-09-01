/*
TO DO: I need to parse the input of these responses to prevernt errors!


*/
#include <iostream>
#include <string>
#include "bodies.h"
#include "systemWriter.h"
Planet createMoons(Planet p);
void systemWriter(Center c);
using namespace std;
//vector <Planet> planets;
void systemCreator(string s){
  Center center;
  center.systemName = s;
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
  while(input == "y"){
    Planet planet;
    cout << "Please name your the body\n";
    cin >> planet.name;
    //center.orbitersNames.push_back(planet.name);
    cin.ignore(10000,'\n');
    cout << "Now enter the mass of the body\n";
    cin >> planet.mass;
    cin.ignore(10000,'\n');
    cout << "What is the diameter of this body ?\n";
    cin >> planet.diameter;
    cin.ignore(10000,'\n');
    cout << "How far is this planet from the central object of your system\n";
    cin >> planet.distanceFromCenter;
    cin.ignore(10000,'\n');
    cout << "Do you want to add moons to this planet? y/n\n";
    cin >> input;
    cin.ignore(10000,'\n');

    if(input == "y"){
      planet = createMoons(planet);
    }
    center.orbiters.push_back(planet);
    cout << "Add another planet? y/n\n";
    cin >> input;
    cin.ignore(10000,'\n');
  }
  systemWriter(center);
}

Planet createMoons(Planet p){
    string input ="y";
    while(input == "y"){
      Moon moon;
      cout << "Enter the name of this moon\n";
      cin >> moon.name;
      cin.ignore(10000,'\n');
      cout << "Enter the mass of this moon\n";
      cin >> moon.mass;
      cin.ignore(10000,'\n');
      cout << "What is the diameter of the moon?\n";
      cin >> moon.diameter;
      cin.ignore(10000,'\n');
      cout << "How far is this moon from the planet?\n";
      cin >> moon.distanceFromCenter;
      cin.ignore(10000,'\n');
      cout << "Do you want to add another moon? y/n\n";
      //string input;
      cin >> input;
      cin.ignore(10000,'\n');
      p.orbiters.push_back(moon);
  }
    //p.moonNames.push_back(moon.name);
     return p;
}
