#include <iostream>
#include <cstring>

#define max(a,b) ((a)<(b)?(b):(a))

using namespace std;

const int MAXL = 40;
const int MAXN = 81;

void max2(int x,int y)
{

}
int max3(int x,int y,int z)
{

}

struct Bigint//高精度类
{
    int a[MAXL];
    static const int MAX_INT_LENGTH = 10;
    Bigint()
    {
        memset (a, 0, sizeof (a));
    }
    Bigint (int n)
    {
        memset (a, 0, sizeof (a));
        *this = n;
    }
    int& operator [] (int i)
    {
        return a[i];
    }
    int size()
    {
        return a[0];
    }
    void resize (int n)
    {
        a[0] = n;
    }
    Bigint operator = (int n)
    {
        do
        {
            a[++a[0]] = n % 10;
            n /= 10;
        }
        while (n);
        return *this;
    }
    Bigint operator = (const string &s)
    {
        resize (s.size());
        for (int i = 1; i <= size(); ++i)
            a[i] = s[size() - i] - 48;
        return *this;
    }
    Bigint operator + (Bigint &b)
    {
        if (a[0] < b[0]) return b + *this;
        Bigint c;
        c.resize (a[0]);
        for (int i = 1; i <= b[0]; ++i)
        {
            c[i] += a[i] + b[i];
            if (c[i] >= 10)
            {
                c[i + 1] += c[i] / 10;
                c[i] %= 10;
            }
        }
        for (int i = b[0] + 1; i <= a[0]; ++i)
        {
            c[i] += a[i];
            if (c[i] >= 10)
            {
                c[i + 1] += c[i] / 10;
                c[i] %= 10;
            }
        }
        if (c[c[0] + 1])++c[0];
        return c;
    }
    Bigint operator += (Bigint &b)
    {
        return *this = *this + b;
    }
    Bigint operator * (int n)
    {
        Bigint b;
        b.resize (a[0]);
        for (int i = 1; i <= size(); ++i) b[i] = a[i] * n;
        for (int i = 1; i <= b[0] + MAX_INT_LENGTH; ++i)
            if (b[i] >= 10)
            {
                b[i + 1] += b[i] / 10;
                b[i] %= 10;
            }
        for (int i = b[0] + MAX_INT_LENGTH; i >= 1; --i)
            if (b[i])
            {
                b.resize (i);
                break;
            }
        return b;
    }
    bool operator < (Bigint b)
    {
        if (size() < b.size()) return true;
        else if (size() > b.size()) return false;
        else for (int i = size(); i >= 1; --i)
                if (a[i] > b[i]) return false;
                else if (a[i] < b[i]) return true;
        return false;
    }
};
ostream& operator << (ostream &out, Bigint a)
{
    for (int i = a.size(); i >= 1; --i)
        out << a[i];
    return out;
}
istream& operator >> (istream &in, Bigint &a)
{
    string s;
    in >> s;
    a = s;
    return in;
}

int n, m;
Bigint f[MAXN][MAXN];
Bigint ans;

int main()
{
    cin >> n >> m;
    for (int k = 1; k <= n; ++k) //每一行相互独立，分别处理
    {
        Bigint a[MAXN];
        for (int i = 1; i <= m; ++i)
        {
            cin >> a[i];
            f[i][i] = a[i] * 2;//初始化
        }
        for (int l = 1; l < m; ++l)
            for (int i = 1; i + l <= m; ++i)
            {
                //状态转移方程 f[i][j]=max(a[i]+f[i+1][j],a[j]+f[i][j-1])*2
                int j = i + l;
                f[i][j] = max (a[i] + f[i + 1][j], a[j] + f[i][j - 1]) * 2;
            }
        ans += f[1][m];
        memset (f, 0, sizeof (f));
    }
    cout << ans;
    return 0;
}