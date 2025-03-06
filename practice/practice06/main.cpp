#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

void menu()
{
    std::cout << "Options:\n";
    std::cout << "1. Enter a fraction manually\n";
    std::cout << "2. Add a fraction\n";
    std::cout << "3. Subtract a fraction\n";
    std::cout << "4. Multiply by a fraction\n";
    std::cout << "5. Divide by a fraction\n";
    std::cout << "6. Display as Mixed Fraction\n";
    std::cout << "7. Clear Fraction\n";
    std::cout << "8. Exit\n";
}

Fraction getIntegerFromUser()
{
    int numerator, denominator;
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;
    return Fraction(numerator, denominator);
}

int main()
{
    Fraction currentFraction;

    while (true)
    {
        std::cout << "Current Fraction: " << currentFraction << "\n";
        menu();

        int choice;
        std::cout << "Choose an option: ";
        std::cin >> choice;

        /*
        try
        {
            Fraction f1(5, 6);
            std::cout << "Fraction: " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;

            f1.setNumerator(7);
            std::cout << "After setting numerator to 7: " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;

            f1.setDenominator(12);
            std::cout << "After setting denominator to 12: " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;

            Fraction f2;
            std::cout << "Default fraction: " << f2.getNumerator() << "/" << f2.getDenominator() << std::endl;

            Fraction f1(3, 4);
            Fraction f2(2, 5);

            Fraction add = f1 + f2;
            Fraction sub = f1 - f2;
            Fraction mul = f1 * f2;
            Fraction div = f1 / f2;

            std::cout << "f1: " << f1 << std::endl;
            std::cout << "f2: " << f2 << std::endl;
            std::cout << "f1 + f2: " << add << std::endl;
            std::cout << "f1 - f2: " << sub << std::endl;
            std::cout << "f1 * f2: " << mul << std::endl;
            std::cout << "f1 / f2: " << div << std::endl;

            Fraction f1(7, 2);
            MixedFraction mf1(f1);
            MixedFraction mf2(3, 4, 2);

            std::cout << "Fraction f1: " << f1 << std::endl;
            std::cout << "MixedFraction mf1: " << mf1 << std::endl;
            std::cout << "MixedFraction mf2: " << mf2 << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        */

        try
        {
            switch (choice)
            {
            case 1:
                currentFraction = getIntegerFromUser();
                break;
            case 2:
            {
                Fraction fraction = getIntegerFromUser();
                currentFraction = currentFraction + fraction;
                break;
            }
            case 3:
            {
                Fraction fraction = getIntegerFromUser();
                currentFraction = currentFraction - fraction;
                break;
            }
            case 4:
            {
                Fraction fraction = getIntegerFromUser();
                currentFraction = currentFraction * fraction;
                break;
            }
            case 5:
            {
                Fraction fraction = getIntegerFromUser();
                currentFraction = currentFraction / fraction;
                break;
            }
            case 6:
            {
                MixedFraction mixedFraction(currentFraction);
                std::cout << "Mixed Fraction: " << mixedFraction << "\n";
                break;
            }
            case 7:
                currentFraction = Fraction();
                break;
            case 8:
                std::cout << "Exit\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}
