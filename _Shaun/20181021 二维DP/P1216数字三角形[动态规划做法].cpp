#include <iostream>

using namespace std;

const int MAXN = 1005;

int n;
int a[MAXN][MAXN], f[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio (false); //加快cin/cout,但这句话不要与scanf/printf/getchar/putchar等标准输入输出函数同时使用
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) //数字三角形第i行有i个数字,所以内层循环从1到i
            cin >> a[i][j];
    for (int j = 1; j <= n; ++j) f[n][j] = a[n][j];//初始值,最后一排的数字到底部最大值当然是本身
    for (int i = n - 1; i >= 1; --i) //最后一排求过了,没有必要再求一次,所以从倒数第二排开始
        for (int j = 1; j <= i; ++j) //j不会超过i
            f[i][j] = max (f[i + 1][j], f[i + 1][j + 1]) + a[i][j];//状态转移方程
    cout << f[1][1] << endl;
    return 0;
}
