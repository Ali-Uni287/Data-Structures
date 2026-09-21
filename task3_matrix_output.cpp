#include <iostream>
using namespace std;
const int SIZE = 3;
void displayMatrix(int m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}
int main() {
    int A[SIZE][SIZE] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int B[SIZE][SIZE] = {{9, 8, 7},{6, 5, 4},{3, 2, 1}};
    int sum[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            sum[i][j] = A[i][j] + B[i][j];
    cout << "Matrix A:\n";
    displayMatrix(A);
    cout << "Matrix B:\n";
    displayMatrix(B);
    cout << "\nSum of Matrix A and B:\n\n";
    displayMatrix(sum);
    return 0;
}
