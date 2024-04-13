// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "TicTacToe.h"



int main()
{
    char winner = ' ';
    
    resetBoard();

    

    std::cout << "Enter your character [X/O]: \n";
    std::cin >> player_token;
    player_token = toupper(player_token);
    if (player_token == 'X') {
        ai_token = 'O';
    }
    else if (player_token == 'O') {
        ai_token = 'X';
    }
    else {
        std::cout << "Invalid input. Please enter X or O. \n";
    }

    // game loop
    while (winner == ' ' && checkFreeSpaces() != 0) {
        printBoard();
        playerMove();
        printBoard();
        computerMove();
        printBoard();
        checkWinner();
    }
    
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
        printf("  %c | %c | %c \n", board[0][i], board[1][i], board[2][i]);
        printf("  --|---|-- \n");
    }
    printf("  %c | %c | %c \n", board[0][2], board[1][2], board[2][2]);
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
            std::cout << "Invalid move!\n";
        }
        else {
            board[row][col] = player_token;
        }
    } while (board[row][col] != ' ');
    
}
