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
//Puts all of the periapsis and apoapsis in accending order. Then it uses and index to see if the orbits would collide.
bool collisionDetectionPlanets(Center *c,string name,double newVal, double diameter){
  double radius = (diameter/2);
  int savedIndex;
  vector<double> peri;
  vector<double> apo;
  //Get the periapsis and apoapsis on a vector
  for(int i =0; i < c->orbiters.size(); i++){
    peri.push_back(c->orbiters[i].periapsis);
    apo.push_back(c->orbiters[i].apoapsis);
    if(c->orbiters[i].name == name)
      savedIndex = i;
  }
  int indexApo,indexPeri = savedIndex;
  for(int i=0;i<peri.size();i++)
    cout <<peri[i] <<" ";
  cout <<endl;
  for(int i=0; i< apo.size();i++)
    cout << apo[i]<<" ";
  cout << endl;
  //Sort the vectors in accending order
  double temp;
  for(int i =0; i < peri.size();i++){
      for(int j =i;j < peri.size();j++){
        if(peri[i] > peri[j]){
          if(i==savedIndex)
            indexPeri = j;
          temp = peri[i];
          peri[i] = peri[j];
          peri[j] = temp;
        }
      }
  }
  for(int i =0; i < apo.size();i++){
      for(int j =i;j < apo.size();j++){
        if(apo[i] > apo[j]){
          if(i == savedIndex)
            indexApo = j;
          temp = apo[i];
          apo[i] = apo[j];
          apo[j] = temp;
        }
      }
      cout << "saved index: "<<savedIndex<<endl;
      cout << "apo in: " << indexApo<<endl;
      cout <<"peri in: "<<indexPeri<<endl;
      for(int i=0;i<peri.size();i++)
        cout <<peri[i] <<" ";
      cout <<endl;
      for(int i=0; i< apo.size();i++)
        cout << apo[i]<<" ";
      cout << endl;
      if(savedIndex == 0 && savedIndex != apo.size()-1 && savedIndex != peri.size()-1){
        if(newVal > c->diameter/2 + radius && newVal + radius < peri[indexPeri+1])
          return false;
        else
          return true;
      }
      else if(savedIndex == apo.size()-1 || savedIndex == peri.size() -1){
        if(newVal > apo[indexApo-1] +(c->diameter/2) + radius)
          return false;
        else
          return true;
      }
      else if(newVal > apo[indexApo-1]+radius && newVal+radius < peri[indexPeri+1])
        return false;
      else
        return true;
  }
  return true;
}
bool collisionDetectionMoons(Center *c,string name,double newVal, double diameter){
  double radius = (diameter/2);
  int savedIndex;
  vector<double> peri;
  vector<double> apo;
  //Get the periapsis and apoapsis on a vector
  vector<int> moonIndex = c->findMoonIndex(name);
  vector<Moon> moons = c->orbiters[moonIndex[0]].orbiters;
  for(int i =0; i < moons.size(); i++){
    peri.push_back(moons[i].periapsis);
    apo.push_back(moons[i].apoapsis);
    if(moons[i].name == name)
      savedIndex = i;
  }
  int indexApo,indexPeri = savedIndex;
  for(int i=0;i<peri.size();i++)
    cout <<peri[i] <<" ";
  cout <<endl;
  for(int i=0; i< apo.size();i++)
    cout << apo[i]<<" ";
  cout << endl;
  //Sort the vectors in accending order
  double temp;
  for(int i =0; i < peri.size();i++){
      for(int j =i;j < peri.size();j++){
        if(peri[i] > peri[j]){
          if(i==savedIndex)
            indexPeri = j;
          temp = peri[i];
          peri[i] = peri[j];
          peri[j] = temp;
        }
      }
  }
  for(int i =0; i < apo.size();i++){
      for(int j =i;j < apo.size();j++){
        if(apo[i] > apo[j]){
          if(i == savedIndex)
            indexApo = j;
          temp = apo[i];
          apo[i] = apo[j];
          apo[j] = temp;
        }
      }
      cout << "saved index: "<<savedIndex<<endl;
      cout << "apo in: " << indexApo<<endl;
      cout <<"peri in: "<<indexPeri<<endl;
      for(int i=0;i<peri.size();i++)
        cout <<peri[i] <<" ";
      cout <<endl;
      for(int i=0; i< apo.size();i++)
        cout << apo[i]<<" ";
      cout << endl;

      if(savedIndex == 0 && savedIndex != apo.size()-1 && savedIndex != peri.size()-1){
        if(newVal > c->orbiters[moonIndex[0]].diameter/2 + radius && newVal + radius < peri[indexPeri+1])
          return false;
        else
          return true;
      }
      else if(savedIndex == apo.size()-1 || savedIndex == peri.size() -1){
        if(newVal > apo[indexApo-1] + radius + c->orbiters[moonIndex[0]].diameter/2)
          return false;
        else
          return true;
      }
      else if(newVal > apo[indexApo-1]+radius && newVal+radius < peri[indexPeri+1])
        return false;
      else
        return true;
  }
  return true;
}
