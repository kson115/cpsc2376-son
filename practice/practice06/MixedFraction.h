#pragma once

#include "Fraction.h"
#include <iostream>

class MixedFraction : public Fraction
{
private:
    int whole;  
    void extractWholePart();  

public:
    MixedFraction(int w, int n, int d);
    MixedFraction(const Fraction& fraction);

    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction);
};
