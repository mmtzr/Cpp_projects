// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "TicTacToe.h"


int main()
{
    char winner = ' ';
    int player_turn = 0;

    resetBoard();

    std::cout << "Enter your character [X/O]: \n";
    std::cin >> player_token;

    player_token = toupper(player_token);

    while (player_token != 'O' && player_token != 'X') {
        std::cout << "Invalid input. Please enter X or O. \n";
        std::cout << "Enter your character [X/O]: \n";
        std::cin >> player_token;
        player_token = toupper(player_token);
    }

    if (player_token == 'X') {
        ai_token = 'O';
        player_turn = 0; // computer plays first
    }
    else {
        ai_token = 'X';
        player_turn = 1; //player plays first
    }
    printBoard();

    // game loop
    while (winner == ' ' && checkFreeSpaces() != 0) {
        player_turn = Move(player_turn);
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }

        player_turn = Move(player_turn);
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }
    }
    printWinner(winner);
    
}

void resetBoard()
{
    // create an empty 3x3 board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() 
{
    // print the board
    for (int i = 0; i < 2; i++) {
        std::cout << "  " << board[0][i] << " | "<< board[1][i]  << " | " << board[2][i] << " \n";

        std::cout << "  --|---|-- \n";
    }
    std::cout << "  " << board[0][2] <<" | " << board[1][2] << " | "<< board[2][2] <<" \n";
}

int Move(int player_turn)
{
    // check whose turn it is and make the move
    if (player_turn == 0) {
        std::cout << "My move.\n";
        computerMove();
        printBoard();
        return 1;
    }
    else {
        std::cout << "Your move.\n";
        playerMove();
        printBoard();
        return 0;
    }
}

int checkFreeSpaces()
{
    // check and return how many free spaces are left
    int freeSpaces = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove()
{
    int row, col;
    std::cout << "Enter row #(1-3): \n";
    std::cin >> row;
    row--;
    std::cout << "Enter column #(1-3): \n";
    std::cin >> col;
    col--;

    // loop until player gives a valid input
    do {
        if (board[row][col] != ' ') {
            std::cout << "Invalid move! Space occupied, try again.\n";
        }
        else {
            board[row][col] = player_token; 
            break;
        }
    } while (board[row][col] != ' ');
    
}

void computerMove()
{
    // generate a random number based on a seed
    // generate the seed based on  time
    srand(time(0));
    int row, col;
    // check if there is any space left
    if (checkFreeSpaces() > 0) {
        // generate two numbers 0-2
        // check if free, else generate until we get a free space
        do
        {
            row = rand() % 3;
            col = rand() % 3;

        } while (board[row][col] != ' ');

        board[row][col] = ai_token;
    }
    else {
        printWinner(' ');
    }
}

char checkWinner()
{
    // check board for winning state
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}

void printWinner(char winner)
{
    if (winner == player_token) {
        std::cout << "You win! ^o^ \n";
    }
    else if (winner == ai_token) {
        std::cout << "You lose! T_T \n";
    }
    else {
        std::cout << "It's a draw :( \n";
    }
}
