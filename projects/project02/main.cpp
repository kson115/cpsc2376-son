#include <iostream>
#include <string>
#include <thread> 
#include <chrono> 
#include "game.h"

int main()
{
    int rows, cols, WIN_NEED;
    std::string input;
    int column;

    std::cout << "Welcome to an Object-Oriented Turn-Based Grid Connect-Four Game with \n"
              << "Color Tokens/Board, Configured Settings, and an AI Opponent!: "
              << "Player 1 (Red) plays against AI (Blue).\n";

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
    std::cout << "Enter the number of tokens required to win: ";
    std::cin >> WIN_NEED;

    Game game(rows, cols, WIN_NEED); 

    std::cout << "Player 1 (human, Red) will play against Player 2 (AI, Blue).\n";
    std::cout << "Type 'q' to quit the game at any time.\n";

    while (game.status() == ONGOING)
    {
        std::cout << game;

        if (game.getCurrentPlayer() == PLAYER_1)
        {
            std::cout << "Player 1 (Red), it's your turn.\n";
            std::cout << "Enter column (1-" << game.getCols() << "): ";
            std::cin >> input;

            if (input == "q" || input == "Q")
            {
                std::cout << "Exiting the game. Thanks for playing!" << std::endl;
                return 0;
            }

            try
            {
                column = std::stoi(input);
            }
            catch (const std::invalid_argument&)
            {
                std::cout << "Invalid input! Please enter a number between 1 and " 
                          << game.getCols() << ".\n";
                continue;
            }

            if (column < 1 || column > game.getCols())
            {
                std::cout << "Invalid column! Please choose a valid column.\n";
                continue;
            }
            game.play(column - 1); 
        }
        else
        {        
            std::cout << "AI (Blue), it's your turn.\n";
            std::this_thread::sleep_for(std::chrono::seconds(3)); 
            game.aiMove();  
        }
    }

    std::cout << game;

    switch (game.status())
    {
    case PLAYER_1_WINS:
        std::cout << "Player 1 wins!" << std::endl;
        break;
    case PLAYER_2_WINS:
        std::cout << "AI (Blue) wins!" << std::endl;
        break;
    case DRAW:
        std::cout << "It's a draw!" << std::endl;
        break;
    default:
        break;
    }
    return 0;
}

// Ai-created template with modification
