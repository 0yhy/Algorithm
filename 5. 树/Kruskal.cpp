#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 10005;
const int MAXM = 1000005;

struct Edge
{
    int from, to, weight;
    Edge(int f = 0, int t = 0, int w = 0) : from(f), to(t), weight(w){};
    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
} e[MAXM];

int n, m;
int sum;
int f[MAXN];

int findFather(int x)
{
    if (x == f[x])
        return x;
    else
        return f[x] = findFather(f[x]);
}
void joint(int x, int y)
{
    x = findFather(x), y = findFather(y);
    if (x != y)
        f[x] = y;
}

void Kruskal()
{
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; ++i)
    {
        int x = e[i].from;
        int y = e[i].to;
        if (findFather(x) != findFather(y))
        {
            joint(x, y);
            sum += e[i].weight;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> e[i].from, e[i].to, e[i].weight;
    Kruskal();
    cout << sum;
    return 0;
}