#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1005;
const int MAXM = 10005;

struct Edge
{
    int to, length;
    Edge(int t = 0, int l = 0) : to(t), length(l) {}
};
vector<Edge> e[MAXN];

int n, m;
bool bfs_vis[MAXN];
bool dfs_vis[MAXN];

void addEdge(int x, int y, int length)
{
    e[x].push_back(Edge(y, length));
}

void dfs(int now)
{
    cout << now << " ";
    for (int i = 0; i < e[now].size(); ++i)
    {
        int next = e[now][i].to;
        if (!dfs_vis[next])
        {
            dfs_vis[next] = true;
            dfs(next);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    bfs_vis[start] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        cout << now << " ";
        for (int i = 0; i < e[now].size(); ++i)
        {
            int next = e[now][i].to;
            if (!bfs_vis[next])
            {
                q.push(next);
                bfs_vis[next] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, l;
        cin >> x >> y >> l;
        addEdge(x, y, l);
        addEdge(y, x, l);
    }
    dfs_vis[1] = true;
    dfs(1);
    bfs(1);
}

/*
5 4
1 2 1
2 4 3
1 3 2
5 3 5
*/