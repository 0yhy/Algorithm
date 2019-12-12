#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 10005;
const int MAXM = 50005;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int to, length;
    Edge(int t = 0, int l = 0) : to(t), length(l){};
};
vector<Edge> e[MAXN];

int n, m, start;
int dist[MAXN];

void addEdge(int x, int y, int length)
{
    e[x].push_back(Edge(y, length));
}

void BellonFord(int start)
{
    bool inq[MAXN];
    memset(dist, INF, sizeof(dist));
    memset(inq, false, sizeof(inq));
    dist[start] = 0;
    inq[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        inq[now] = false;
        for (int i = 0; i < e[now].size(); ++i)
        {
            int next = e[now][i].to;
            if (dist[next] > dist[now] + e[now][i].length)
            {
                dist[next] = dist[now] + e[now][i].length;
                if (!inq[next])
                {
                    q.push(next);
                    inq[next] = true;
                }
            }
        }
    }
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
    BellonFord(start);
    for (int i = 1; i <= n; ++i)
        dist[i] = dist[i] == INF ? 2147483647 : dist[i];
    for (int i = 1; i <= n; ++i)
        cout << dist[i] << " ";
    return 0;
}