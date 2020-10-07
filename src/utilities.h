#include<string>
#include<iostream>
using namespace std;

//Checks if an inputed string is a number and returns true if it is.
//Im sure there are better ways to do this but I wanted to try and make it without help.
bool isInt(string s){
  for(int i =0; i < s.size();i++){

    if(s[i] != '1' && s[i] != '2' && s[i] != '3'
    && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7'
    && s[i] != '8' && s[i] != '9'){
      cout << "You can only enter numbers!\nPlease enter the command again.\n";
      return false;
    }
  }
  return true;
}
