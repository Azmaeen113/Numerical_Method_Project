#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return x + y;
}

int main()
{
    double x0, y0, xn, h;

    cin >> x0;
    cin >> y0;
    cin >> xn;
    cin >> h;

    double x = x0;
    double y = y0;

    cout << fixed << setprecision(6);

    while (x < xn)
    {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x = x + h;

        cout << x << " " << y << endl;
    }

    return 0;
}
