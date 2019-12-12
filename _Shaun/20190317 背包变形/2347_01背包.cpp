#include<iostream>

using namespace std;

const int MAXN = 6, MAXM = 1005;
const int b[] = {0, 1, 2, 3, 5, 10, 20};

int n = 0, m = MAXM - 5;
int c[MAXM], f[MAXM];
int ans = 0;

int main()
{
    for (int i = 1; i <= MAXN; ++i)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; ++j)
        {
            c[++n] = b[i];
        }
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= c[i]; --j)
        {
            f[j] |= f[j - c[i]];
        }
    for (int i = 1; i <= m; ++i)
    {
        ans += f[i];
    }
    cout << "Total=" << ans << endl;
    return 0;
}