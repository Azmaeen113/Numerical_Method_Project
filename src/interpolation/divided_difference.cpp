#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[20], y[20][20];
    
    cout << "Enter the data points (x and y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] and y[" << i << "]: ";
        cin >> x[i] >> y[i][0];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    cout << "\nDivided Difference Table:" << endl;
    cout << setw(10) << "x" << setw(12) << "y";
    for (int j = 1; j < n; j++) {
        cout << setw(15) << "DD[" << j << "]";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(10) << fixed << setprecision(4) << x[i];
        for (int j = 0; j < n - i; j++) {
            cout << setw(15) << fixed << setprecision(6) << y[i][j];
        }
        cout << endl;
    }

    double xp;
    cout << "\nEnter the value of x for interpolation: ";
    cin >> xp;

    double result = y[0][0];
    double term = 1.0;

    for (int j = 1; j < n; j++) {
        term *= (xp - x[j - 1]);
        result += term * y[0][j];
    }

    cout << "\nInterpolated value at x = " << xp << " is: " << fixed << setprecision(6) << result << endl;

    return 0;
}
