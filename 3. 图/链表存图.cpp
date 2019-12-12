#include <iostream>

using namespace std;

const int MAXN = 1000;
const int MAXM = 100000;

struct Edge
{
    int to, next;
    Edge(int t = 0, int n = 0) : to(t), next(n){};
};
Edge e[MAXM];

int ecnt;
int head[MAXN];

int n, m, start;

void addEdge(int x, int y)
{
    e[++ecnt] = Edge(y, head[x]);
    head[x] = ecnt;
}

int main()
{
    cin >> n >> m >> start;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
        addEdge(y, x);
    }
    //遍历start的每一条边
    for (int i = head[start]; i; i = e[i].next)
    {
        cout << i << " ";
    }
}