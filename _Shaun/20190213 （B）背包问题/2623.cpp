#include <iostream>

using namespace std;

const int MAXN = 105, MAXM = 2005;

int n, m;
int idx[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
int f[MAXM];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> idx[i] >> a[i] >> b[i];
        if (idx[i] == 2) { cin >> c[i]; }
    }
    for (int i = 1; i <= n; ++i)
    {
        switch (idx[i])
        {
        case 1:
            for (int j = m; j >= 0; --j)
                for (int k = j; k >= 0; --k)
                {
                    f[j] = max (f[j], f[k] + a[i] * (j - k) * (j - k) - b[i] * (j - k));
                }
            break;
        case 2:
            for (int j = m; j >= b[i]; --j)
                for (int k = 1; k <= c[i]; ++k)
                    if (k * b[i] <= j) { f[j] = max (f[j], f[j - k * b[i]] + a[i] * k); }
            break;
        case 3:
            for (int j = b[i]; j <= m; ++j)
            {
                f[j] = max (f[j], f[j - b[i]] + a[i]);
            }
            break;
        }
    }
    cout << f[m] << endl;
    return 0;
}
