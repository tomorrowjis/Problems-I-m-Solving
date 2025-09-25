class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int ans =0;
        vector<int>store;

        for(int i=0; i<nums.size(); i++){
            if(val==nums[i])ans++;
            else store.push_back(nums[i]);
        }
        for(int i=0; i<store.size(); i++){
            nums[i] = store[i];
        }
        return nums.size()-ans;
    }
};
