#include <math.h>
#include <iostream>
using namespace std;

int main() {

	int n = 5;
	double A[5][5] = { {27, -3, 4, -6, 5},
			{2, 24, 7, 0, 2},
			{4, 3, 33, 1, 9},
			{-4, 0, -5, 28, -1,},
			{7, 1, -7, 2, 25} };
	double C[5] = { 27, 70, 150, 36, 28 };
	double X[5] = { 0,0,0,0,0 };
	double XX[5];

	int how_many = 0;


	/// вывод начального вектора
	for (int i = 0; i < n; i++) {
		cout << X[i] << " ";
	}

	/// вычисление х(К+1)
	do {
		for (int i = 0; i < n; i++) {
			XX[i] = C[i];
			for (int j = 0; j < n; j++) {
				if (j != i) {
					XX[i] = XX[i] - A[i][j] * X[j];
				}
			}
			XX[i] = XX[i] / A[i][i];
		}

		how_many = 0;
		///проверка модулей разности
		for (int i = 0; i < n ; i++) {
			if (fabs(X[i] - XX[i]) < 0.0001) {
				how_many = how_many + 1;
			}
			X[i] = XX[i];
		}
		/// вывод результирующего вектора
		for (int i = 0; i < n; i++) {
			cout << X[i] << " ";
		}
		cout << endl;
	} while (how_many != n);



}




