#include "MixedFraction.h"
#include <stdexcept>
#include <iostream>

MixedFraction::MixedFraction(int w, int n, int d) : Fraction(n, d), whole(w)
{
    extractWholePart();  
}

MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction), whole(0)
{
    extractWholePart();  
}

void MixedFraction::extractWholePart()
{
    if (getDenominator() != 0)
    {
        whole += getNumerator() / getDenominator();  
        setNumerator(getNumerator() % getDenominator());  
    }
    else
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
}

std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction)
{
    os << mixedFraction.whole;  
    if (mixedFraction.getNumerator() != 0)  
    {
        os << " " << mixedFraction.getNumerator() << "/" << mixedFraction.getDenominator();
    }
    return os;
}
