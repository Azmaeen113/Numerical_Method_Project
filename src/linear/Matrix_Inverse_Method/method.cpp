#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> cofactor_matrix(const vector<vector<double>> &mat, int row, int col)
{
    int n = mat.size();
    vector<vector<double>> temp(n - 1, vector<double>(n - 1));
    int r = 0, c = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == row) continue;
        c = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == col) continue;
            temp[r][c++] = mat[i][j];
        }
        r++;
    }
    return temp;
}

double determinant(const vector<vector<double>> &mat)
{
    int n = mat.size();

    if (n == 1)
        return mat[0][0];

    if (n == 2)
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    double det = 0;
    int sign = 1;

    for (int i = 0; i < n; i++)
    {
        auto sub = cofactor_matrix(mat, 0, i);
        det += sign * mat[0][i] * determinant(sub);
        sign = -sign;
    }
    return det;
}

vector<vector<double>> adjoint(const vector<vector<double>> &mat)
{
    int n = mat.size();
    vector<vector<double>> adj(n, vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto sub = cofactor_matrix(mat, i, j);
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(sub);
        }
    }
    return adj;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<double>> mat(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    double det = determinant(mat);

    if (det == 0)
    {
        cout << "Inverse Doesn't Exist\n";
        return 0;
    }

    auto adj = adjoint(mat);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] / det << " ";
        cout << "\n";
    }

    return 0;
}
