#include <iostream>
#include <bitset>

using namespace std;

const int MAXN = 6, MAXM = 1005;

int a[MAXN], w[MAXN] = {1, 2, 3, 5, 10, 20};
bitset<MAXM> S;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    S[0] = 1;
    for (int i = 0; i < 6; i++)
        for (int j = 1; j <= a[i]; j++)
        {
            S |= S << w[i];
        }
    cout << "Total=" << S.count() - 1 << endl;
    return 0;
}
