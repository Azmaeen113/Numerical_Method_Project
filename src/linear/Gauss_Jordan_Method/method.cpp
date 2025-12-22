#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1));
    vector<double> x(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int r = i + 1; r < n; r++)
            if (fabs(a[r][i]) > fabs(a[pivot][i]))
                pivot = r;

        swap(a[i], a[pivot]);

        double d = a[i][i];
        if (d == 0) return 0;

        for (int j = 0; j <= n; j++)
            a[i][j] /= d;

        for (int r = 0; r < n; r++) {
            if (r == i) continue;
            double f = a[r][i];
            for (int c = 0; c <= n; c++)
                a[r][c] -= f * a[i][c];
        }
    }

    for (int i = 0; i < n; i++)
        x[i] = a[i][n];

    for (double v : x) cout << v << " ";
    cout << endl;
}
