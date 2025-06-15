/*
 Name: Arissya Zahiera Binti Zulazman
 ID : 24006970
 Group : Lab 1
 Question: A Boolean Matrix Question
*/
#include <iostream>
using namespace std;

void booleanMatrix(int mat[][100], int row, int col) {
    bool rowmarker[100] = { false };
    bool colmarker[100] = { false };

    for (int i = 0; i < row; i++) { //if 1 is found mark row and column
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 1) {
                rowmarker[i] = true;
                colmarker[j] = true;
            }
        }
    }

    for (int i = 0; i < row; i++) { // make every cell in row n col marked 1
        for (int j = 0; j < col; j++) {
            if (rowmarker[i] || colmarker[j]) {
                mat[i][j] = 1;
            }
        }
    }
}

int main() {
    int mat[100][100];
    int row, col;

    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    cout << "Enter the matrix (1 or 0 only) (with every number add a space): " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> mat[i][j];

            if (mat[i][j] != 0 && mat[i][j] != 1) {
                cout << "Invalid input. Only 0 and 1 allowed." << endl;
                return 1;
            }
        }
    }

    booleanMatrix(mat, row, col);

    cout << "Output:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
