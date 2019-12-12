#include <iostream>

using namespace std;

const int M = 1005;
const int f[] = {0, 1, 2, 3, 5, 10, 20};

int a1, a2, a3, a4, a5, a6;
int b[M];
int ans = 0;

int main()
{
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    for (int i1 = 0; i1 <= a1; ++i1)
        for (int i2 = 0; i2 <= a2; ++i2)
            for (int i3 = 0; i3 <= a3; ++i3)
                for (int i4 = 0; i4 <= a4; ++i4)
                    for (int i5 = 0; i5 <= a5; ++i5)
                        for (int i6 = 0; i6 <= a6; ++i6)
                        {
                            b[i1 + i2 * 2 + i3 * 3 + i4 * 5 + i5 * 10 + i6 * 20] = 1;
                        }
    for (int i = 1; i < M; ++i)
    {
        ans += b[i];
    }
    cout << "Total=" << ans << endl;
    return 0;
}