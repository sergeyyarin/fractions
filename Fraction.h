//
// Created by sergey on 8/23/21.
//

#ifndef FRACTIONS_FRACTION_H
#define FRACTIONS_FRACTION_H
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

class Fraction {
    int numerator{};
    int denominator{};

public:
    Fraction();
    explicit Fraction(int, int);
    Fraction operator+(const Fraction &) const;
    Fraction operator-(const Fraction &) const;
    Fraction operator*(const Fraction &) const;
    Fraction operator/(const Fraction &) const;
    [[nodiscard]] std::string to_string() const;
    [[nodiscard]] double to_decimal() const;
};

Fraction::Fraction() {
    numerator = 1;
    denominator = 1;
}
Fraction::Fraction(int a, int b = 1) {
    numerator = a;
    denominator = b;
}
Fraction Fraction::operator+(const Fraction &term) const {
    Fraction ret;
    if (denominator == term.denominator) {
        ret.numerator = numerator + term.numerator;
        ret.denominator = denominator;
        return ret;
    }
    return {};
}
Fraction Fraction::operator-(const Fraction &subtrahend) const {
    Fraction ret;
    if (denominator == subtrahend.denominator) {
        ret.numerator = numerator - subtrahend.numerator;
        ret.denominator = denominator;
        return ret;
    }
    return {};
}
Fraction Fraction::operator*(const Fraction &factor) const {
    return {};
}
Fraction Fraction::operator/(const Fraction &divider) const {
    return {};
}
std::string Fraction::to_string() const {
    std::ostringstream strm;
    strm << numerator;
    if (denominator > 1)
        strm << '/' << denominator;
    return strm.str();
}
double Fraction::to_decimal() const {
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}
#endif//FRACTIONS_FRACTION_H
