// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// GLOBAL
// create the game space and initiate with coordinates
int game_space[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int digit;
int row, col;
char token;

int main()
{

    // players' names
    string n1, n2;
    cout << "Enter the name of the first player (X):\n";
    cin >> n1;
    cout << "Enter the name of the second player (O):\n";
    cin >> n2;
    // draw initial structure
    draw_structure();
    // begin game loop
    int i = 1;
    

    while (i!=0) {
        cout << "Player " << n1 << " enter coordinates.\n";
        cin >> digit;
        switch (digit) {
            case 0:
               row = 0;
               col = 1;

            }
        
            
    }
}

void draw_structure() {
    cout << "      |      |     \n";
    cout << "  " << game_space[0][0] << "  |  " << game_space[0][1] << "  |  " << game_space[0][2] << "  \n";
    cout << "______|______|_____\n";
    cout << "      |      |     \n";
    cout << "  " << game_space[1][0] << "  |  " << game_space[1][1] << "  |  " << game_space[1][2] << "  \n";
    cout << "______|______|_____\n";
    cout << "      |      |     \n";
    cout << "  " << game_space[2][0] << "  |  " << game_space[2][1] << "  |  " << game_space[2][2] << "  \n";
    cout << "      |      |     \n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
