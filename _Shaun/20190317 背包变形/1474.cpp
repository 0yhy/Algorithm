#include <iostream>

using namespace std;

typedef long long LL;

const int MAXV = 30, MAXN = 10005;

int v, n;
LL h[MAXV], f[MAXN] = {1};

int main()
{
    cin >> v >> n;
    for (int i = 1; i <= v; ++i) { cin >> h[i]; }
    for (int i = 1; i <= v; ++i)
        for (int j = h[i]; j <= n; ++j)
        {
            f[j] += f[j - h[i]];
        }
    cout << f[n];
    return 0;
}
