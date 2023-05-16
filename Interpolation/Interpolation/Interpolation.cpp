#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<pair<double, double>> points = { {-1.8, 6.63552}, {-0.4, -4.43904}, {0.1, 1.94271},
                                           {1.5, 29.53125}, {1.8, 27.57888}, {2.7, 4.22577} };
    vector<double> y = { 6.63552, -4.43904, 1.94271, 29.53125, 27.57888, 4.22577 };
    double x = -2;

    // Вычисление многочлена Лагранжа
    double lagrange = 0;
    for (int k = 0; k < points.size(); k++) {
        double numerator = 1;
        for (int i = 0; i < points.size(); i++) {
            if (i != k) {
                numerator *= (x - points[i].first);
            }
        }

        double denominator = 1;
        for (int j = 0; j < points.size(); j++) {
            if (j != k) {
                denominator *= (points[k].first - points[j].first);
            }
        }

        lagrange += points[k].second * numerator / denominator;
    }

    // Вычисление многочлена Ньютона
    int n = points.size();
    double** divided_differences = new double* [n];
    for (int i = 0; i < n; i++) {
        divided_differences[i] = new double[n];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            divided_differences[i][j] = (divided_differences[i+1][j-1] - divided_differences[i][j-1]) /
                (points[i+j].first - points[i].first);
        }
    }

    double newton = y[0];
    for (int k = 1; k < n; k++) {
        double prod = 1;
        for (int j = 0; j < k; j++) {
            prod *= (x - points[j].first);
        }
        newton += divided_differences[0][k] * prod;
    }

    for (int i = 0; i < n; i++) {
        delete[] divided_differences[i];
    }
    delete[] divided_differences;

    
    cout << "Значение полинома Лагранжа: " << lagrange << endl;
    cout << "Значение полинома Ньютона: " << newton << endl;

    return 0;
}
