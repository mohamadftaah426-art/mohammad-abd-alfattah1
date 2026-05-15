#include <iostream>
#include <cmath>

class Fraction {
    int num, den;
    
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    void simplify() {
        int g = gcd(std::abs(num), std::abs(den));
        num /= g;
        den /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }
    
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
        simplify();
    }
    
    Fraction operator+(const Fraction& o) const {
        return Fraction(num * o.den + o.num * den, den * o.den);
    }
    
    Fraction operator-(const Fraction& o) const {
        return Fraction(num * o.den - o.num * den, den * o.den);
    }
    
    Fraction operator*(const Fraction& o) const {
        return Fraction(num * o.num, den * o.den);
    }
    
    Fraction operator/(const Fraction& o) const {
        if (o.num == 0) throw std::invalid_argument("Division by zero");
        return Fraction(num * o.den, den * o.num);
    }
    
    bool operator==(const Fraction& o) const {
        return num == o.num && den == o.den;
    }
    
    bool operator<(const Fraction& o) const {
        return num * o.den < o.num * den;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.num;
        if (f.den != 1) os << "/" << f.den;
        return os;
    }
};

int main() {
    Fraction a(3, 4), b(1, 2);
    
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " < " << b << " ? " << (a < b ? "Yes" : "No") << std::endl;
    
    return 0;
}
