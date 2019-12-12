// 实现区间加法

#include <iostream>

using namespace std;

const int MAXN = 1005;

int n;
int d[MAXN];
int num[MAXN];

void add(int l, int r, int x)
{
    d[l] += x;
    d[r + 1] -= x;
}

void getNum()
{
    for (int i = 1; i <= n; ++i)
        num[i] = num[i - 1] + d[i];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
        d[i] = num[i] - num[i - 1];
    }
    while (1)
    {
        int l, r, x;
        cin >> l >> r >> x;
        add(l, r, x);
        getNum();
        for (int i = 1; i <= n; ++i)
            cout << num[i] << " ";
    }
    return 0;
}
/*
5
1 2 3 4 5
*/