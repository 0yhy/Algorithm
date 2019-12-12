#include <iostream>

using namespace std;

const int MAXN = 1000005;

int T, M;
int t[MAXN], v[MAXN];
int f[MAXN];

int main ()
{
    cin >> T >> M;
    for (int i = 1; i <= M; ++i) { cin >> t[i] >> v[i]; }
    for (int i = 1; i <= M; ++i)
        for (int j = t[i]; j <= T; ++j)
        {
            f[j] = max (f[j], f[j - t[i]] + v[i]);
        }
    cout << f[T] << endl;
    return 0;
}
