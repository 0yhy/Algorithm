#include <iostream>

using namespace std;

const int MAXN = 10005;

int heap[MAXN];
int n; //节点个数

void swap(int x, int y)
{
    int tmp = heap[x];
    heap[x] = heap[y];
    heap[y] = tmp;
}
void siftDown(int x)
{
    bool flag = true; //flag记录是否需要继续调整
    int min_node = x;
    while (x * 2 <= n && flag)
    {
        if (heap[x * 2] < heap[x])
            min_node = x * 2;
        if (x * 2 + 1 <= n && flag)
            if (heap[x * 2 + 1] < heap[min_node])
                min_node = x * 2 + 1;
        if (min_node != x)
        {
            swap(x, min_node);
            x = min_node;
        }
        else
            flag = false;
    }
}
void siftUp(int x)
{
    bool flag = true;
    while (x != 1 && flag)
    {
        if (heap[x] < heap[x / 2])
            swap(x, x / 2);
        else
            flag = false;
        x /= 2;
    }
}
void buildHeap() // O(n)
{
    for (int i = n / 2; i >= 1; --i)
        siftDown(i);
}

int main()
{
}