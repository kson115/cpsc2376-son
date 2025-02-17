
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

template <typename T>
T calculate(T firstNumber, T secondNumber, char operation) 
{
    switch (operation) 
    {
    case '+':
        return firstNumber + secondNumber;
    case '-':
        return firstNumber - secondNumber;
    case '*':
        return firstNumber * secondNumber;
    case '/':
        if (secondNumber != 0) 
        {
            return firstNumber / secondNumber;
        }
        else 
        {
            std::cerr << "Error: denominator == 0 is not allowed." << std::endl;
            return 0;  
        }
    default:
        std::cerr << "Error: Invalid operation." << std::endl;
        return 0;
    }
}

void calculatedResult(double result) 
{
    std::cout << std::fixed << std::setprecision(2) << "Result: " << result << std::endl;
}

int main() 
{
    std::string input;
    double firstNumber, secondNumber;
    char operation;

    while (true) 
    {
        std::cout << "Enter first number: ";
        std::getline(std::cin, input);
        std::stringstream(input) >> firstNumber;

        std::cout << "Enter second number: ";
        std::getline(std::cin, input);
        std::stringstream(input) >> secondNumber;

        std::cout << "Enter operation (+, -, *, /): ";
        std::cin >> operation;
        std::cin.ignore();

        if (input.find('.') != std::string::npos) 
        {
            double result = calculate(firstNumber, secondNumber, operation);
            calculatedResult(result);
        }
        else 
        {
            int intFirstNumber = static_cast<int>(firstNumber);
            int intSecondNumber = static_cast<int>(secondNumber);
            int result = calculate(intFirstNumber, intSecondNumber, operation);
            std::cout << "Result: " << result << std::endl;
        }

        char continueChoice;
        std::cout << "Do you want another calculation? (y/n): ";
        std::cin >> continueChoice;
        std::cin.ignore();

        if (continueChoice != 'y' && continueChoice != 'Y') 
        {
            break;
        }
    }
    return 0;
}

// This templated was created by Ai and modified
// Please comment out both problem1a.cpp and program3a.cpp, then run this program
