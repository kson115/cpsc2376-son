#include <iostream>
#include <vector>
#include <stdexcept>

// Enumeration for game state
enum class GameState 
{
    ONGOING,
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    DRAW
};

// Enumeration for game tokens
enum class GameToken 
{
    EMPTY,
    PLAYER_1,
    PLAYER_2
};

// Function prototypes
void printRules();
std::vector<std::vector<GameToken>> makeBoard(int size);
void printBoard(const std::vector<std::vector<GameToken>>& board);
bool play(std::vector<std::vector<GameToken>>& board, GameToken player);
GameState gameStatus(const std::vector<std::vector<GameToken>>& board);

// Main function
int main() 
{
    const int size = 5; // Setting the board size to 5x5
    auto board = makeBoard(size);
    bool playing = true;
    GameToken player = GameToken::PLAYER_1;
    GameState state = GameState::ONGOING;

    printRules();

    while (playing) 
    {
        board = makeBoard(size); // Reset the board for a new game
        while (state == GameState::ONGOING) 
        {
            printBoard(board);
            if (!play(board, player)) 
            {
                continue;
            }
            state = gameStatus(board);
            player = (player == GameToken::PLAYER_1) ? GameToken::PLAYER_2 : GameToken::PLAYER_1; // Switch player
        }

        printBoard(board);

        switch (state) 
        {
        case GameState::PLAYER_1_WINS:
            std::cout << "Player 1 wins!\n";
            break;
        case GameState::PLAYER_2_WINS:
            std::cout << "Player 2 wins!\n";
            break;
        case GameState::DRAW:
            std::cout << "It's a draw!\n";
            break;
        default:
            break;
        }

        std::cout << "Play again? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'n' || choice == 'N') 
        {
            playing = false;
        }
        else {
            state = GameState::ONGOING;
        }
    }

    return 0;
}

// Function to print game rules
void printRules() 
{
    std::cout << "Welcome to Gomoku!\n";
    std::cout << "Players take turns to place their marks (X for Player 1, O for Player 2) on the grid.\n";
    std::cout << "The first player to get five marks in a row (horizontally, vertically, or diagonally) wins.\n";
}

// Function to initialize the game board
std::vector<std::vector<GameToken>> makeBoard(int size) 
{
    return std::vector<std::vector<GameToken>>(size, std::vector<GameToken>(size, GameToken::EMPTY));
}

// Function to print the game board
void printBoard(const std::vector<std::vector<GameToken>>& board) 
{
    std::cout << "  ";
    for (int i = 0; i < board.size(); ++i) 
    {
        std::cout << i % 10 << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < board.size(); ++i) 
    {
        std::cout << i % 10 << " ";
        for (const auto& cell : board[i]) 
        {
            switch (cell) 
            {
            case GameToken::EMPTY:
                std::cout << ".";
                break;
            case GameToken::PLAYER_1:
                std::cout << "X";
                break;
            case GameToken::PLAYER_2:
                std::cout << "O";
                break;
            }
            std::cout << " ";
        }
        std::cout << '\n';
    }
}

// Function to handle player turns
bool play(std::vector<std::vector<GameToken>>& board, GameToken player) 
{
    int row, col;
    std::cout << "Player " << ((player == GameToken::PLAYER_1) ? 1 : 2) << ", enter your move (row and column): ";
    std::cin >> row >> col;

    if (std::cin.fail() || row < 0 || row >= board.size() || col < 0 || col >= board.size() || board[row][col] != GameToken::EMPTY) 
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid move. Try again.\n";
        return false;
    }

    board[row][col] = player;
    return true;
}

// Function to check the game status
GameState gameStatus(const std::vector<std::vector<GameToken>>& board) 
{
    const int WIN_CONDITION = 5;

    // Check rows, columns, and diagonals
    for (int i = 0; i < board.size(); ++i) 
    {
        for (int j = 0; j < board[i].size(); ++j) 
        {
            if (board[i][j] == GameToken::EMPTY) continue; // Skip EMPTY cells

            // Check horizontal
            if (j <= board.size() - WIN_CONDITION && board[i][j] != GameToken::EMPTY) 
            {
                bool win = true;
                for (int k = 1; k < WIN_CONDITION; ++k) 
                {
                    if (board[i][j] != board[i][j + k]) 
                    {
                        win = false;
                        break;
                    }
                }
                if (win) return (board[i][j] == GameToken::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
            }

            // Check vertical
            if (i <= board.size() - WIN_CONDITION && board[i][j] != GameToken::EMPTY) 
            {
                bool win = true;
                for (int k = 1; k < WIN_CONDITION; ++k) 
                {
                    if (board[i][j] != board[i + k][j]) 
                    {
                        win = false;
                        break;
                    }
                }
                if (win) return (board[i][j] == GameToken::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
            }

            // Check diagonal (down-right)
            if (i <= board.size() - WIN_CONDITION && j <= board.size() - WIN_CONDITION && board[i][j] != GameToken::EMPTY) 
            {
                bool win = true;
                for (int k = 1; k < WIN_CONDITION; ++k) 
                {
                    if (board[i][j] != board[i + k][j + k]) 
                    {
                        win = false;
                        break;
                    }
                }
                if (win) return (board[i][j] == GameToken::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
            }

            // Check diagonal (down-left)
            if (i <= board.size() - WIN_CONDITION && j >= WIN_CONDITION - 1 && board[i][j] != GameToken::EMPTY) 
            {
                bool win = true;
                for (int k = 1; k < WIN_CONDITION; ++k) 
                {
                    if (board[i][j] != board[i + k][j - k]) 
                    {
                        win = false;
                        break;
                    }
                }
                if (win) return (board[i][j] == GameToken::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
            }
        }
    }

    // Check for draw or ongoing game
    for (const auto& row : board) 
    {
        for (const auto& cell : row) 
        {
            if (cell == GameToken::EMPTY) 
            {
                return GameState::ONGOING;
            }
        }
    }
    return GameState::DRAW;
}
