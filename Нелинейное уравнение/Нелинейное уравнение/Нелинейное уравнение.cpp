#include <iostream>
#include <cmath>

using namespace std;

// определяем функцию
double f(double x) {
    return x + pow(2, x) + 1;
}

// функция для метода половинного деления
double bisection(double a, double b, double eps) {
    int n = 0; // счетчик числа итераций
    while (b - a > eps) { // пока не достигнута заданная точность
        double c = (a + b) / 2; // находим середину отрезка
        if (f(c) == 0) { // если нашли корень
            cout << "Number of iterations: " << n << endl;
            return c;
        }
        else if (f(a) * f(c) < 0) { // если корень находится на левой половине отрезка
            b = c; // сдвигаем правую границу
        }
        else { // если корень находится на правой половине отрезка
            a = c; // сдвигаем левую границу
        }
        n++; // увеличиваем счетчик итераций
    }
    cout << "Number of iterations: " << n << endl;
    return (a + b) / 2; // возвращаем найденный корень
}

int main() {
    double a = -1, b = 0, eps = 1e-6;
    double root = bisection(a, b, eps);
    cout << "Root: " << root << endl;
    return 0;
}

//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//// определяем функцию и её производную
//double f(double x) {
//    return x + pow(2, x) + 1;
//}
//
//double df(double x) {
//    return 1 + log(2) * pow(2, x);
//}
//
//// функция для метода касательных (метода Ньютона)
//double newton(double x0, double eps) {
//    double x = x0;
//    int n = 0; // счетчик числа итераций
//    while (fabs(f(x)) > eps) { // пока не достигнута заданная точность
//        x = x - f(x) / df(x); // находим следующее приближение
//        n++; // увеличиваем счетчик итераций
//    }
//    cout << "Number of iterations: " << n << endl;
//    return x; // возвращаем найденный корень
//}
//
//int main() {
//    double x0 = -1, eps = 1e-6;
//    double root = newton(x0, eps);
//    cout << "Root: " << root << endl;
//    return 0;
//}