class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    int prefix[n];
    int suffix[n+1];
    int pre = 1;
    int suf = 1;

    for(int i=1; i<n; i++){
        pre = pre * nums[i-1];
        prefix[i] = pre;
    }
    for(int i=n-2; i>=0; i--){
        suf = suf * nums[i+1];
        suffix[i] = suf;
    }

    vector<int>answer(n);

    answer[0] = suffix[0];
    answer[n-1] = prefix[n-1];

    for(int i = 1; i<n-1; i++){
        answer[i] = suffix[i] * prefix[i];
    }

    return answer;
  }
};
