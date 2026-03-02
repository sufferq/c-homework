#include <iostream>
using namespace std;

class Fraction {
private:
    int num;  
    int den;  

    
    void simplify() {
        if (den == 0) 
            return;

        
        int a = num, b = den;

        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }

        num /= a;
        den /= a;

        
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    
    Fraction(const Fraction& other) {
        num = other.num;
        den = other.den;
    }

    
    Fraction& operator=(const Fraction& other) {
        if (this != &other) {
            num = other.num;
            den = other.den;
        }
        return *this;
    }

    
    double toDouble() {
        return (double)num / den;
    }

    
    Fraction operator+(Fraction f) {
        return Fraction(num * f.den + f.num * den, den * f.den);
    }

    Fraction operator-(Fraction f) {
        return Fraction(num * f.den - f.num * den, den * f.den);
    }

    Fraction operator*(Fraction f) {
        return Fraction(num * f.num, den * f.den);
    }

    Fraction operator/(Fraction f) {
        return Fraction(num * f.den, den * f.num);
    }

    
    bool operator==(Fraction f) {
        return num * f.den == f.num * den;
    }

    bool operator<(Fraction f) {
        return num * f.den < f.num * den;
    }

    
    void show() {
        if (den == 1)
            cout << num;
        else
            cout << num << "/" << den;
    }
};


int main() {
    Fraction a(1, 2);  
    Fraction b(2, 3);  
    Fraction c;         

    Fraction d = a;     


    c = b;             

    
    Fraction sum = a + b;
    Fraction mul = a * 2;


    
    cout << "a = ";
    a.show();
    cout << "\n";

    cout << "b = ";
    b.show();
    cout << "\n";

    cout << "sum = ";
    sum.show();
    cout << "\n";

    return 0;
}