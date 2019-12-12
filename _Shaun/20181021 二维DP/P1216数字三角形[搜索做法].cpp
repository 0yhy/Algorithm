#include <iostream>

using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int n, ans = -INF; //ans预设一个极小值,便于取出极大值
int a[MAXN][MAXN];

void dfs (int i, int j, int sum) //当前位置在a[i][j],当前路径数字总和为sum(尚未加上当前数字)
{
    if (i == n)
        ans = max (ans, sum + a[i][j]);
    else
        dfs (i + 1, j, sum + a[i][j]), dfs (i + 1, j + 1, sum + a[i][j]);
}

int main()
{
    ios::sync_with_stdio (false); //加快cin/cout,但这句话不要与scanf/printf/getchar/putchar等标准输入输出函数同时使用
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) //数字三角形第i行有i个数字,所以内层循环从1到i
            cin >> a[i][j];
    dfs (1, 1, 0);
    cout << ans << endl;
    return 0;
}
