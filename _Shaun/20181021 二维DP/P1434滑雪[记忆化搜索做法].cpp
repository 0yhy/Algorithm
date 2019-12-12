#include <iostream>

using namespace std;

const int MAXN = 105;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int r, c, ans;
int h[MAXN][MAXN], f[MAXN][MAXN];

int dfs (int cr, int cc)
{
    if (f[cr][cc]) return f[cr][cc];
    else
    {
        int t = 1;//��СҲҪΪ1,��Ȼ��͵ĵ�Ϊ0�Ļ��𰸻����
        for (int i = 0; i < 4; ++i)//ö�����ڵ�
        {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (h[cr][cc] < h[nr][nc] && nr >= 1 && nr <= r && nc >= 1 && nc <= c)
                t = max (dfs (nr, nc) + 1, t);
        }
        return f[cr][cc] = t;
    }
}
int main()
{
    ios::sync_with_stdio (false);
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> h[i][j];
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            ans = max (dfs (i, j), ans);
    cout << ans << endl;
    return 0;
}