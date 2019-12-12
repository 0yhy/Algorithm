#include <iostream>

using namespace std;

const int MAXM = 101;
const int MAXT = 1001;

int T, M;
int t[MAXM], v[MAXM];
int f[MAXM][MAXT];

int main ()
{
    cin >> T >> M;
    for (int i = 1; i <= M; ++i) { cin >> t[i] >> v[i]; }
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= T; ++j)
            if (t[i] <= j) { f[i][j] = max (f[i - 1][j], f[i - 1][j - t[i]] + v[i]); }
            else { f[i][j] = f[i - 1][j]; }
    cout << f[M][T];
    return 0;
}
