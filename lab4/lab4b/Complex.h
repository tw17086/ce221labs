#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex
{   public:
        Complex(double = 0.0, double = 0.0);
        Complex operator+(const Complex &) const;
        Complex operator-(const Complex &) const;
        Complex operator*(const Complex &) const;
        bool operator==(const Complex &) const;
        bool operator!=(const Complex &) const;
        void print() const;
    private:
        double real;
        double imaginary;
     friend ostream& operator<<(ostream&, const Complex&);
};
#endif

