#include <iostream>
using namespace std;

char board[3][3]; // 3x3 Tic-Tac-Toe board
int currentPlayer = 1; // Player 1 starts

// Function to initialize the Tic-Tac-Toe board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the Tic-Tac-Toe board
void displayBoard() {
    system("cls"); // Clear the screen
    cout << "Welcome to Tic-Tac-Toe Game\n\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|"; // Vertical line
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl; // Horizontal line
    }
    cout << endl;
}

// Function to make a move for the current player
int makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return 0; // Invalid move
    }

    char mark = (currentPlayer == 1) ? 'X' : 'O';
    board[row][col] = mark;
    return 1; // Valid move
}

// Function to check if the game is over
int isGameOver() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // Win in a row

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // Win in a column
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // Win in the main diagonal

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // Win in the other diagonal

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Game still in progress
            }
        }
    }

    return -1; // It's a draw
}

int main() {
    int row, col, moveResult, gameOver;
    char playAgain;

    do {
        initializeBoard();

        do {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move\nRow: ";
            cin >> row;
			cout<<"Column: ";
			cin>> col; 

            // Adjust user input to match array indexing (1-3 to 0-2)
            row--; // Decrement by 1
            col--;

            // Make the move and check if it's valid
            moveResult = makeMove(row, col);
            if (!moveResult) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            // Check if the game is over
            gameOver = isGameOver();

            if (gameOver == 1) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            } else if (gameOver == -1) {
                displayBoard();
                cout << "It's a draw! Well played!" << endl;
            } else {
                // Switch to the other player
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        } while (gameOver == 0);

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');
	return 0;
}
