#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXL = 1005;

string a, b;
int l1, l2;
int c[MAXL][MAXL];

int main()
{
    //scanf ("%s%s", a + 1, b + 1);
    cin >> a >> b;
    l1 = a.size(), l2 = b.size();
    a = " " + a, b = " " + b;
    for (int i = 1; i <= l1; ++i)
        for (int j = 1; j <= l2; ++j)
            if (a[i] == b[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else
            {
                c[i][j] = max (c[i][j - 1], c[i - 1][j]);
            }
    cout << c[l1][l2] << endl;
    return 0;
}
