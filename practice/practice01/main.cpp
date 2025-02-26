#include <iostream>
#include "../../practice/practice03/mathyStuff.cpp"

int main()
{
    std::cout << "add 2+3: " << add(2, 3) << "\n";
    std::cout << "double 5: " << doubleValue(5) << "\n";
    Rectangle r{ 3,4 };
    std::cout << "get area of 3 x 4 rectangle: " << r.area() << "\n";
}