#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <numeric> 

int main() 
{
    std::vector<int> numbers;
    std::string line;
    int num;

    std::cout << "Enter integers separated by spaces: ";
    std::getline(std::cin, line);
    std::istringstream stream(line);

    while (stream >> num) 
    {
        numbers.push_back(num); 
    }

    std::cout << "You entered: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    int product = 1;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) 
    {
        product *= *it;
    }

    std::cout << "Sum of all elements: " << sum << std::endl;
    std::cout << "Product of all elements: " << product << std::endl;

    return 0;
}

// modified and verified by Ai
