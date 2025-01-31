#include <iostream>
#include <vector>

// Function to print the vector
void printVector(const std::vector<int>& numbers) 
{
    for (int i = 0; i < numbers.size(); i++) 
    {
        std::cout << numbers.at(i) << " ";
    }
}

// Function to double the vector
void doubleVector(std::vector<int>& numbers)
{
    for (int i = 0; i < numbers.size();i++)
    {       
        std::cout << numbers.at(i)*2 << " ";
    }
}

// Function to calculate the sum of a vector
int calculateSum(const std::vector<int>& numbers) 
{
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) 
    {
        sum += numbers.at(i);
    }
    return sum;
}

// Function to print multiples of a user-defined value
void printMultiples(const std::vector<int>& numbers, int value) 
{
    for (int i = 0; i < numbers.size(); i++) 
    {
        if (numbers.at(i) % value == 0) 
        {
            std::cout << numbers.at(i) << " ";
        }
    }
}

int main() 
{
    std::vector<int> numbers = { 10, 20, 30, 40, 50 };
    int input, num, value;
    int sum = calculateSum(numbers);

    while (true) 
    {
        std::cout << "Menu options:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Calculate the sum\n";
        std::cout << "5. Print multiples of a user-defined value\n";
        std::cout << "6. Exit\n";

        std::cout << "Enter a number from the Menu options (1 to 6): ";
        std::cin >> input;

        switch (input)
        {
        case 1:
            std::cout << "Enter an element to add: ";
            std::cin >> num;
            numbers.push_back(num);
            numbers.push_back(num);
            numbers.push_back(num);
            std::cout << "Vector size after adding elements: " << numbers.size() << std::endl;           
            std::cout << std::endl;
            break;
        case 2:
            printVector(numbers);
            std::cout << std::endl;
            break;
        case 3:
            doubleVector(numbers);
            std::cout << std::endl;
            break;
        case 4:            
            std::cout << "Sum: " << sum << std::endl;
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "Enter a value to find multiples of: ";
            std::cin >> value;
            printMultiples(numbers, value);
            std::cout << std::endl;
            break;
        case 6:
            std::cout << "Exit" << std::endl;
            return 0;

        }
        
    }
}







