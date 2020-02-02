#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 10005;
const int MAXM = 20005;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int to, length;
    Edge(int t = 0, int l = 0) : to(t), length(l){};
};
vector<Edge> e[MAXN];

int dist[MAXN];
bool vis[MAXN]; //起点到该点的路径已经为确定值
int n, m;
int start;

void addEdge(int x, int y, int length)
{
    e[x].push_back(Edge(y, length));
}

int main()
{
    cin >> n >> m >> start;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, l;
        cin >> x >> y >> l;
        addEdge(x, y, l);
    }
    memset(dist, INF, sizeof(dist));
    // for (int i = 0; i < e[start].size(); ++i)
    //     dist[e[start][i].to] = e[start][i].length;
    dist[start] = 0;

    for (int k = 1; k <= n - 1; ++k)
    {
        int min_dist = INF;
        int now;
        for (int i = 1; i <= n; ++i)
            if (!vis[i] && dist[i] < min_dist)
            {
                min_dist = dist[i];
                now = i;
            }
        vis[now] = true;
        for (int i = 0; i < e[now].size(); ++i)
        {
            int next = e[now][i].to;
            if (dist[now] + e[now][i].length < dist[next])
                dist[next] = dist[now] + e[now][i].length;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << dist[i] << " ";
    return 0;
}

/*
4 8 2
1 2 2
1 3 6
2 3 3
3 1 7
3 4 1
4 3 12
1 4 4
4 1 5
*/