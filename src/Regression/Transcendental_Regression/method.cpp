#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> x(n), y(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    double sx = 0, sy = 0, sxy = 0, sxx = 0;
    for (int i = 0; i < n; i++) {
        sx += x[i];
        sy += log(y[i]);
        sxy += x[i] * log(y[i]);
        sxx += x[i] * x[i];
    }
    
    double m = (n * sxy - sx * sy) / (n * sxx - sx * sx);
    double c = (sy - m * sx) / n;
    
    double v;
    cin >> v;
    
    double result = exp(c) * exp(m * v);
    cout << fixed << setprecision(6) << result << endl;
    
    return 0;
}

