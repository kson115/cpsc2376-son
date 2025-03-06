#include "Fraction.h"
#include <stdexcept>
#include <numeric>

Fraction::Fraction() : num(0), den(1) {}
Fraction::Fraction(int n, int d) : num(n), den(d)
{
    if (d == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    simplify();
}

void Fraction::simplify()
{
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");
    int gcd = std::gcd(num, den);
    num /= gcd;
    den /= gcd;
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}
int Fraction::getNumerator() const
{
    return num;
}

int Fraction::getDenominator() const
{
    return den;
}

void Fraction::setNumerator(int n)
{
    num = n;
    simplify();
}

void Fraction::setDenominator(int d)
{
    if (d == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    den = d;
    simplify();
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
    int n = lhs.num * rhs.den + rhs.num * lhs.den;
    int d = lhs.den * rhs.den;
    return Fraction(n, d);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
    int n = lhs.num * rhs.den - rhs.num * lhs.den;
    int d = lhs.den * rhs.den;
    return Fraction(n, d);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
    int n = lhs.num * rhs.num;
    int d = lhs.den * rhs.den;
    return Fraction(n, d);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
    if (rhs.num == 0)
    {
        throw std::invalid_argument("Division by zero not allowed.");
    }
    int n = lhs.num * rhs.den;
    int d = lhs.den * rhs.num;
    return Fraction(n, d);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
    os << fraction.num << '/' << fraction.den;
    return os;
}
