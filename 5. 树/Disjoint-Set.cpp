#include <iostream>

using namespace std;

const int MAXN = 1005;

int n, m;
int sum;
int f[MAXN];

int findFather(int x)
{
    if (x == f[x])
        return x;
    else
        return f[x] = findFather(f[x]);
}

void joint(int x, int y)
{
    x = findFather(x), y = findFather(y);
    if (x != y)
        f[x] = y;
}

int main()
{
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        joint(x, y);
    }
    for (int i = 1; i <= n; ++i)
        if (f[i] == i)
            ++sum;
    cout << sum;
    return 0;
}