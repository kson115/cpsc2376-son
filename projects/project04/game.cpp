#include "game.h"
#include <cstdlib>
#include <algorithm>

Game::Game(int rows, int cols, int winLength)
    : rows_(rows), cols_(cols), winLength_(winLength),
    currentPlayer(PLAYER_1), gameStatus(ONGOING) 
{
    board.resize(rows_, std::vector<Player>(cols_, NONE));
}

void Game::play(int col) 
{
    if (gameStatus != ONGOING) return;

    for (int row = rows_ - 1; row >= 0; --row) 
    {
        if (board[row][col] == NONE) 
        {
            board[row][col] = currentPlayer;
            checkForWinner(row, col);
            if (gameStatus == ONGOING)
                currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
            return;
        }
    }
}

void Game::aiMove() 
{
    if (gameStatus != ONGOING) return;
    for (int col = 0; col < cols_; ++col) 
    {
        for (int row = rows_ - 1; row >= 0; --row) 
        {
            if (board[row][col] == NONE) 
            {
                board[row][col] = PLAYER_2;
                checkForWinner(row, col);
                currentPlayer = PLAYER_1;
                return;
            }
        }
    }
}

void Game::checkForWinner(int lastRow, int lastCol) 
{
    if (checkLine(lastRow, lastCol, 0, 1) || checkLine(lastRow, lastCol, 1, 0) ||
        checkLine(lastRow, lastCol, 1, 1) || checkLine(lastRow, lastCol, 1, -1)) 
    {
        gameStatus = (currentPlayer == PLAYER_1) ? WIN_PLAYER_1 : WIN_PLAYER_2;
    }
    else if (isBoardFull()) 
    {
        gameStatus = DRAW;
    }
}

bool Game::checkLine(int startRow, int startCol, int dRow, int dCol) 
{
    int count = 0;
    Player player = board[startRow][startCol];
    for (int i = -winLength_ + 1; i < winLength_; ++i) 
    {
        int r = startRow + i * dRow;
        int c = startCol + i * dCol;
        if (r >= 0 && r < rows_ && c >= 0 && c < cols_ && board[r][c] == player) 
        {
            count++;
            if (count == winLength_) return true;
        }
        else 
        {
            count = 0;
        }
    }
    return false;
}

bool Game::isBoardFull() 
{
    for (int r = 0; r < rows_; ++r)
        for (int c = 0; c < cols_; ++c)
            if (board[r][c] == NONE) return false;
    return true;
}

void Game::draw(SDL_Renderer* renderer, int cellSize, int offsetX, int offsetY) {
    for (int row = 0; row < rows_; ++row) 
    {
        for (int col = 0; col < cols_; ++col) 
        {
            SDL_Rect cellRect = 
            {
                offsetX + col * cellSize,
                offsetY + row * cellSize,
                cellSize,
                cellSize
            };

            // Draw cell background
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue board
            SDL_RenderFillRect(renderer, &cellRect);

            // Draw token
            Player p = board[row][col];
            if (p != NONE) 
            {
                if (p == PLAYER_1)
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red
                else
                    SDL_SetRenderDrawColor(renderer, 0, 200, 255, 255);  // Cyan

                SDL_Rect tokenRect = 
                {
                    cellRect.x + 10,
                    cellRect.y + 10,
                    cellSize - 20,
                    cellSize - 20
                };
                SDL_RenderFillRect(renderer, &tokenRect);
            }

            // Draw border
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black border
            SDL_RenderDrawRect(renderer, &cellRect);
        }
    }
}

GameStatus Game::status() const 
{
    return gameStatus;
}

Player Game::getCurrentPlayer() const 
{
    return currentPlayer;
}
