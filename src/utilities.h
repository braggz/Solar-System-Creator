#include<string>
#include<iostream>
using namespace std;

//Checks if an inputed string is a number and returns true if it is.
//Im sure there are better ways to do this but I wanted to try and make it without help.
bool isInt(string s){
  for(int i =0; i < s.size();i++){

    if(s[i] != '1' && s[i] != '2' && s[i] != '3'
    && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7'
    && s[i] != '8' && s[i] != '9' && s[i] != '0'){
      cout << "You can only enter numbers!\nPlease enter the command again.\n";
      return false;
    }
  }
  return true;
}
bool isDouble(string s){
  for(int i =0; i < s.size();i++){

    if(s[i] != '1' && s[i] != '2' && s[i] != '3'
    && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7'
    && s[i] != '8' && s[i] != '9' && s[i] != '.' && s[i] != '0'){
      cout << "You can only enter numbers!\nPlease enter the command again.\n";
      return false;
    }
  }
  return true;
}
bool collisionDetection(Center *c,string name,double d){
  if(name == c->name){
    if(c->diameter < d)
      return false;
  }
  else{
    for(int i =0; i < c->orbiters.size();i++){
      for(int j =0; j <c->orbiters[i].orbiters.size(); i++){
        if(c->orbiters[i].orbiters[j].name == name ){
          if(c->orbiters[i].orbiters.size() == 1){
            if(c->orbiters[i].diameter < d){
              cout << "Planet dist: " << (c->orbiters[i-1].periapsis + (c->orbiters[i-1].diameter/2) ) <<endl;
              return false;
            }
          }
          else if(j == c->orbiters[i].orbiters.size()){
            if((c->orbiters[i].orbiters[j-1].periapsis + (c->orbiters[i].orbiters[j-1].diameter/2) )< d ){
              cout << "Moon Dist: " << (c->orbiters[i].orbiters[j-1].periapsis + (c->orbiters[i].orbiters[j-1].diameter/2) ) <<endl;
              return false;
            }
          }
          else{
            if((c->orbiters[i].orbiters[j-1].periapsis + c->orbiters[i].orbiters[j-1].diameter/2  )< d  && (c->orbiters[i].orbiters[j+1].apoapsis -(c->orbiters[i].orbiters[j+1].diameter/2 ) ) > d){
              cout << "Dist1: " <<c->orbiters[i].orbiters[j+1].apoapsis - (c->orbiters[i].orbiters[j+1].diameter/2 ) <<endl;
              cout <<"Dist2: " <<(c->orbiters[i].orbiters[j-1].periapsis + c->orbiters[i].orbiters[j-1].diameter/2  )<<endl;
              return false;
            }

          }
        }
      }
      if(c->orbiters[i].name == name ){
        if(c->orbiters.size() == 1){
          if(c->diameter < d){
            return false;
          }
        }
        else if(i == c->orbiters.size()){
          if((c->orbiters[i-1].periapsis + (c->orbiters[i-1].diameter/2)  )< d ){
            cout << "Dist: " << c->orbiters[i-1].periapsis + (c->orbiters[i-1].diameter/2) <<endl;
            return false;

          }
        }
        else{
          if((c->orbiters[i-1].periapsis + (c->orbiters[i-1].diameter/2 ) )< d  && (c->orbiters[i+1].apoapsis - (c->orbiters[i+1].diameter/2)  ) > d){
            cout << "Dist 1: " <<(c->orbiters[i-1].periapsis + (c->orbiters[i-1].diameter/2 ) ) <<endl;
            cout << "Dist 2: " <<(c->orbiters[i+1].apoapsis - (c->orbiters[i+1].diameter/2)  )<<endl;
            return false;
          }

        }
      }
    }
  }
  return true;
}
