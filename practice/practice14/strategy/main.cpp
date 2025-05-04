#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

class TextFilter 
{
public:
    virtual std::string applyFilter(const std::string& text) = 0;
    virtual ~TextFilter() = default;
};

class ReverseFilter : public TextFilter 
{
public:
    std::string applyFilter(const std::string& text) override 
    {
        std::string reversed = text;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }
};

class UppercaseFilter : public TextFilter 
{
public:
    std::string applyFilter(const std::string& text) override 
    {
        std::string upper = text;
        std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
        return upper;
    }
};

// Allow the user to select and apply filters dynamically
int main() 
{
    std::unique_ptr<TextFilter> filter;
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    filter = std::make_unique<ReverseFilter>();
    std::cout << "Reversed: " << filter->applyFilter(input) << std::endl;

    filter = std::make_unique<UppercaseFilter>();
    std::cout << "Uppercase: " << filter->applyFilter(input) << std::endl;
    return 0;
}

//AI-generated template