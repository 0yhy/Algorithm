#include <iostream>

using namespace std;

const int MAXN = 1000;

int data[MAXN];
int nxt[MAXN];

int cnt;
int head;

void traverse()
{
    for (int i = head; i; i = nxt[i])
        cout << data[i] << " ";
    cout << endl;
}

void pushFront(int x)
{
    data[++cnt] = x;
    nxt[cnt] = head;
    head = cnt;
}
void pushBack(int x)
{
    data[++cnt] = x;
    int p = head;
    while (nxt[p])
        p = nxt[p];
    nxt[p] = cnt;
}

int main()
{
    cin >> cnt;
    for (int i = 1; i <= cnt; ++i)
    {
        cin >> data[i];
        nxt[i] = i + 1;
    }
    nxt[cnt] = 0;
    head = 1;
    pushFront(4);
    for (int i = 1; i <= cnt; ++i)
        cout << nxt[i] << " ";
    cout << endl;
    pushBack(3);
    traverse();
    return 0;
}