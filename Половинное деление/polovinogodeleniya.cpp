#include <iostream>

int main() {

	float a = -3;
	float b = -2;
	double e = 0.0001;
	float c, x;

	while (b - a > 2 * e) {
			c = (a + b) / 2;
			if ((2*pow(a,3) + 4*pow(a, 2) + 4) + a + 3 < 0) {
				b = c;
			}
			else {
				if ((2 * pow(b, 3) + 4 * pow(b, 2) + 4) + b + 3 < 0) {
					a = c;
				}
			}
		x = (a + b) / 2;
		}
	std :: cout << x;
}


