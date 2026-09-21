#include <iostream>
using namespace std;
const int ROWS = 4;
const int COLS = 5;
int main() {
    int parking[ROWS][COLS] = {{1, 0, 1, 1, 0},{0, 0, 1, 0, 1},{1, 1, 0, 0, 0},{0, 1, 0, 1, 1}};
    cout << " PARKING LAYOUT (0 = Empty, 1 = Occupied)\n\n";
    cout << "        ";
    for (int j = 0; j < COLS; j++)
        cout << "C" << j + 1 << "  ";
    cout << "\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Row " << i + 1 << "   ";
        for (int j = 0; j < COLS; j++)
            cout << parking[i][j] << "   ";
        cout << "\n";
    }
    int occupied = 0, empty = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (parking[i][j] == 1)
                occupied++;
            else
                empty++;
        }
    }
    cout << "\nTotal occupied spaces: " << occupied << "\n";
    cout << "Total empty spaces   : " << empty << "\n";
    int row, col;
    cout << "\nEnter row number (1-" << ROWS << "): ";
    cin >> row;
    cout << "Enter column number (1-" << COLS << "): ";
    cin >> col;
    if (cin.fail() || row < 1 || row > ROWS || col < 1 || col > COLS) {
        cout << "\nInvalid input! Row must be 1-" << ROWS
             << " and column must be 1-" << COLS << ".\n";
    } else {
        if (parking[row - 1][col - 1] == 0)
            cout << "\nSpace (Row " << row << ", Column " << col << ") is AVAILABLE.\n";
        else
            cout << "\nSpace (Row " << row << ", Column " << col << ") is OCCUPIED.\n";
    }
    int capacity = ROWS * COLS;
    cout << "\n===== PARKING SUMMARY =====\n";
    cout << "Total capacity   : " << capacity << "\n";
    cout << "Current occupancy: " << occupied << " / " << capacity
         << " (" << (occupied * 100) / capacity << "%)\n";
    return 0;
}
