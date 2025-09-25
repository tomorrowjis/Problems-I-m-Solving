class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int cnt = 1;
        int tracker = 1;
        int maj_val = nums[0];


        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1])cnt++;
            else{
                cnt = 1;
            }

            if(cnt>tracker){
                tracker = cnt;
                maj_val = nums[i];
            }
        }

        return maj_val;
    }
};
