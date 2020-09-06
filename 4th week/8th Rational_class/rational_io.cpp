#include <iostream>
#include <sstream>

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

ostream& operator<<(ostream& stream, const Rational& first) {
    stream << first.Numerator() << "/" << first.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& first) {
    int numerator;
    int denominator;
    char divider;

    if (stream) {
        stream >> numerator >> divider >> denominator;
        if (stream && divider == '/') {
            Rational second(numerator, denominator);
            first = second;
        }
    }
    return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
