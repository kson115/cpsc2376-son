#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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

    int evenSum = 0;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) 
    {
        if (*it % 2 == 0) 
        {
            evenSum += *it;
        }
    }
   
    std::cout << "Sum of even numbers: " << evenSum << std::endl;

    return 0;
}
