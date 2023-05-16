#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>

using namespace std;

/** функция для дифференцирования */
double f(double x) {
    return sin(3 * x);
}

int main() {
    setlocale(LC_ALL, "RUS");
    const int nm = 6;

    int M1 = 27;
    int M2 = 243;
    double xo = 3.14 / 4;
    double eps = 0.001;

    vector<double> x = { 6.8, 7.2, 7.6, 8.0, 8.4, 8.8, 9.2 };
    vector<double> y = { -0.44194, -0.60356, -0.75676, -0.90237, -1.04108, -1.17352, -1.20021 };
    vector<vector<double>> yy = { {-0.44194, 0, 0, 0, 0, 0, 0},
                                 {-0.60356, 0, 0, 0, 0, 0, 0},
                                 {-0.75676, 0, 0, 0, 0, 0, 0},
                                 {-0.90237, 0, 0, 0, 0, 0, 0},
                                 {-1.04108, 0, 0, 0, 0, 0, 0},
                                 {-1.17352, 0, 0, 0, 0, 0, 0},
                                 {-1.20021, 0, 0, 0, 0, 0, 0} };

    cout << "По первой формуле верхний порог для h = ";
    double s1 = sqrt(6 * eps / M1);
    cout << s1 << endl;

    cout << "Введите желаемое h: ";
    double h;
    cin >> h;
    double diff1 = (f(xo + h) - f(xo - h)) / (2 * h);
    cout << "Производная, вычисленная по первой формуле: " << diff1 << endl;

    cout << "По второй формуле верхний порог для h = ";
    double s2 = pow(30 * eps / M2, 0.25);
    cout << s2 << endl; cout << "Введите желаемое h: ";
    double h1;
    cin >> h1;
    double diff2 = (f(xo - 2 * h1) - 8 * f(xo - h1) + 8 * f(xo + h1) - f(xo + 2 * h1)) / (12 * h1);
    cout << "Производная, вычисленная по второй формуле: " << diff2 << endl;

    /** второй способ */
    double h2 = 0.1;
    for (int j = 1; j <= nm; j++) {
        for (int i = 0; i <= nm - j; i++) {
            yy[i][j] = yy[i + 1][j - 1] - yy[i][j - 1];
        }
    }

    double s = 0;
    double d = -1;
    double Delta = 0;
    for (int j = 1; j <= nm - 1; j++) {
        d = (-1) * d;
        double tempSum = 0;
        double tempDelta = 0;
        for (int i = 0; i <= nm - j; i++) {
            if (j == 1) {
                yy[i][j] = y[i];
            }
            else {
                yy[i][j] = yy[i + 1][j - 1] - yy[i][j - 1];
            }
            tempSum += yy[i][j];
        }
        s += d * tempSum / (j * h2);
        Delta = abs(yy[0][j + 1] / ((j + 1) * h2));

        tempDelta += Delta;
        cout << "y'(xo) = " << s << endl;
        cout << "погрешность = " << tempDelta << endl;
    }

    return 0;

}