#include <iostream>
#include <string>

int main() 
{
    float redPotion{ 0.0f };    // Amount of red potion in mL
    float bluePotion{ 0.0f };   // Amount of blue potion in mL
    float* flask{ nullptr };    // Pointer to the selected potion

    std::string potionChoice;
    while (true) 
    {       
        std::cout << "Enter which potion ('Red' or 'Blue' or 'Done') to add liquid to?: ";
        std::cin >> potionChoice;
       
        if (potionChoice == "Red") 
        {
            flask = &redPotion;
        }
        else if (potionChoice == "Blue") 
        {
            flask = &bluePotion;
        }
        else if (potionChoice == "Done")
        {           
            std::cout << "It's done. Exit a fantasy lab." << std::endl;
            break;           
        }
        else
        {
            std::cout << "Invalid choice. Please choose 'Red', 'Blue', or 'Done'." << std::endl;
            continue;
        }
   
        float volumeToAdd;
        std::cout << "Enter how many milliliters to add? ";
        std::cin >> volumeToAdd;

        if (flask) 
        {
            *flask += volumeToAdd;
        }

        std::cout << "Potion Levels:" << std::endl;
        std::cout << "Red Potion: " << redPotion << " mL" << std::endl;
        std::cout << "Blue Potion: " << bluePotion << " mL" << std::endl;
    }
    return 0;
}
