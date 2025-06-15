/*
 Name: Arissya Zahiera Binti Zulazman
 ID: 24006970
 Group Lab 1
 Question : Count all sorted rows in a matrix

*/

#include <iostream>
using namespace std;

int Sortedcount(int mat[][100], int row, int column) {
	int sorted = 0;

	for (int i = 0; i < row; i++) {
		bool ascending = true; //reset every loop time 
		bool descending = true;

		for (int j = 0; j < column - 1; j++) {
			if (mat[i][j] >= mat[i][j + 1])
				ascending = false; // when ascending false check descending from start again
			if (mat[i][j] <= mat[i][j + 1])
				descending = false;
		}

		if (ascending || descending)
			sorted++;
	}

	return sorted;
}

int main() {
	int row, column;

	cout << "Enter number of rows: ";
	cin >> row;
	cout << "Enter number of columns: ";
	cin >> column;

	int mat[100][100]; // initial matrix ruang 

	cout << "Enter the values into the matrix:" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> mat[i][j];
		}
	}

	cout << "The number of sorted rows is: " << Sortedcount(mat, row, column) << endl;

	return 0;
}
