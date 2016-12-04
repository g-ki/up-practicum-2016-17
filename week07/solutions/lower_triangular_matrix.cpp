#include <iostream>

using namespace std;

// Когато подаваме двумерен масив като аргумент на функция,
// не е задължително да подаваме първата му размерност.
bool lowerTriangularMatrix(double matrix[][100], int n) {
    for (int row = 0; row < n - 1; row++) {
        for (int column = row + 1; column < n; column++) {
            if (matrix[row][column] != 0)
                return false;
        }
    }

    return true;
}

int main() {
    double matrix[100][100];
    
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    
    matrix[1][0] = 2;
    matrix[1][1] = 3;
    matrix[1][2] = 0;
    
    matrix[2][0] = 4;
    matrix[2][1] = 5;
    matrix[2][2] = 6;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << matrix[i][j];
        cout << endl;
    }
    
    cout << endl << lowerTriangularMatrix(matrix, 3);
}
