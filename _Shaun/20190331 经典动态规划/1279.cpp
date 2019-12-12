#include <iostream>
#include <cmath>

using namespace std;

const int MAXL = 2005;

int f[MAXL][MAXL];
string a, b;
int l1, l2;
int k;

int main()
{
    cin >> a >> b >> k;
    l1 = a.size(), l2 = b.size();
    a = " " + a, b = " " + b;
    for (int i = 1; i <= l1; i++)
    {
        f[i][0] = f[i - 1][0] + k;
    }
    for (int i = 1; i <= l2; i++)
    {
        f[0][i] = f[0][i - 1] + k;
    }
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            f[i][j] = min (f[i - 1][j] + k, min (
                               f[i][j - 1] + k,
                               f[i - 1][j - 1] + abs (a[i] - b[j])
                           ));
        }
    }
    cout << f[l1][l2] << endl;
    return 0;
}
