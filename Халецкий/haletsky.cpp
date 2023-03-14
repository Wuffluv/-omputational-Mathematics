#include <iostream>
#include <math.h>
using namespace std;

int main() {

	int n = 6;

	double A[5][5]= { {0.34, 0.74, -0.7, 0.96, 0.98},
		{-0.46, 0.31, -0.59, -0.58, -0.06},
		{-0.76, -0.75, 0.93, 0.42, -0.11},
		{-0.99, 0.88, -0.68, 0.94, 0.64,},
		{0.54, -0.35, -0.99, -0.04, -0.09,}};
	double B[5][5];
	double T[5][5];
	double Y[5];
	double X[5];
	double C[5] = {-0.22, -0.73, 0.39, 0.46, -0.46};

	

	/// заполнение матриц
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = 0;
				if (i == j){
					(T[i][j] = 1);
				}
				else {
					(T[i][j] = 0);
				}
		}
	}
	
	/// заполнение крайнего столбца матрицы В
	for (int i = 0; i < n; i++) {
		B[i][0] = A[i][0];
		}

	/// заполнеие верхней строки матрицы Т
	for (int j = 0; j < n - 1 ; j++) {
		T[0][j] = A[0][j] / B[0][0];
	}

	/// заполнение матрицы B и T
	for (int k = 0; k < n - 1; k++) {
		for (int i = k; i < n - 1; i++) {
			B[i][k] = A[i][k];
				for (int m = 0; m < k; m++) {

				}
		}
		if (k <= n ) {
			for (int j = k + 1; j < n - 1; j++) {
				T[k][j] = A[k][j];
				for (int m = 0; m < k; m++) {
					T[k][j] = T[k][j] - (B[k][m] * T[m][j]);
				}
				T[k][j] = T[k][j] / B[k][k];
			}
		}
	}

	/// вывод матриц B 
	cout << "B" << " ";
	for (int i = 0; i < n - 1 ; i++) {
		for (int j = 0; j < n - 1; j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	/// вывод матриц Т
	cout << "T" << " ";
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				cout << T[i][j] << " ";
			}
			cout << endl;
		}
	cout << endl;

	/// вычисление вектора Y
	Y[0] = C[0] / B[0][0];
	for (int i = 0; i < n - 1; i++) {
		Y[i] = C[i];
			for (int m = 0; m < i; m++) {
				Y[i] = Y[i] - (B[i][m] * Y[m]);
			}
		Y[i] = Y[i] / B[i][i];
	}

	/// вывод вектора Y 
	cout << "Y" << " ";
	for (int i = 0; i < n - 1; i++) {
		cout << Y[i] << " ";
	}

	/// вывод вектора Х
	X[n-2] = Y[n-2];
		for (int i = n - 3; i >= 0; i--) {
			X[i] = Y[i];
			for (int m = i + 1; m < n - 2; m++) {
				X[i] = X[i] - (T[i][m] * X[m]);
				}
		}

	/// вывод вектора Х
	cout << "X" << " ";
	for (int i = 0; i < n - 1; i++) {
		cout << X[i] << " ";
	}
	
}

