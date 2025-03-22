#include <iostream>
#include <vector>
#include <limits>
#include <string>

enum GameToken { EMPTY, PLAYER_1, PLAYER_2 };
enum GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

// Board size (3x3 grid of boxes means 4x4 grid of dots)
const int SIZE = 4;  // Number of dots along each edge of the grid

class DotsAndBoxes {
public:
    DotsAndBoxes(int size = SIZE);
    void play(int row, int col, char direction); // Play a move
    GameState status() const;
    void printBoard() const; // Print the current board state

private:
    std::vector<std::vector<GameToken>> grid;
    std::vector<std::vector<bool>> horizontalEdges; // Track horizontal edges
    std::vector<std::vector<bool>> verticalEdges; // Track vertical edges
    GameToken currentPlayer;
    GameState gameState;
    int player1Boxes;
    int player2Boxes;
    const int size;

    bool isValidMove(int row, int col, char direction) const;
    bool checkBoxCompletion(int row, int col, char direction);
    bool isBoardFull() const;
};

DotsAndBoxes::DotsAndBoxes(int size) : size(size), currentPlayer(PLAYER_1), gameState(ONGOING),
player1Boxes(0), player2Boxes(0),
grid(size - 1, std::vector<GameToken>(size - 1, EMPTY)),
horizontalEdges(size, std::vector<bool>(size - 1, false)),
verticalEdges(size - 1, std::vector<bool>(size, false)) {
}

void DotsAndBoxes::play(int row, int col, char direction) {
    if (!isValidMove(row, col, direction)) {
        std::cout << "Invalid move! Try again.\n";
        return;
    }

    if (direction == 'h') {
        horizontalEdges[row][col] = true;
    }
    else if (direction == 'v') {
        verticalEdges[row][col] = true;
    }

    if (checkBoxCompletion(row, col, direction)) {
        if (currentPlayer == PLAYER_1) {
            player1Boxes++;
        }
        else {
            player2Boxes++;
        }
    }

    if (isBoardFull()) {
        gameState = (player1Boxes > player2Boxes) ? PLAYER_1_WINS : (player2Boxes > player1Boxes) ? PLAYER_2_WINS : DRAW;
    }
    else {
        currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
    }
}

bool DotsAndBoxes::isValidMove(int row, int col, char direction) const {
    if (direction == 'h') {
        return (row >= 0 && row < size - 1 && col >= 0 && col < size - 1 && !horizontalEdges[row][col]);
    }
    else if (direction == 'v') {
        return (row >= 0 && row < size - 1 && col >= 0 && col < size && !verticalEdges[row][col]);
    }
    return false;
}

bool DotsAndBoxes::checkBoxCompletion(int row, int col, char direction) {
    if (direction == 'h') {
        // Check if horizontal edge completes any box
        if (row > 0 && horizontalEdges[row - 1][col] && verticalEdges[row - 1][col] && verticalEdges[row][col]) {
            grid[row - 1][col] = currentPlayer;
            return true;
        }
        if (row < size - 1 && horizontalEdges[row + 1][col] && verticalEdges[row][col] && verticalEdges[row + 1][col]) {
            grid[row][col] = currentPlayer;
            return true;
        }
    }
    else if (direction == 'v') {
        // Check if vertical edge completes any box
        if (col > 0 && verticalEdges[row][col - 1] && horizontalEdges[row][col - 1] && horizontalEdges[row][col]) {
            grid[row][col - 1] = currentPlayer;
            return true;
        }
        if (col < size - 1 && verticalEdges[row][col + 1] && horizontalEdges[row][col] && horizontalEdges[row + 1][col]) {
            grid[row][col] = currentPlayer;
            return true;
        }
    }
    return false;
}

bool DotsAndBoxes::isBoardFull() const {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (grid[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

GameState DotsAndBoxes::status() const {
    return gameState;
}

void DotsAndBoxes::printBoard() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << (j == 0 ? "" : " ");
            std::cout << (grid[i][j] == PLAYER_1 ? "X" : grid[i][j] == PLAYER_2 ? "O" : ".");
        }
        std::cout << std::endl;
    }
}

int main() {
    int row, col;
    char direction;
    DotsAndBoxes game;

    while (game.status() == ONGOING) {
        game.printBoard();
        std::cout << (game.status() == PLAYER_1 ? "Player 1's turn (X)" : "Player 2's turn (O)") << std::endl;
        std::cout << "Enter your move (row col direction[h/v]): ";
        std::cin >> row >> col >> direction;

        game.play(row - 1, col - 1, direction);
    }

    game.printBoard();
    switch (game.status()) {
    case PLAYER_1_WINS:
        std::cout << "Player 1 (X) wins!\n";
        break;
    case PLAYER_2_WINS:
        std::cout << "Player 2 (O) wins!\n";
        break;
    case DRAW:
        std::cout << "It's a draw!\n";
        break;
    default:
        break;
    }

    return 0;
}
