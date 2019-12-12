#include <iostream>

using namespace std;

const int MAXN = 201;

int n, m, t;
int f[MAXN][MAXN];

int main()
{
    cin >> n >> m >> t;
    while (n--) ///我这里没有存，直接读一组做一组，顺便滚动数组优化空间
    {
        int x, y;
        cin >> x >> y;
        for (int j = m; j >= x; --j)
            for (int k = t; k >= y; --k)
            {
                f[j][k] = max (f[j][k], f[j - x][k - y] + 1);
            }
    }
    cout << f[m][t];
}
