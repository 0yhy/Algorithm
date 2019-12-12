#include <algorithm>
#include <iostream>

using namespace std;

int func (int x)
{
    cout << x;
}

int func1 (int &x)
{
    cout << x;
}

struct Point
{
    int r, c, h;
    Point () : {}
    Point (int _r = 0, int _c = 0, int _h = 0) : r (_r), c (_c), h (_h) {}
    bool operator < (const Point &rhs) const//重载运算符,告诉编译器按照h的大小来比较两个Point,这一步是为了排序
    {
        return h < rhs.h;
    }
};

const int MAXN = 105;
const int dr[] = {-1, 0, 1, 0};//枚举位移量
const int dc[] = {0, 1, 0, -1};

int r, c, cnt, ans;
int h[MAXN][MAXN], f[MAXN][MAXN];
Point p[MAXN * MAXN];

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
        for (int j = 0; j < 4; ++j) //枚举四个相邻点
        {
            int nr = p[i].r + dr[j], nc = p[i].c + dc[j];
            if (p[i].h > h[nr][nc] && nr >= 1 && nr <= r && nc >= 1 && nc <= c) //当前点比相邻点高且枚举的相邻点要合法(不能越界)
                f[p[i].r][p[i].c] = max (f[p[i].r][p[i].c], f[nr][nc] + 1);
        }
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            ans = max (ans, f[i][j]);//统计答案
    cout << ans << endl;
    return 0;
}
