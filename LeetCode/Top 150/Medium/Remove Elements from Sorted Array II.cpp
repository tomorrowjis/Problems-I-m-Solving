class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int>checker;

        for(int i=0; i<nums.size(); i++){
            checker[nums[i]] = 0;
        }

        int idx = 0;

        for(int i=0; i<nums.size(); i++){
            if(checker[nums[i]]<2){
                nums[idx] = nums[i];
                idx++;
                checker[nums[i]]++;
            }
        }

        return idx;
        
    }
};
