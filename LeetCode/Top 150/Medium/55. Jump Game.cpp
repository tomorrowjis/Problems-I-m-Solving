class Solution {
public:
   bool canJump(vector<int>& nums) {
    int n = nums.size();
    int zero_passed = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(nums[i]==0)cnt++;
        if(nums[i]==0&&i<n-1){
            for(int j=i-1; j>=0; j--)
            {
                if(nums[j]+j>i){
                    zero_passed++;
                    break;
                }
            }
        }
        else if(nums[i]==0&&i==n-1)zero_passed++;
    }

    if(cnt==zero_passed)return true;
    else return false;

}
};
