#include <iostream>

using namespace std;

const int MAXN = 21, MAXM = 20000001;

int n, b, m, sum = 0;
int h[MAXN], f[MAXM];

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
        sum += h[i];
    }
    m = sum - b;
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= h[i]; --j)
        {
            f[j] = max (f[j], f[j - h[i]] + h[i]);
        }
    cout << m - f[m] << endl;
    return 0;
}
