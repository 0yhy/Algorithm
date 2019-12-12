#include <iostream>
#include <cstring>

using namespace std;

const int MAXC = 2000005;
const int INF = 0x3f3f3f3f;

int k, n;
int f[MAXC];//f[i]表示构成面值为i至少需要的邮票数

int main()
{
    memset (f, INF, sizeof (f));
    cin >> k >> n;
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        for (int j = x; j < MAXC; ++j)
            if (f[j - x] + 1 <= k)
            {
                f[j] = min (f[j], f[j - x] + 1);
            }
    }
    for (int i = 1; i < MAXC; ++i)
        if (f[i] == INF)
        {
            cout << i - 1 << endl;
            return 0;
        }
    return 0;
}
