#include <iostream>

using namespace std;

const int MAXN = 1005;
const int MAXM = 505;

int n;
int preSum[MAXN];
int num[MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
        preSum[i] = preSum[i - 1] + num[i];
    }
    for (int i = 1; i <= n; ++i)
        cout << preSum[i] << " ";
    return 0;
}