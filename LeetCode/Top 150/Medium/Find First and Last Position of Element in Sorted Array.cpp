class Solution {
public:
   vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.empty())return {-1, -1};


        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(first == nums.size()) first--;

        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(last == nums.size())last--;
        if(nums[last]==target)last = last;
        else if(last-1>=0 && nums[last-1]==target)last--;


        cout<<first<<" "<<last<<endl;


        if(nums[first]==target && nums[last]==target)return {first, last};
        else if(nums[first]==target) return {first, first};
        else if(nums[last]==target) return {last, last};
        else return {-1, -1};
    }
};
