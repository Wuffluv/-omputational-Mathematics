//#include <iostream>
//#include <cmath>
//using namespace std;
//
//double f1(double x) {
//    return 0.3 / sqrt(2 * x * x + 2);
//}
//
//double f2(double x) {
//    return 0.5 * log(x * x + 4) / (x * x + 4);
//}
//
///// Метод трапеций
//double integrate_trapezoid(double (*f)(double), double a, double b, int n) {
//    double h = (b - a) / n;
//    double w = 0;
//
//    for (int k = 1; k < n; k++) {
//        double x = a + k * h;
//        w += f(x);
//    }
//
//    w = (2 * w + f(a) + f(b)) * h / 2;
//    return w;
//}
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//    double a1 = 0.3, b1 = 1.3, a2 = 0.5, b2 = 1.3;
//    int n1 = 1000, n2 = 2000;
//
//    double result1 = integrate_trapezoid(f1, a1, b1, n1);
//    double result2 = integrate_trapezoid(f2, a2, b2, n2);
//
//    cout << "Значение первого интеграла: " << result1 << endl;
//    cout << "Значение второго интеграла: " << result2 << endl;
//
//    return 0;
//}


#include <iostream>
#include <cmath>

using namespace std;

// Интеграл 1: 0.3 dx/корень 2x^2 + 2
double f1(double x) {
    return 0.3 / sqrt(2 * x * x + 2);
}

// Интеграл 2: 0.5 ln(x^2 +4 )/x^2 +4 dx
double f2(double x) {
    return 0.5 * log(x * x + 4) / (x * x + 4);
}

//Метод Симпсона
double simpson_integration(double (*f)(double), double a, double b, int m) {
    int n = 2 * m;
    double h = (b - a) / n;
    double s = 0.0;
    double s1 = 0.0;
    double s2 = 0.0;

    for (int k = 1; k <= m; k++) {
        double x = a + (2 * k - 1) * h;
        s1 += f(x);
    }

    for (int k = 1; k <= m - 1; k++) {
        double x = a + 2 * k * h;
        s2 += f(x);
    }

    s = (4 * s1 + 2 * s2 + f(a) + f(b)) * h / 3.0;
    return s;
}

int main() {
    setlocale(LC_ALL, "Rus");
    // Задаем пределы интегрирования и параметр m
    double a1 = 0.3;
    double b1 = 1.3;
    int m = 100;

    // Вычисляем значение первого интеграла
    double result1 = simpson_integration(f1, a1, b1, m);
    cout << "Значение первого интеграла: " << result1 << endl;

    // Задаем пределы интегрирования и параметр m
    double a2 = 0.5;
    double b2 = 1.3;

    // Вычисляем значение второго интеграла
    double result2 = simpson_integration(f2, a2, b2, m);
    cout << "Значение второго интеграла: " << result2 << endl;

    return 0;
}
