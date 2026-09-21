#include <iostream>
using namespace std;
const int LABS = 2;
const int ROWS = 3;
const int COMPUTERS = 5;

int main() {
    int lab[LABS][ROWS][COMPUTERS] = {{ {1, 0, 1, 1, 0}, {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0} },{ {0, 1, 0, 1, 1}, {1, 0, 0, 0, 1}, {0, 0, 1, 1, 0} } };
    int totalAvailable = 0, totalInUse = 0;
    int labAvailable[LABS] = {0};
    cout << "COMPUTER LAB STATUS (0 = Available, 1 = In Use) \n";
    for (int l = 0; l < LABS; l++) {
        cout << "\nLab " << l + 1 << ":\n";
        for (int r = 0; r < ROWS; r++) {
            cout << "  Row " << r + 1 << ": ";
            for (int c = 0; c < COMPUTERS; c++) {
                cout << lab[l][r][c] << " ";

                if (lab[l][r][c] == 0) {
                    totalAvailable++;
                    labAvailable[l]++;
                } else {
                    totalInUse++;
                }
            }
            cout << "\n";
        }
    }
    cout << "\nTotal available computers: " << totalAvailable << "\n";
    cout << "Total computers in use   : " << totalInUse << "\n";
    cout << "\n AVAILABLE COMPUTERS PER LAB\n";
    for (int l = 0; l < LABS; l++)
        cout << "Lab " << l + 1 << ": " << labAvailable[l] << "\n";
    int labNo, rowNo, compNo;
    cout << "\nEnter lab number (1-" << LABS << "): ";
    cin >> labNo;
    cout << "Enter row number (1-" << ROWS << "): ";
    cin >> rowNo;
    cout << "Enter computer number (1-" << COMPUTERS << "): ";
    cin >> compNo;
    if (cin.fail() || labNo < 1 || labNo > LABS ||
        rowNo < 1 || rowNo > ROWS || compNo < 1 || compNo > COMPUTERS) {
        cout << "\nInvalid input! Lab must be 1-" << LABS
             << ", row 1-" << ROWS << ", computer 1-" << COMPUTERS << ".\n";
    } else {
        cout << "\nComputer " << compNo << " in Row " << rowNo
             << " of Lab " << labNo << " is ";
        if (lab[labNo - 1][rowNo - 1][compNo - 1] == 0)
            cout << "AVAILABLE.\n";
        else
            cout << "IN USE.\n";
    }
    return 0;
}
