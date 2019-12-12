#include <iostream>

using namespace std;

const int MAXM = 11;
const int MAXT = 10000;

int n, m, k, r;
int sump = 0, sumt = 0;
int a[MAXM], t[MAXM], p[MAXM];
int N, V;
int f[MAXT], g[MAXT];

int main()
{
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n; ++i) { cin >> a[i]; }
    for (int i = 1; i <= m; ++i) { cin >> t[i]; sumt += t[i];}
    for (int i = 1; i <= m; ++i) { cin >> p[i]; sump += p[i];}
    N = m, V = sump - k;
    for (int i = 1; i <= N; ++i)
        for (int j = V; j >= p[i]; --j)
        {
            f[j] = max (f[j], f[j - p[i]] + t[i]);
        }
    N = n, V = r - sumt + f[V];
    for (int i = 1; i <= N; ++i)
        for (int j = V; j >= a[i]; --j)
        {
            g[j] = max (g[j], g[j - a[i]] + 1);
        }
    cout << g[V] << endl;
    return 0;
}
