#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

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
        if (denominator == 0)
            throw invalid_argument("Invalid argument");
        else if (numerator < 0 && denominator < 0) {
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
    if (first.Denominator() == 0 || second.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    Rational new_rational(first.Numerator() * second.Denominator(),
                        first.Denominator() * second.Numerator());

    return new_rational;
}

ostream& operator<<(ostream& stream, const Rational& first) {
    // if (abs(first.Numerator()) != abs(first.Denominator()))
        stream << first.Numerator() << "/" << first.Denominator();
    // else
    //     stream << first.Numerator() / first.Denominator();
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

bool operator<(const Rational& first, const Rational& second) {
    return (first - second).Numerator() < 0;
}

int main() {
    string oprtr;
    string fruction1;
    string fruction2;

    cin >> fruction1 >> oprtr >> fruction2;
    try {
        istringstream input(fruction1);
        Rational r1;
        input >> r1;
        istringstream input2(fruction2);
        Rational r2;
        input2 >> r2;
        if (oprtr == "*")
            cout << r1 * r2 << endl;
        else if (oprtr == "/")
            cout << r1 / r2 << endl;
        else if (oprtr == "+")
            cout << r1 + r2 << endl;
        else if (oprtr == "-")
            cout << r1 - r2 << endl;
    } 
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
    catch (domain_error& e1) {
        cout << e1.what() << endl;
    }
    return 0;
}
