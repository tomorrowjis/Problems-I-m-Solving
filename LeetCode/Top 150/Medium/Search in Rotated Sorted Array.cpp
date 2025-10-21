class Solution {
public:
    int search(vector<int>& nums, int target)
{
    int n = nums.size();
    int last_val = nums[n-1];

    int st = 0;
    int en = n-1;

    int mid = n-1;
    while(st<=en)
    {
        mid = (st + en) / 2;
        if(mid<n-1 && nums[mid+1]<nums[mid])
        {
            break;
        }
        else if(mid<n-1 && nums[mid+1]>nums[mid])
        {
            if(nums[mid]>last_val) st = mid + 1;
            else if(nums[mid] < last_val) en = mid - 1;
        }
        else if(mid == n-1) en = mid - 1;
    }

    if(mid == 0)
    {
        if(nums[mid]==target)return mid;
        else
        {

            st = 1;
            en = n-1;

            while(st <= en)
            {
                mid = (st + en)/2;
                if(target == nums[mid])return mid;
                else if(target<nums[mid]) en = mid - 1;
                else st = mid + 1;
            }
            return -1;
        }
    }
    else
    {
        if(nums[0]<=target && nums[mid]>=target)
        {
            st = 0;
            en = mid;
        }
        else
        {
            st = mid + 1;
            en = n - 1;
        }

        while(st <= en)
        {
            mid = (st + en)/2;
            if(target == nums[mid])return mid;
            else if(target<nums[mid]) en = mid - 1;
            else st = mid + 1;
        }
        return -1;


    }

    return mid;

  }
};
