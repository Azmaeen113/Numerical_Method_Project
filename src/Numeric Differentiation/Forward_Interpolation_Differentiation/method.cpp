#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double x[20], y[20][20];
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i][0];
    }
    
    double h = x[1] - x[0];
    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    
    double xp;
    cin >> xp;
    
    double u = (xp - x[0]) / h;
    
    double result = (1.0 / h) * (y[0][1] + (2 * u - 1) * y[0][2] / 2.0 + (3 * u * u - 6 * u + 2) * y[0][3] / 6.0);
    
    if (n > 4) {
        result += (1.0 / h) * (4 * u * u * u - 18 * u * u + 22 * u - 6) * y[0][4] / 24.0;
    }
    
    cout << fixed << setprecision(6) << result << endl;
    
    return 0;
}

