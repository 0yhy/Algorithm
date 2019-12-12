#include <iostream>

using namespace std;

const int MAXN = 105;
const int MAXC = 1005;
const int INF = 0x3f3f3f3f;

int N, V;
int c[MAXN], v[MAXN];
int f[MAXN][MAXC];

void initiaize() // 不用恰好装满
{
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= V; ++j)
            f[i][j] = 0;
}
void initializeFull() // 恰好装满
{
    f[0][0] = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= V; ++j)
            f[i][j] = -INF;
}

int main()
{
    cin >> N >> V;
    initiaize();
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= V; ++j)
            if (c[i] < j)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - c[i]] + v[i]);
            else
                f[i][j] = f[i - 1][j];
    }
    cout << f[N][V];
    return 0;
}