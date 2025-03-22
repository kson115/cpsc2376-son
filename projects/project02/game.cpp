#include "game.h"
#include <utility>

Game::Game(int r, int c, int win)
    : rows(r), cols(c), WIN_NEED(win), board(r, std::vector<GameToken>(c, EMPTY)),
    currentPlayer(PLAYER_1), gameState(ONGOING) {}

GameToken Game::getCurrentPlayer() const
{
    return currentPlayer;
}

int Game::getCols() const
{
    return cols;
}

int Game::getRows() const
{
    return rows;
}

void Game::play(int col)
{
    if (col < 0 || col >= cols || gameState != ONGOING)
    {
        return; 
    }

    for (int row = 0; row < rows; ++row)
    {
        if (board[row][col] == EMPTY)
        {
            board[row][col] = currentPlayer;
            if (checkWin(row, col))
            {
                gameState = (currentPlayer == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
            else if (isBoardFull())
            {
                gameState = DRAW;
            }
            else
            {
                currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;  // Switch turn
            }
            return;
        }
    }
    std::cout << "Column " << (col + 1) << " is full. Please choose another column." << std::endl;
}

GameState Game::status() const
{
    return gameState;
}

bool Game::isBoardFull() const
{
    for (const auto& row : board)
    {
        for (const auto& cell : row)
        {
            if (cell == EMPTY) return false;
        }
    }
    return true;
}

bool Game::checkWin(int row, int col)
{
    GameToken token = board[row][col];
    std::vector<std::pair<int, int>> directions = { {0, 1},{1, 0},{1, 1},{1, -1} };

    for (const auto& dir : directions)
    {
        int count = 1; 
        for (int step = 1; step < WIN_NEED; ++step)
        {
            int r = row + step * dir.first;
            int c = col + step * dir.second;

            if (r >= 0 && r < rows && c >= 0 && c < cols && board[r][c] == token)
            {
                count++;
            }
            else
            {
                break; 
            }
        }

        for (int step = 1; step < WIN_NEED; ++step)
        {
            int r = row - step * dir.first;
            int c = col - step * dir.second;

            if (r >= 0 && r < rows && c >= 0 && c < cols && board[r][c] == token)
            {
                count++;
            }
            else
            {
                break; 
            }
        }

        if (count >= WIN_NEED)
        {
            return true; 
        }
    }
    return false; 
}

void Game::aiMove()
{
    int column;
    while (true)
    {
        column = rand() % cols;  
        for (int row = 0; row < rows; ++row)
        {
            if (board[row][column] == EMPTY)
            {
                play(column);  
                std::cout << "AI (Blue) plays in column " << (column + 1) << "\n";
                return;
            }
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Game& game)
{
    os << "   ";
    for (int j = 0; j < game.getCols(); ++j)
    {
        os << (j + 1) << " ";        
    }
    os << "\n";

    for (int i = 0; i < game.getRows(); ++i)
    {
        os << (i + 1) << " ";
        if (i + 1 < 10) os << " ";
        for (int j = 0; j < game.getCols(); ++j)
        {
            os << "\033[48;5;226m";  
            switch (game.board[i][j])
            {
            case EMPTY:
                os << "\033[37m. "; 
                break;
            case PLAYER_1:
                os << "\033[31mO "; 
                break;
            case PLAYER_2:
                os << "\033[34mX "; 
                break;
            }
        }
        os << "\033[0m\n";  
    }
    os << "\033[0m";  
    return os;
}
