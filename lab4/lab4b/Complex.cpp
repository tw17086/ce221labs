using namespace std;

#include <iostream>
#include "Complex.h"

Complex::Complex(double r, double i) : real(r), imaginary(i) {}

Complex Complex::operator+(const Complex &op2) const{
    return Complex(real + op2.real, imaginary + op2.imaginary);
}

Complex Complex::operator-(const Complex &op2) const{
    return Complex(real - op2.real, imaginary - op2.imaginary);
}

Complex Complex::operator*(const Complex &op2) const{
    return Complex(real * op2.real - imaginary * op2.imaginary, op2.real * imaginary + real * op2.imaginary);
}

bool Complex::operator==(const Complex &op2) const{
    return real==op2.real && imaginary==op2.imaginary;
}
bool Complex::operator!=(const Complex &op2) const{
    return !(real==op2.real && imaginary==op2.imaginary);
}

// display a complex in the form ([r] + [i]i)
ostream &operator<<(ostream &o, const Complex &cmplx){
    o << cmplx.real << " + " << cmplx.imaginary << "i";
    return o;
}



int main(){
  Complex x, y(4.3, 8.2), z(3.3, 1.1);

  cout << "x: " << x;

  cout << endl << "y: " << y;
  cout << endl << "z: " << z;

  x = y+z;

  cout << endl << endl << "x = y+z: " << x << " = " << y << " + " << z;

  x = y-z;

  cout << endl << endl << "x = y-z: " << x << " = " << y << " - " << z;
  cout << endl;

  x = y*z;

  cout << endl << endl << "x = y*z: " << x << " = " << y << " * " << z;
  cout << endl;

  Complex w(x);

  cout << endl << endl << "x == w: " << x << " == " << w << " : " <<(x == w) << endl;
  cout << endl << endl << "x == y: " << x << " == " << y << " : " <<(x == y) << endl;
  cout << endl << endl << "x != z: " << x << " != " << z << " : " <<(x == z) << endl;
}
