#include <iostream>

using namespace std;

void transpose(double matrix[][100], int m, int n) {
    int min = (m < n) ? m : n;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i < min && j < min && i < j) {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
            else if (i >= min || j >= min) {
                matrix[j][i] = matrix[i][j];
            }
        }
    }
}

void printMatrix(double matrix[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    double matrix[100][100];
    
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[0][3] = 4;
    
    matrix[1][0] = 5;
    matrix[1][1] = 6;
    matrix[1][2] = 7;
    matrix[1][3] = 8;

    printMatrix(matrix, 2, 4);
    
    transpose(matrix, 2, 4);
    
    cout << endl;
    printMatrix(matrix, 4, 2);
}
