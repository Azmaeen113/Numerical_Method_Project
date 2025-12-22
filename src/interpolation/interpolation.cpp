
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    double target;
    cin >> target;

    string method;
    cin >> method;

    if (method == "forward") {
        vector<vector<double>> d(n);
        d[0] = y;

        for (int i = 1; i < n; i++)
            for (int j = 0; j < n - i; j++)
                d[i].push_back(d[i - 1][j + 1] - d[i - 1][j]);

        double h = x[1] - x[0];
        double p = (target - x[0]) / h;

        double ans = y[0], term = 1.0;
        for (int i = 1; i < n; i++) {
            term *= (p - (i - 1)) / i;
            ans += term * d[i][0];
        }

        cout << ans << endl;
    }

    else if (method == "backward") {
        vector<vector<double>> d(n);
        d[0] = y;

        for (int i = 1; i < n; i++)
            for (int j = n - 1; j >= i; j--)
                d[i].push_back(d[i - 1][j] - d[i - 1][j - 1]);

        double h = x[1] - x[0];
        double p = (target - x[n - 1]) / h;

        double ans = y[n - 1], term = 1.0;
        for (int i = 1; i < n; i++) {
            term *= (p + (i - 1)) / i;
            ans += term * d[i][i - 1];
        }

        cout << ans << endl;
    }

    else if (method == "divided") {
        vector<vector<double>> d(n, vector<double>(n));
        for (int i = 0; i < n; i++)
            d[i][0] = y[i];

        for (int j = 1; j < n; j++)
            for (int i = 0; i < n - j; i++)
                d[i][j] = (d[i + 1][j - 1] - d[i][j - 1]) /
                          (x[i + j] - x[i]);

        double ans = d[0][0], term = 1.0;
        for (int i = 1; i < n; i++) {
            term *= (target - x[i - 1]);
            ans += term * d[0][i];
        }

        cout << ans << endl;
    }

    else {
        cout << "Invalid method" << endl;
    }

    return 0;
}

