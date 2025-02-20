#include <iostream>
#include <vector>
#include <stdexcept>

enum class GameToken { EMPTY, PLAYER_1, PLAYER_2 };
enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

void printRules();
std::vector<std::vector<GameToken>> makeBoard(int rows, int cols);
void printBoard(const std::vector<std::vector<GameToken>>& board);
bool play(std::vector<std::vector<GameToken>>& board, GameToken player);
GameState gameStatus(const std::vector<std::vector<GameToken>>& board);

int main()
{
    const int rows = 6;
    const int cols = 7;
    auto board = makeBoard(rows, cols);
    bool playing = true;
    GameToken player = GameToken::PLAYER_1;
    GameState state = GameState::ONGOING;

    printRules();

    while (playing)
    {
        board = makeBoard(rows, cols);
        while (state == GameState::ONGOING)
        {
            printBoard(board);
            if (!play(board, player))
            {
                continue;
            }

            if (player == GameToken::PLAYER_1)
            {
                player = GameToken::PLAYER_2;
            }
            else
            {
                player = GameToken::PLAYER_1;
            }
            state = gameStatus(board);
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
        std::cout << "Play again? Please enter 'y' for Yes or 'n' for No: ";
        char choice;
        std::cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            playing = false;
        }
        else 
        {
            state = GameState::ONGOING;
        }
    }
    return 0;
}

void printRules()
{
    std::cout << "Welcome to a turn-based, grid-based Connect Four game!\n";
    std::cout << "Two players take turns to place their marks (Player 1: O, Player 2: X) on the grid.\n";
    std::cout << "Winning needs four marks in a row (horizontally, vertically, or diagonally).\n";
}

std::vector<std::vector<GameToken>> makeBoard(int rows, int cols)
{
    return std::vector<std::vector<GameToken>>(rows, std::vector<GameToken>(cols, GameToken::EMPTY));
}

void printBoard(const std::vector<std::vector<GameToken>>& board)
{
    std::cout << "   ";
    for (int j = 1; j <= board[0].size(); ++j)
    {
        std::cout << j << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < board.size(); ++i)
    {
        std::cout << (i + 1) << " ";
        if (i + 1 < 10) std::cout << " "; 
        for (int j = 0; j < board[i].size(); ++j)
        {
            switch (board[i][j])
            {
            case GameToken::EMPTY:
                std::cout << ".";
                break;
            case GameToken::PLAYER_1:
                std::cout << "O";
                break;
            case GameToken::PLAYER_2:
                std::cout << "X";
                break;
            }
            std::cout << " ";
        }
        std::cout << '\n';
    }
}

bool play(std::vector<std::vector<GameToken>>& board, GameToken player)
{
    int row, col;
    if (player == GameToken::PLAYER_1)
    {
        std::cout << "Player 1, enter your row (1 to 6): ";
    }
    else
    {
        std::cout << "Player 2, enter your row (1 to 6): ";
    }
    std::cin >> row;
    std::cout << "Enter your column (1 to 7): ";
    std::cin >> col;

    row -= 1;
    col -= 1;

    if (std::cin.fail() || row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != GameToken::EMPTY)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Bad input. Try again.\n";
        return false;
    }

    board[row][col] = player;
    return true;
}

GameState gameStatus(const std::vector<std::vector<GameToken>>& board)
{
    const int WIN_NEED = 5;
    const int rows = board.size();
    const int cols = board[0].size();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (board[i][j] == GameToken::EMPTY) continue;

            if (j <= cols - WIN_NEED && board[i][j] != GameToken::EMPTY)
            {
                bool win = true;
                for (int k = 1; k < WIN_NEED; ++k)
                {
                    if (board[i][j] != board[i][j + k]) //horizontal move (left-right;right-left)
                    {
                        win = false;
                        break;
                    }
                }
                if (win)
                {
                    if (board[i][j] == GameToken::PLAYER_1)
                    {
                        return GameState::PLAYER_1_WINS;
                    }
                    else
                    {
                        return GameState::PLAYER_2_WINS;
                    }                                       
                }
            }

            if (i <= rows - WIN_NEED && board[i][j] != GameToken::EMPTY)
            {
                bool win = true;
                for (int k = 1; k < WIN_NEED; ++k)
                {
                    if (board[i][j] != board[i + k][j]) //vertical move (top-bottom;bottom-top)
                    {
                        win = false;
                        break;
                    }
                }
                if (win)
                {
                    return (board[i][j] == GameToken::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
                }
            }

            if (i <= rows - WIN_NEED && j <= cols - WIN_NEED && board[i][j] != GameToken::EMPTY)
            {
                bool win = true;
                for (int k = 1; k < WIN_NEED; ++k)
                {
                    if (board[i][j] != board[i + k][j + k]) //diagonal move (down-right;up-right)
                    {
                        win = false;
                        break;
                    }
                }
                if (win)
                {
                    return (board[i][j] == GameToken::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
                }
            }

            if (i <= rows - WIN_NEED && j >= WIN_NEED - 1 && board[i][j] != GameToken::EMPTY)
            {
                bool win = true;
                for (int k = 1; k < WIN_NEED; ++k)
                {
                    if (board[i][j] != board[i + k][j - k]) //diagonal move (downn-left;up-left)
                    {
                        win = false;
                        break;
                    }
                }
                if (win)
                {
                    return (board[i][j] == GameToken::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
                }
            }
        }
    }

    for (const auto& row : board)
    {
        for (const auto& elem : row)
        {
            if (elem == GameToken::EMPTY)
            {
                return GameState::ONGOING;
            }
        }
    }
    return GameState::DRAW;
}

// This is a lecture-based Gomoku game template modified with Ai-created gameStatus function, 
// Then modified again to a Connect Four game.
