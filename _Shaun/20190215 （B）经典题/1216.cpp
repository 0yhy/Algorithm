#include <iostream>

using namespace std;

const int MAXN = 1005;

int r;
int a[MAXN][MAXN];
int f[MAXN][MAXN];

int main()
{
    cin >> r;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= i; ++j)
        {
            cin >> a[i][j];
        }
    for (int i = r; i >= 1; --i)
        for (int j = 1; j <= r; ++j)
        {
            f[i][j] = a[i][j] + max (f[i + 1][j], f[i + 1][j + 1]);
        }
    cout << f[1][1];
    return 0;
}
