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

    double h = x[1] - x[0];
    
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    cout << "\nBackward Difference Table:" << endl;
    cout << setw(10) << "x" << setw(10) << "y";
    for (int j = 1; j < n; j++) {
        cout << setw(12) << "∇^" << j << "y";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(10) << x[i];
        for (int j = 0; j <= i; j++) {
            cout << setw(12) << fixed << setprecision(4) << y[i][j];
        }
        cout << endl;
    }

    double xp;
    cout << "\nEnter the value of x for interpolation: ";
    cin >> xp;

    double u = (xp - x[n - 1]) / h;
    double result = y[n - 1][0];
    double u_term = u;
    double factorial = 1;

    for (int j = 1; j < n; j++) {
        factorial *= j;
        result += (u_term * y[n - 1][j]) / factorial;
        u_term *= (u + j);
    }

    cout << "\nInterpolated value at x = " << xp << " is: " << fixed << setprecision(6) << result << endl;

    return 0;
}
