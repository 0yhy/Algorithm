#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;
const int INF = 0x3f3f3f3f;

int n, m, start;
bool vis[MAXN];
int dist[MAXN];

struct Edge
{
    int to, length;
    Edge(int t = 0, int l = 0) : to(t), length(l) {}
};
vector<Edge> e[MAXN];

void addEdge(int x, int y, int length)
{
    e[x].push_back(Edge(y, length));
}

struct Node
{
    int dist, index;
    Node(int d = 0, int i = start) : dist(d), index(i) {}
    bool operator<(const Node &x) const
    {
        return x.dist < dist;
    }
};
priority_queue<Node> q;

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
    // {
    //     dist[e[start][i].to] = e[start][i].length;
    //     q.push(Node(dist[e[start][i].to, e[start][i].to]));
    // }
    // vis[start] = true;
    dist[start] = 0;
    q.push(Node(0, start));

    while (!q.empty())
    {
        int now = q.top().index;
        q.pop();
        if (!vis[now])
        // continue;
        {
            vis[now] = true;
            for (int i = 0; i < e[now].size(); ++i)
            {
                int next = e[now][i].to;
                if (dist[next] > dist[now] + e[now][i].length)
                {
                    dist[next] = dist[now] + e[now][i].length;
                    q.push(Node(dist[next], next));
                }
            }
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