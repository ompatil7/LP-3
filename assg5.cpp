// Design 8-Queens matrix having first Queen placed. Use backtracking to place remaining
// Queens to generate the final 8-queen’s matrix
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

const int N = 4; // Chessboard size (8x8)

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a Queen at board[row][col] is safe
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // Check the column for any Queen
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Function to check if there are valid moves left
bool hasValidMoves(const vector<vector<int>>& board, int row) {
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) return true;
    }
    return false;
}

// Function for the interactive 8-Queens game
bool playGame(vector<vector<int>>& board) {
    int placedQueens = 1; // Start with the first Queen already placed
    int row, col;

    while (placedQueens < N) {
        printBoard(board);

        // Check if there are valid moves left for the next row
        if (!hasValidMoves(board, placedQueens)) {
            cout << "No valid moves left! Game Over. Try again? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                return false; // Restart the game
            } else {
                return true; // End the game
            }
        }

        cout << "Enter row and column (0-7) to place Queen #" << (placedQueens + 1) << ": ";
        cin >> row >> col;

        // Check if the user's chosen position is safe and within bounds
        if (row >= 0 && row < N && col >= 0 && col < N && isSafe(board, row, col)) {
            board[row][col] = 1; // Place the Queen
            placedQueens++;      // Move to the next Queen
        } else {
            cout << "Cannot place Queen at (" << row << ", " << col << "). Try again.\n";
        }
    }
    return true; // Successfully placed all Queens
}

int main() {
    srand(time(0)); // Seed for random number generation

    while (true) {
        // Initialize an 4x4 board with all zeros
        vector<vector<int>> board(N, vector<int>(N, 0));

        // Place the first Queen at a random position
        int firstRow = rand() % N;
        int firstCol = rand() % N;
        board[firstRow][firstCol] = 1;

        cout << "Starting board with first Queen placed at (" << firstRow << ", " << firstCol << "):\n";
        printBoard(board);

        // Begin the interactive game to place remaining Queens
        if (playGame(board)) {
            cout << "Congratulations! You completed the N-Queens puzzle:\n";
            printBoard(board);
            break;
        }
    }
    return 0;
}
//heh bagh
//hela kai input nai ahe, top la N=4 ahe so 4x4 chessboard asel, u can change that
//4x4 chess board sathi inputs :
// 0 1 2 3
// 1
// 2
// 3

// random queen place hoil
// row and column ask karel mag code
// so enter like row (space) column  - 2 1
//EXAMPLE:
//
// Starting board with first Queen placed at (0, 1):
// . Q . . 
// . . . . 
// . . . . 
// . . . . 

// . Q . . 
// . . . . 
// . . . . 
// . . . . 

// Enter row and column (0-7) to place Queen #2: 2 0
// . Q . . 
// . . . . 
// Q . . . 
// . . . . 

// Enter row and column (0-7) to place Queen #3: 3 2
// . Q . . 
// . . . . 
// Q . . . 
// . . Q . 

// Enter row and column (0-7) to place Queen #4: 1 3
// Congratulations! You completed the 8-Queens puzzle:
// . Q . . 
// . . . Q 
// Q . . . 
// . . Q . 