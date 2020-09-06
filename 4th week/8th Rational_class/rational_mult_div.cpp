#include <iostream>
using namespace std;

int Lcm(int a, int b) {
    if (a == b && a != 0) {
        return a;
    }
    else if (a == 0) {
        return b;
    }
    else if (b == 0) {
        return a;
    }
    while (a != 0 && b != 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a + b;
}

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        int sign = 1;
        if (numerator < 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        else if (numerator < 0) {
            numerator *= -1;
            sign = -1;
        }
        else if (denominator < 0) {
            denominator *= -1;
            sign = -1;
        }
        int lcm = Lcm(numerator, denominator);
        p = (numerator * sign) / lcm;
        q = denominator / lcm;
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p;
    int q;
};

bool operator==(const Rational& first, const Rational& second) {
    if (first.Numerator() == second.Numerator()
        && first.Denominator() == second.Denominator())
        return true;
    return false;
}

Rational operator+(const Rational& first, const Rational& second) {
    Rational new_rational; 
    if (first.Denominator() == second.Denominator()) {
        Rational rational(first.Numerator() + second.Numerator(), first.Denominator());
        new_rational = rational;
    }
    else if (first.Denominator() % second.Denominator() == 0) {
        Rational rational(first.Numerator() + second.Numerator()
                              * (first.Denominator() / second.Denominator()), first.Denominator());
        new_rational = rational;
    }
    else if (second.Denominator() % first.Denominator() == 0) {
        Rational rational(first.Numerator() * (second.Denominator() / first.Denominator())
                              + second.Numerator(), second.Denominator());
        new_rational = rational;
    }
    else{
        Rational rational(first.Numerator() * second.Denominator() + second.Numerator()
                              * first.Denominator(), first.Denominator() * second.Denominator());
        new_rational = rational;
    }

    return new_rational;
}

Rational operator-(const Rational& first, const Rational& second) {
    Rational new_rational; 
    if (first.Denominator() == second.Denominator()) {
        Rational rational(first.Numerator() - second.Numerator(), first.Denominator());
        new_rational = rational;
    }
    else if (first.Denominator() % second.Denominator() == 0) {
        Rational rational(first.Numerator() - second.Numerator()
                              * (first.Denominator() / second.Denominator()), first.Denominator());
        new_rational = rational;
    }
    else if (second.Denominator() % first.Denominator() == 0) {
        Rational rational(first.Numerator() * (second.Denominator() / first.Denominator())
                              - second.Numerator(), second.Denominator());
        new_rational = rational;
    }
    else{
        Rational rational(first.Numerator() * second.Denominator() - second.Numerator()
                              * first.Denominator(), first.Denominator() * second.Denominator());
        new_rational = rational;
    }

    return new_rational;
}

Rational operator*(const Rational& first, const Rational& second) {
    Rational new_rational(first.Numerator() * second.Numerator(),
                        first.Denominator() * second.Denominator());

    return new_rational;
}

Rational operator/(const Rational& first, const Rational& second) {
    Rational new_rational(first.Numerator() * second.Denominator(),
                        first.Denominator() * second.Numerator());

    return new_rational;
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}