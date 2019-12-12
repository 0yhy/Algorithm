/*
  Floyd
  邻接矩阵存图 可以有负权边
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100;
const int INF = 0x3f3f3f3f;

int dist[MAXN][MAXN];
int n, m;

void addEdge(int x, int y, int length)
{
    dist[x][y] = length;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, l;
        cin >> x >> y >> l;
        addEdge(x, y, l);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}

/*
4 8
1 2 2
1 3 6
2 3 3
3 1 7
3 4 1
4 3 12
1 4 4
4 1 5
*/
