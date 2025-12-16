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

    double fb = f(b);
    double c = a, fc = fa, prev = 1e18;

    iter = 0;
    while (iter < maxIter)
    {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);

        if (fabs(fc - prev) <= tol || fabs(fc) < tol)
        {
            a = b = c;
            break;
        }

        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }

        prev = fc;
        iter++;
    }

    cout << a << "\n";

    return 0;
}
