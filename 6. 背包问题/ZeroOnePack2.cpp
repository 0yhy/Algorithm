#include <iostream>

using namespace std;

const int MAXN = 105;
const int MAXC = 10005;
const int INF = 0x3f3f3f3f;

int N, V;
int c[MAXN], v[MAXN];
int f[MAXC];

void initialize()
{
    for (int i = 0; i <= N; ++i)
        f[i] = 0;
}
void initializeFull()
{
    f[0] = 0;
    for (int i = 1; i <= N; ++i)
        f[i] = -INF;
}

int main()
{
    cin >> N >> V;
    initialize();
    for (int i = 1; i <= N; ++i)
        cin >> c[i] >> v[i];
    for (int i = 1; i <= N; ++i)
        for (int j = V; j >= c[i]; --j)
            f[j] = max(f[j], f[j - c[i]] + v[i]);
    cout << f[V];
    return 0;
}