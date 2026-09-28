#include <iostream>
using namespace std;
const int FLOORS = 3;
const int WARDS = 3;
const int BEDS = 4;

int main() {
    int beds[FLOORS][WARDS][BEDS] = {{ {1, 0, 1, 0}, {0, 0, 1, 1}, {1, 1, 0, 0} }, { {0, 1, 0, 0}, {1, 0, 0, 1}, {0, 0, 0, 1} }, { {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 0, 1, 1} }   };
    int totalOccupied = 0, totalAvailable = 0;
    int floorOccupied[FLOORS] = {0};
    cout << " HOSPITAL BED STATUS (0 = Available, 1 = Occupied)\n";
    for (int f = 0; f < FLOORS; f++) {
        cout << "\nFloor " << f + 1 << ":\n";
        for (int w = 0; w < WARDS; w++) {
            cout << "  Ward " << w + 1 << ": ";
            for (int b = 0; b < BEDS; b++) {
                cout << beds[f][w][b] << " ";

                if (beds[f][w][b] == 1) {
                    totalOccupied++;
                    floorOccupied[f]++;
                } else {
                    totalAvailable++;
                }
            }
            cout << "\n";
        }
    }
    cout << "\nTotal occupied beds : " << totalOccupied << "\n";
    cout << "Total available beds: " << totalAvailable << "\n";
    cout << "\nOCCUPIED BEDS PER FLOOR \n";
    for (int f = 0; f < FLOORS; f++)
        cout << "Floor " << f + 1 << ": " << floorOccupied[f] << "\n";
    int floorNo, wardNo, bedNo;
    cout << "\nEnter floor number (1-" << FLOORS << "): ";
    cin >> floorNo;
    cout << "Enter ward number (1-" << WARDS << "): ";
    cin >> wardNo;
    cout << "Enter bed number (1-" << BEDS << "): ";
    cin >> bedNo;
    if (cin.fail() || floorNo < 1 || floorNo > FLOORS ||
        wardNo < 1 || wardNo > WARDS || bedNo < 1 || bedNo > BEDS) {
        cout << "\nInvalid input! Floor must be 1-" << FLOORS
             << ", ward 1-" << WARDS << ", bed 1-" << BEDS << ".\n";
    } else {
        cout << "\nBed " << bedNo << " in Ward " << wardNo
             << " on Floor " << floorNo << " is ";
        if (beds[floorNo - 1][wardNo - 1][bedNo - 1] == 0)
            cout << "AVAILABLE.\n";
        else
            cout << "OCCUPIED.\n";
    }
    return 0;
}
