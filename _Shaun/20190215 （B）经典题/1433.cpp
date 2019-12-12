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
    //printf("��ʼ���ѣ���ǰ�ڵ��� %d\n��ǰ�ѷ��ʽڵ��� %d\n��ǰ��·�� %lf\n",cur,num,sum);
    if (num == n)
    {
        //printf("\n\n�ѷ���������нڵ㣡���¾�����СֵΪ%lf\n\n",sum);
        ans = min (ans, sum);
    }
    if (sum > ans) { return; }
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
        {
            //printf("��ǰ��%d�Žڵ�δ���ʣ��Ӵ˽ڵ��������\n",i);
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
