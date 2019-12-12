#include <iostream>

using namespace std;

int max (int a, int b, int c, int d)
{
    if (a < b) a = b;
    if (a < c) a = c;
    if (a < d) a = d;
    return a;
}

const int MAXN = 10;

int n;
int x, y, z;
int a[MAXN][MAXN], f[MAXN][MAXN][MAXN][MAXN];

int main()
{
    ios::sync_with_stdio (false);
    cin >> n;
    while (cin >> x >> y >> z)
    {
        if (!x && !y && !z) break;
        a[x][y] = z;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                for (int l = 1; l <= n; ++l)
                {
                    f[i][j][k][l] = max (f[i - 1][j][k][l - 1], f[i - 1][j][k - 1][l], f[i][j - 1][k][l - 1], f[i][j - 1][k - 1][l]) + a[i][j] + a[k][l];
                    if (i == k && j == l) f[i][j][k][l] -= a[i][j];
                }
    cout << f[n][n][n][n];
    return 0;
}