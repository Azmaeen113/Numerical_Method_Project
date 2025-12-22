#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double factor = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++)
                a[j][k] -= factor * a[i][k];
        }
    }

    vector<double> x(n);

    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    for (int i = 0; i < n; i++)
        cout << x[i] << " ";

    return 0;
}
