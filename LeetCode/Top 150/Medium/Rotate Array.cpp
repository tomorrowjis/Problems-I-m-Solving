#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{

    if (k <= nums.size())
    {
        vector<int> store_k;

        for (int i = nums.size() - k; i < nums.size(); i++)
        {
            store_k.push_back(nums[i]);
        }

        for (int i = nums.size() - k - 1; i >= 0; i--)
        {
            swap(nums[i], nums[i + k]);
        }

        for (int i = 0; i < store_k.size(); i++)
        {
            nums[i] = store_k[i];
        }
    }
    else
    {
        int n = nums.size();
        int r = k % n;
        k = r;

        vector<int> store_k;

        for (int i = nums.size() - k; i < nums.size(); i++)
        {
            store_k.push_back(nums[i]);
        }

        for (int i = nums.size() - k - 1; i >= 0; i--)
        {
            swap(nums[i], nums[i + k]);
        }

        for (int i = 0; i < store_k.size(); i++)
        {
            nums[i] = store_k[i];
        }
    }
}

int main()
{
    vector<int> p = {1, 2};
    rotate(p, 3);

    for (auto x : p)
        cout << x << " ";
    cout << endl;
}
