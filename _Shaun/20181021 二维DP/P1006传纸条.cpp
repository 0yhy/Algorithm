#include <iostream>

using namespace std;

inline int max (int a, int b, int c, int d, int e)
{
    if (a < b) a = b;
    if (a < c) a = c;
    if (a < d) a = d;
    if (a < e) a = e;
    return a;
}

const int MAXN = 51;

int n, m;
int a[MAXN][MAXN], f[MAXN][MAXN][MAXN][MAXN];

int main()
{
    ios::sync_with_stdio (false);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= m; ++k)
                for (int l = 1; l <= n; ++l)
                {
                    f[i][j][k][l] = max (f[i][j][k][l], f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1], f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]) + a[i][j] + a[k][l];
                    if (i == k && j == l) f[i][j][k][l] -= a[i][j];
                }
    cout << f[m][n][m][n];
    return 0;
}