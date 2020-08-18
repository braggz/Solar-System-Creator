#include <iostream>
#include "create_new_system.h"
using namespace std;

int main(){
  //Clear Screen
  for(int i =0; i < 20 ; i++)
    cout << endl;

  char input;
  while(input != 'e'){
    cout << "Welcome to Solar System Creator!\n\n";
    cout << "Type 'c' to create a new system\n";
    cout << "Type 'e' to quit\n";
    cin >> input;

    switch(input){
      case 'c':
        createNewSystem();
        break;
      case 'e' :
        break;
        default :
        cout << "Invalid input, please try again.\n";
      }
    }
    cout << "Thank you for playing!\n";
    return 0;
}
