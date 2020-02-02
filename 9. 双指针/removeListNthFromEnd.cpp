/* 删除链表的第倒数第n个元素 */

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data_, Node *next_) : data(data_), next(next_) {}
};

Node *buildList(vector<int> &nums)
{
    Node *head = new Node(nums[0], NULL);
    Node *p = head;
    for (int i = 1; i < nums.size(); ++i)
    {
        Node *q = new Node(nums[i], NULL);
        p->next = q;
        p = p->next;
    }
    return head;
}

Node *removeListNthFromEnd(Node *head, int n)
{
    Node *p = head, *q = head;
    Node *fp = new Node(0, p);
    for (int i = 1; i <= n; ++i)
        q = q->next;
    while (q)
    {
        fp = p;
        p = p->next;
        q = q->next;
    }
    if (head == p)
        head = head->next;
    else
        fp->next = p->next;
    delete p;
    return head;
}

void traverse(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 6};
    Node *list = buildList(nums);
    traverse(list);
    removeListNthFromEnd(list, 3);
    traverse(list);
    return 0;
}