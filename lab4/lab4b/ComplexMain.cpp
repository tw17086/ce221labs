#include <iostream>

using namespace std;

#include "Complex.h"

int main(){
  Complex x, y(4.3, 8.2), z(3.3, 1.1);

  cout << "x: ";
  x.print();
  cout << endl << "y: ";
  y.print();
  cout << endl << "z: ";
  z.print();

  x = y+z;

  cout << endl << endl << "x = y+z: ";
  x.print();
  cout << " = ";
  y.print();
  cout << " + ";
  z.print();

  x = y-z;

  cout << endl << endl << "x = y-z: ";
  x.print();
  cout << " = ";
  y.print();
  cout << " - ";
  z.print();
  cout << endl;
}

