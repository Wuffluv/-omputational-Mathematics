#include <iostream>
#include <cmath>

using namespace std;

double fn(double x, double y) {
    return (4 * x * x + 3) * sin(y);
}

int main() {
    const int nm = 11;
    double xx[nm];
    double yy[nm];
    double xo = 0;
    double yo = 1;
    double h = 0.1;

    // Euler
    xx[0] = xo;
    yy[0] = yo;
    for (int k = 1; k < nm; k++) {
        xx[k] = xx[k - 1] + h;
        yy[k] = yy[k - 1] + h * fn(xx[k - 1], yy[k - 1]);
    }

    cout << "Euler" << endl;
    cout << "xx" << endl;
    for (int i = 0; i < nm; i++) {
        cout << xx[i] << endl;
    }
    cout << endl;
    cout << "yy" << endl;
    for (int i = 0; i < nm; i++) {
        cout << yy[i] << endl;
    }
    cout << endl;

    // Euler Mod
    xx[0] = xo;
    yy[0] = yo;
    for (int k = 1; k < nm; k++) {
        xx[k] = xx[k - 1] + h;
        yy[k] = yy[k - 1] + h * fn(xx[k - 1] + h / 2, yy[k - 1] + (h / 2) * fn(xx[k - 1], yy[k - 1]));
    }

    cout << "Euler Mod" << endl;
    cout << "yy" << endl;
    for (int i = 0; i < nm; i++) {
       cout << yy[i] << endl;
    }
    cout << endl;

    // Runge-Kutta
    xx[0] = xo;
    yy[0] = yo;
    for (int k = 1; k < nm; k++) {
        xx[k] = xx[k - 1] + h;
        double a = h * fn(xx[k - 1], yy[k - 1]);
        double b = h * fn(xx[k - 1] + h / 2, yy[k - 1] + a / 2);
        double c = h * fn(xx[k - 1] + h / 2, yy[k - 1] + b / 2);
        double d = h * fn(xx[k - 1] + h, yy[k - 1] + c);
        yy[k] = yy[k - 1] + (a + 2 * b + 2 * c + d) / 6;
    }

    cout << "Runge-Kutta" << endl;
    cout << "yy" << endl;
    for (int i = 0; i < nm; i++) {
        cout << yy[i] << endl;
    }
    cout << endl;

    // Adams
    xx[0] = xo;
    yy[0] = yo;
    for (int k = 1; k < nm; k++) {
        xx[k] = xx[k - 1] + h;
        if (k <= 1) {
            double a = h * fn(xx[k - 1], yy[k - 1]);
            double b = h * fn(xx[k - 1] + h / 2, yy[k - 1] + a / 2);
            double c = h * fn(xx[k - 1] + h / 2, yy[k - 1] + b / 2);
            double d = h * fn(xx[k - 1] + h, yy[k - 1] + c);
            yy[k] = yy[k - 1] + (a + 2 * b + 2 * c + d) / 6;
        }
        else {
            double a = fn(xx[k - 1], yy[k - 1]);
            double b = fn(xx[k - 1], yy[k - 2]);
            yy[k] = yy[k - 1] + (h / 2) * (3 * a - b);
        }
    }

    cout << "Adams for m = 1" << endl;
    cout << "yy" << endl;
    for (int i = 0; i < nm; i++) {
        cout << yy[i] << endl;
    }
    cout << endl;

    return 0;
}

