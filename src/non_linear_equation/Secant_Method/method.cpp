#include <bits/stdc++.h>
using namespace std;

int main()
{
    int degree, maxIter;
    double x0, x1, tol;

    cin >> degree;

    vector<double> coef(degree + 1);
    for (int i = 0; i <= degree; i++)
        cin >> coef[i];

    cin >> x0 >> x1 >> tol >> maxIter;

    auto f = [&](double x)
    {
        double val = 0;
        for (int i = 0; i <= degree; i++)
            val += coef[i] * pow(x, degree - i);
        return val;
    };

    double f0 = f(x0);
    double f1 = f(x1);
    int iter = 0;

    while (iter < maxIter)
    {
        if (fabs(f1 - f0) < 1e-12)
            break;

        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        double f2 = f(x2);

        if (fabs(x2 - x1) < tol || fabs(f2) < tol)
        {
            cout << fixed << setprecision(6) << x2 << endl;
            return 0;
        }

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        iter++;
    }

    cout << fixed << setprecision(6) << x1 << endl;
    return 0;
}
