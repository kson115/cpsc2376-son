#pragma once

#include <vector>
#include <iostream>

enum GameToken { EMPTY, PLAYER_1, PLAYER_2 };
enum GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

class Game
{
public:
    Game(int r = 6, int c = 7, int win = 5); 
    void play(int col);
    GameState status() const;
    GameToken getCurrentPlayer() const;  
    int getCols() const;  
    int getRows() const;  
    void aiMove();  
    friend std::ostream& operator<<(std::ostream& os, const Game& game);  
    
private:
    std::vector<std::vector<GameToken>> board;
    GameToken currentPlayer;
    GameState gameState;
    const int rows, cols;
    int WIN_NEED;

    bool isBoardFull() const;
    bool checkWin(int row, int col); 
};
