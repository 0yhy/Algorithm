/*
    给定一个数组 vector<int> nums
    给定一个目标数 target
    找出所有满足条件的三个数 使得这三个数的和 = target
*/
/*
    双指针法：固定一个数 从后面的数开始用双指针寻找符合条件的数
*/
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data_, Node *next_ = nullptr) : data(data_), next(next_) {}
};

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.size() < 3)
        return ans;
    map<vector<int>, bool> m;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        int start = i + 1;
        int end = nums.size() - 1;
        while (start < end)
        {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum < 0)
                ++start;
            else if (sum > 0)
                --end;
            else
            {
                if (!m[vector<int>{nums[i], nums[start], nums[end]}])
                {
                    m[vector<int>{nums[i], nums[start], nums[end]}] = true;
                    ans.push_back({nums[i], nums[start], nums[end]});
                }
                ++start;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}