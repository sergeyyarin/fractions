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
    if (denominator == term.denominator)
        return Fraction(numerator + term.numerator, denominator);

    const auto lcm = std::lcm(denominator, term.denominator);

    const auto expand_fraction = [&](Fraction f) -> int {
        return f.numerator * (lcm / f.denominator);
    };

    return Fraction(expand_fraction(*this) + expand_fraction(term), lcm);
}
Fraction Fraction::operator-(const Fraction &subtrahend) const {
    return *this + (subtrahend * Fraction(-1));
}
Fraction Fraction::operator*(const Fraction &factor) const {
    return Fraction(numerator * factor.numerator, denominator * factor.denominator);
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
