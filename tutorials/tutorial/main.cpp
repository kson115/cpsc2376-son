#include <iostream>
#include <array>
#include <algorithm>

int main() 
{
    std::array<int, 3>array{ 1, 2, 3 };

    // This does exactly the same as the loop we used before.
    for (int i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}