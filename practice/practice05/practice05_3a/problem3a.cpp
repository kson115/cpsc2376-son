#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm> 
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

    std::cout << "Squared elements: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {std::cout << n * n << " ";});
    std::cout << std::endl;

    int squaredSum = std::accumulate(numbers.begin(), numbers.end(), 0, [](int total, int n) 
        {
        return total + (n * n);
        });

    std::cout << "Sum of all squared elements: " << squaredSum << std::endl;

    return 0;
}

