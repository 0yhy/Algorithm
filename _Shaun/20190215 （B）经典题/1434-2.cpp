#include <iostream>

using namespace std;

const int MAXN = 105;

const int dx[] = {0, -1, 0, 1, 0};
const int dy[] = {0, 0, 1, 0, -1};

int r, c, ans;
int a[MAXN][MAXN], f[MAXN][MAXN];

int dfs (int cx, int cy)
{
    if (f[cx][cy]) { return f[cx][cy]; }
    int t = 1;
    for (int i = 1; i <= 4; ++i)
    {
        int nx = cx + dx[i], ny = cy + dy[i];
        if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && a[cx][cy] < a[nx][ny])
        {
            t = max (dfs (nx, ny) + 1, t);
        }
    }
    f[cx][cy] = t;
    return t;
}
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
        {
            cin >> a[i][j];
        }
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
        {
            ans = max (dfs (i, j), ans);
        }
    cout << ans;
    return 0;
}
