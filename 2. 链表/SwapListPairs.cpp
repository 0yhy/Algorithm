#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data_, ListNode *next_) : val(data_), next(next_) {}
};

ListNode *buildList(vector<int> &nums)
{
    ListNode *head = new ListNode(nums[0], NULL);
    ListNode *p = head;
    for (int i = 1; i < nums.size(); ++i)
    {
        ListNode *q = new ListNode(nums[i], NULL);
        p->next = q;
        p = p->next;
    }
    return head;
}
void traverse(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *swapPairs(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *curp = head;
    ListNode *fp = nullptr;
    head = head->next;
    while (curp->next)
    {
        ListNode *p = curp;
        ListNode *q = curp->next;
        p->next = q->next;
        q->next = p;
        if (fp)
            fp->next = q;
        if (p->next)
        {
            curp = p->next;
            fp = p;
        }
    }
    return head;
}

int main()
{
    srand(time(NULL));
    vector<int> v;
    int arrSize = 0;
    for (int i = 0; i < arrSize; ++i)
        v.push_back(rand() % 20);
    ListNode *l = buildList(v);
    traverse(l);
    traverse(swapPairs(l));
}