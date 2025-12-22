#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return 1.0 / (1.0 + x * x);
}

int main()
{
    double a = 0.0;
    double b = 1.0;
    int n = 4;

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    double result = (h / 3.0) * sum;

    cout << fixed << setprecision(6) << result << endl;
    return 0;
}
