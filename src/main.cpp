#include <iostream>
#include "create_new_system.h"
#include "loadSystem.h"
using namespace std;

int main(){

  char input;
  while(input != 'e'){
    //Clear Screen
    for(int i =0; i < 20 ; i++)
      cout << endl;
      cout << "Welcome to Solar System Creator!\n\n";
      cout<< "---------------------------------------------\n";

    cout << "Type 'c' to create a new system\n";
    cout << "Type 'e' to exit\n";
    cout << "Type 'l' to load a system\n";
    cin >> input;

    switch(input){
      case 'c':
        createNewSystem();
        break;
      case 'e' :
        break;
      case 'l' :
        loadSystem();
        break;
        default :
        cout << "Invalid input, please try again.\n";
      }
    }
    cout << "Thank you for playing!\n";
    return 0;
}
