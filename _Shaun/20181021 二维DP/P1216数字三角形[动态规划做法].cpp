#include <iostream>

using namespace std;

const int MAXN = 1005;

int n;
int a[MAXN][MAXN], f[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio (false); //�ӿ�cin/cout,����仰��Ҫ��scanf/printf/getchar/putchar�ȱ�׼�����������ͬʱʹ��
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) //���������ε�i����i������,�����ڲ�ѭ����1��i
            cin >> a[i][j];
    for (int j = 1; j <= n; ++j) f[n][j] = a[n][j];//��ʼֵ,���һ�ŵ����ֵ��ײ����ֵ��Ȼ�Ǳ���
    for (int i = n - 1; i >= 1; --i) //���һ�������,û�б�Ҫ����һ��,���Դӵ����ڶ��ſ�ʼ
        for (int j = 1; j <= i; ++j) //j���ᳬ��i
            f[i][j] = max (f[i + 1][j], f[i + 1][j + 1]) + a[i][j];//״̬ת�Ʒ���
    cout << f[1][1] << endl;
    return 0;
}
