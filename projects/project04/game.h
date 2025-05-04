#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL2/SDL.h>

enum GameStatus {
    ONGOING,
    DRAW,
    WIN_PLAYER_1,
    WIN_PLAYER_2
};

enum Player {
    NONE = 0,
    PLAYER_1,
    PLAYER_2
};

class Game {
public:
    Game(int rows, int cols, int winLength);
    void play(int col);
    void aiMove();
    void draw(SDL_Renderer* renderer, int cellSize, int offsetX, int offsetY);
    GameStatus status() const;
    int getCols() const;
    int getRows() const;
    Player getCurrentPlayer() const;

private:
    int rows_, cols_, winLength_;
    std::vector<std::vector<Player>> board;
    Player currentPlayer;
    GameStatus gameStatus;

    void checkForWinner(int lastRow, int lastCol);
    bool checkLine(int startRow, int startCol, int dRow, int dCol);
    bool isBoardFull();
};

#endif
