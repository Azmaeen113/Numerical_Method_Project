#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int degree;
vector<double> coef;
double a, tol;
int maxIter;

void input_data() {
    cin >> degree;
    coef.resize(degree + 1);
    for (int i = 0; i <= degree; i++)
        cin >> coef[i];
    cin >> a >> tol >> maxIter;
}

double function_value(double x) {
    double res = 0;
    for (int i = 0; i <= degree; i++)
        res += coef[i] * pow(x, degree - i);
    return res;
}

double derivative_value(double x) {
    double res = 0;
    for (int i = 0; i < degree; i++)
        res += coef[i] * (degree - i) * pow(x, degree - i - 1);
    return res;
}

double solve() {
    int iter = 0;
    double x0 = a, x1;

    while (iter < maxIter) {
        double df = derivative_value(x0);
        if (fabs(df) < 1e-12)
            break;

        x1 = x0 - function_value(x0) / df;

        if (fabs(x1 - x0) < tol || fabs(function_value(x1)) < tol)
            return x1;

        x0 = x1;
        iter++;
    }

    return x0;
}

int main() {
    input_data();
    double root = solve();
    cout << fixed << setprecision(6) << root << endl;
    return 0;
}