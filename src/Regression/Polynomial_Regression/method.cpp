#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> x(n), y(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    double sx = 0, sx2 = 0, sx3 = 0, sx4 = 0, sy = 0, sxy = 0, sx2y = 0;
    for (int i = 0; i < n; i++) {
        sx += x[i];
        sy += y[i];
        sx2 += x[i] * x[i];
        sx3 += x[i] * x[i] * x[i];
        sx4 += x[i] * x[i] * x[i] * x[i];
        sxy += x[i] * y[i];
        sx2y += x[i] * x[i] * y[i];
    }
    
    double A[3][4] = {{n, sx, sx2, sy}, {sx, sx2, sx3, sxy}, {sx2, sx3, sx4, sx2y}};
    
    for (int i = 0; i < 3; i++) {
        double d = A[i][i];
        for (int j = 0; j < 4; j++) {
            A[i][j] /= d;
        }
        for (int k = 0; k < 3; k++) {
            if (k == i) continue;
            double f = A[k][i];
            for (int j = 0; j < 4; j++) {
                A[k][j] -= f * A[i][j];
            }
        }
    }
    
    double a = A[0][3], b = A[1][3], c = A[2][3];
    
    double v;
    cin >> v;
    
    double result = a + b * v + c * v * v;
    cout << fixed << setprecision(6) << result << endl;
    
    return 0;
}

