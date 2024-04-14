#pragma once
#include <iostream>

// GLOBAL VARIABLES
// create the game space and initiate with coordinates
char board[3][3];
char player_token, ai_token;



void resetBoard();
void printBoard();
int Move(int);
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);
