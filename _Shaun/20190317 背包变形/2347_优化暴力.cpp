#include <iostream>

using namespace std;

const int N = 6, M = 1005;
const int f[] = {0, 1, 2, 3, 5, 10, 20};

int a1, a2, a3, a4, a5, a6;
int b[M];
int ans = 0;

int main()
{
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    for (register int i6 = a6; i6 >= 0; --i6)
        for (register int i5 = a5; i5 >= 0; --i5)
            for (register int i4 = a4; i4 >= 0; --i4)
                for (register int i3 = a3; i3 >= 0; --i3)
                    for (register int i2 = a2; i2 >= 0; --i2)
                    {
                        register int i1 = a1;
                        int s = i2 * 2 + i3 * 3 + i4 * 5 + i5 * 10 + i6 * 20;
                        for (; i1 >= 7; i1 -= 8)
                        {
                            b[i1 + s] = 1;
                            b[i1 - 1 + s] = 1;
                            b[i1 - 2 + s] = 1;
                            b[i1 - 3 + s] = 1;
                            b[i1 - 4 + s] = 1;
                            b[i1 - 5 + s] = 1;
                            b[i1 - 6 + s] = 1;
                            b[i1 - 7 + s] = 1;
                        }
                        for (; i1 >= 0; --i1)
                        {
                            b[i1 + s] = 1;
                        }
                    }
    for (int i = 1; i < M; ++i)
    {
        ans += b[i];
    }
    cout << "Total=" << ans << endl;
    return 0;
}
