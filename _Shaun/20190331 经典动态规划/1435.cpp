#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXL = 1005;

char a[MAXL], b[MAXL];
int l;
int f[MAXL][MAXL];

int main()
{
    scanf ("%s", a + 1);
    l = strlen (a + 1);
    for (int i = 1; i <= l; ++i) { b[i] = a[l - i + 1]; }
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= l; ++j)
            if (a[i] == b[j])
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else
            {
                f[i][j] = max (f[i - 1][j], f[i][j - 1]);
            }
    cout << l - f[l][l] << endl;
    return 0;
}
