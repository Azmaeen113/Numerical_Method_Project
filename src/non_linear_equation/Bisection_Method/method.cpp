#include <bits/stdc++.h>
using namespace std;

int main()
{
    int degree, maxIter;
    double a, b, step, tol;

    cin >> degree;

    vector<double> coef(degree + 1);
    for (int i = 0; i <= degree; i++)
        cin >> coef[i];

    cin >> a >> b >> step >> tol >> maxIter;

    auto f = [&](double x)
    {
        double val = 0;
        for (int i = 0; i <= degree; i++)
            val += coef[i] * pow(x, degree - i);
        return val;
    };

    double fa = f(a);
    double left = a, right = a;
    int iter = 0;

    while (iter < maxIter)
    {
        left -= step;
        right += step;

        if (fa * f(left) < 0)
        {
            b = left;
            break;
        }

        if (fa * f(right) < 0)
        {
            b = right;
            break;
        }
        iter++;
    }

    double mid = a;

    iter = 0;
    while (iter < maxIter)
    {
        mid = (a + b) / 2.0;
        double fm = f(mid);

        if (fabs(fm) < tol || fabs(b - a) < tol)
        {
            a = b = mid;
            break;
        }

        if (fa * fm < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
            fa = fm;
        }
        iter++;
    }

    cout << (a + b) / 2.0 << "\n";

    return 0;
}
