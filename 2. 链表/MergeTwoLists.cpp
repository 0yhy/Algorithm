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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val > l2->val)
        swap(l1, l2);
    ListNode *head = new ListNode(l1->val, NULL);
    ListNode *p = head;
    l1 = l1->next;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            ListNode *q = new ListNode(l1->val, NULL);
            l1 = l1->next;
            p->next = q;
        }
        else
        {
            ListNode *q = new ListNode(l2->val, NULL);
            l2 = l2->next;
            p->next = q;
        }
        p = p->next;
    }
    if (l1)
        p->next = l1;
    if (l2)
        p->next = l2;
    return head;
}
ListNode *mergeKLists(vector<ListNode *> &Lists)
{
    int arrSize = Lists.size();
    // cout << "arrsize:" << arrSize << endl;
    int cnt = 1;
    int totalCnt = arrSize;
    while (cnt < arrSize)
    {
        // cout << "cnt:" << cnt << endl;
        for (int i = 0; i + cnt < (totalCnt % 2 ? arrSize - 1 : arrSize); i += cnt * 2)
        {
            // cout << "i:" << i << endl;
            Lists[i] = mergeTwoLists(Lists[i], Lists[i + cnt]);
        }
        cnt *= 2;
        totalCnt = totalCnt / 2 + totalCnt % 2;
    }
    return Lists[0];
}

int main()
{
    srand(time(NULL));
    int arrSize = 5;
    vector<ListNode *> Lists;
    for (int i = 0; i < arrSize; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < 5; ++j)
            tmp.push_back(rand() % 10);
        sort(tmp.begin(), tmp.end());
        Lists.push_back(buildList(tmp));
    }
    for (int i = 0; i < arrSize; ++i)
        traverse(Lists[i]);
    mergeKLists(Lists);
    traverse(Lists[0]);
}