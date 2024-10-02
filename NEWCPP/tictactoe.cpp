#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe(int size) : boardSize(size), currentPlayer(1) {
        // Initialize the game board with empty cells
        board = std::vector<std::vector<char>>(size, std::vector<char>(size, ' '));
    }

    bool makeMove(int row, int col) {
        // Check if the cell is valid and empty
        if (row < 0 || row >= boardSize || col < 0 || col >= boardSize || board[row][col] != ' ') {
            return false;
        }

        // Make the move for the current player
        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';

        // Toggle the current player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        return true;
    }

    bool isGameOver() {
        // Check for a win or a draw
        return checkWin() || isBoardFull();
    }

    void printBoard() {
        // Print the game board
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                std::cout << board[i][j];
                if (j < boardSize - 1) std::cout << " | ";
            }
            std::cout << std::endl;
            if (i < boardSize - 1) {
                for (int k = 0; k < boardSize * 4 - 1; ++k) {
                    std::cout << "-";
                }
                std::cout << std::endl;
            }
        }
    }

    int getCurrentPlayer()
    {
        return currentPlayer;
    }

private:
    std::vector<std::vector<char>> board;
    int boardSize;
    int currentPlayer;

    bool checkWin() {
        // Check for a win horizontally, vertically, and diagonally
        // Implement your winning condition checks here
        return false;
    }

    bool isBoardFull() {
        // Check if the board is full (draw)
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int boardSize = 3;
    TicTacToe game(boardSize);

    while (!game.isGameOver()) {
        int row, col;
        std::cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (game.makeMove(row, col)) {
            game.printBoard();
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}