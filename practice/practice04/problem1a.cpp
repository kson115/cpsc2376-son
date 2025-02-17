
#include <iostream>
#include <iomanip>

double convertTemperature(double temp, char scale = 'F') 
{
    if (scale == 'F') 
    {
        return (temp * 9.0 / 5.0) + 32;  
    }
    else if (scale == 'C') 
    {
        return (temp - 32) * 5.0 / 9.0;  
    }
    return temp;  
}

void menu() 
{
    std::cout << "1. Convert Celsius to Fahrenheit" << std::endl;
    std::cout << "2. Convert Fahrenheit to Celsius" << std::endl;
}

int main() 
{
    int choice;
    double temperature, convertedTemperature;
    char scale;

    while (true) 
    {
        menu();
        std::cout << "Please choose 1 or 2: ";
        std::cin >> choice;

        if (choice == 1) 
        {
            scale = 'F';
            std::cout << "Enter temperature in Celsius: ";
        }
        else if (choice == 2) 
        {
            scale = 'C';
            std::cout << "Enter temperature in Fahrenheit: ";
        }
        else 
        {
            std::cout << "Invalid choice. Please choose 1 or 2." << std::endl;
            continue;
        }

        std::cin >> temperature;
        convertedTemperature = convertTemperature(temperature, scale);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Converted: " << convertedTemperature << (scale == 'F' ? "°F" : "°C") << std::endl;

        char continueChoice;
        std::cout << "Do you want another conversion? (y/n): ";
        std::cin >> continueChoice;

        if (continueChoice != 'y' && continueChoice != 'Y') 
        {
            break;
        }
    }

    return 0;
}

// This templated was created by Ai and modified
// Please comment out both problem2a.cpp and program3a.cpp, then run this program