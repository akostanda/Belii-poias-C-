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

bool operator<(const Rational& first, const Rational& second) {
    return (first - second).Numerator() < 0;
    // return (first.Numerator()/first.Denominator()) < (second.Numerator()/second.Denominator());
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
