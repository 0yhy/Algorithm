#include <cstdio>

using namespace std;

struct Point
{
    double x, y;
};

double dist (Point a, Point b)
{
    return sqrt ( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

const int MAXN = 20;
const int INF = 0x7fffffff;

int n;
Point p[MAXN];
double dis[MAXN][MAXN];
bool vis[MAXN];
double ans = INF;

void dfs (int cur, int num, double sum)
{
    //printf("开始深搜：当前节点编号 %d\n当前已访问节点数 %d\n当前总路程 %lf\n",cur,num,sum);
    if (num == n)
    {
        //printf("\n\n已访问完成所有节点！更新距离最小值为%lf\n\n",sum);
        ans = min (ans, sum);
    }
    if (sum > ans) { return; }
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
        {
            //printf("当前第%d号节点未访问，从此节点继续搜索\n",i);
            vis[i] = true;
            dfs (i, num + 1, sum + dis[cur][i]);
            vis[i] = false;
        }
}
int main()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%lf%lf", &p[i].x, &p[i].y);
        for (int j = 0; j < i; ++j)
        {
            double d = dist (p[i], p[j]);
            dis[i][j] = dis[j][i] = d;
        }
    }
    dfs (0, 0, 0);
    printf ("%.2lf", ans);
    return 0;
}
