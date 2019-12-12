#include <iostream>

using namespace std;

const int MAXM = 101;
const int MAXT = 1001;

int T, M;
int t[MAXM], v[MAXM];
int f[MAXT];

int main ()
{
    cin >> T >> M;
    for (int i = 1; i <= M; ++i) { cin >> t[i] >> v[i]; }
    for (int i = 1; i <= M; ++i)
        for (int j = T; j >= t[i]; --j)
        {
            f[j] = max (f[j], f[j - t[i]] + v[i]);
        }
    cout << f[T];
    return 0;
}
