#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() 
{
	int n = 6;
	double x[6], y[6], z[6], a[6], b[6], c[6];

	///Координаты точек
	x[0] = -1.8;
	x[1] = -0.4;
	x[2] = 0.1;
	x[3] = 1.5;
	x[4] = 1.8;
	x[5] = 2.7;

	y[0] = 6.63552;
	y[1] = -4.43904;
	y[2] = 1.94271;
	y[3] = 29.53125;
	y[4] = 27.57888;
	y[5] = 4.22577;

	///z - значения производных в узлах интерполяции
	z[0] = -1;
	///Коэффиценты частичных функций сплайна
	a[0] = 0;
	b[0] = 0;
	c[0] = 0;

	int k;
	double d, e;
	for (k = 1; k < n; k++) {
		d = x[k] - x[k - 1];
		e = y[k] - y[k - 1];
		a[k] = e / (d * d) - z[k - 1] / d;
		b[k] = 2 * e / d - z[k - 1];
		c[k] = y[k];
		z[k] = b[k];
		printf("z[%d]: %f      ", k, z[k]);
		printf("a[%d]: %f      ", k, a[k]);
		printf("b[%d]: %f      ", k, b[k]);
		printf("c[%d]: %f      \n", k, c[k]);

	}

}