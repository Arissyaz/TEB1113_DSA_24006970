#include <iostream>
using namespace std;

int findMaxValue(int mat[100][100], int rc) { //cam guna byk sgt space
    int maxArr[100][100];
    int maxValue = -100000; 

    maxArr[rc - 1][rc - 1] = mat[rc - 1][rc - 1];

    for (int j = rc - 2; j >= 0; j--) {
        maxArr[rc - 1][j] = max(mat[rc - 1][j], maxArr[rc - 1][j + 1]);
    }

    for (int i = rc - 2; i >= 0; i--) {
        maxArr[i][rc - 1] = max(mat[i][rc - 1], maxArr[i + 1][rc - 1]);
    }

    for (int i = rc - 2; i >= 0; i--) {
        for (int j = rc - 2; j >= 0; j--) {
            int potential = maxArr[i + 1][j + 1] - mat[i][j];
            if (potential > maxValue) {
                maxValue = potential;
            }

            maxArr[i][j] = max(mat[i][j], max(maxArr[i][j + 1], maxArr[i + 1][j]));
        }
    }

    return maxValue;
}

int main() {
    int rc;
    int mat[100][100]; // initial matrix ruang

    cout << "Enter number of rows and columns: ";
    cin >> rc;

    cout << "Enter the values into the matrix:" << endl;
    for (int i = 0; i < rc; i++) {
        for (int j = 0; j < rc; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Maximum value is " << findMaxValue(mat, rc) << endl;
    return 0;
}
