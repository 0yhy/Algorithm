#include <algorithm>
#include <iostream>

using namespace std;

struct Point
{
    int r, c, h;
    Point (int _r = 0, int _c = 0, int _h = 0) : r (_r), c (_c), h (_h) {}
    bool operator < (const Point &rhs) const
    {
        return h < rhs.h;
    }
};

const int MAXN = 105;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int r, c, cnt, ans;
int h[MAXN][MAXN], f[MAXN][MAXN];
Point p[MAXN *MAXN];

int main()
{
    ios::sync_with_stdio (false); //加快cin/cout,但这句话不要与scanf/printf/getchar/putchar等标准输入输出函数同时使用
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
        {
            cin >> h[i][j];
            p[++cnt] = Point (i, j, h[i][j]);
            f[i][j] = 1; //初始值
        }
    sort (p + 1, p + cnt + 1);
    for (int i = 1; i <= cnt; ++i)
        for (int j = 0; j < 4; ++j)
        {
            int nr = p[i].r + dr[j], nc = p[i].c + dc[j];
            if (p[i].h > h[nr][nc] && nr >= 1 && nr <= r && nc >= 1 && nc <= c)
            {
                f[p[i].r][p[i].c] = max (f[p[i].r][p[i].c], f[nr][nc] + 1);
            }
        }
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
        {
            ans = max (ans, f[i][j]);
        }
    cout << ans << endl;
    return 0;
}

