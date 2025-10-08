class Solution {
public:
   
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        map<int, int>cnt;
        for(int i=0; i<numbers.size(); i++){
            cnt[numbers[i]]=0;
        }
        for(int i=0; i<numbers.size(); i++){
            cnt[numbers[i]]++;
        }
        int first ;
        int second;
        for(int i=0; i<numbers.size(); i++){
            first = numbers[i];
            second = target - first;

            if(first==second && cnt[first] > 1)break;
            else if(first != second && cnt[second]>0)break;
        }

        vector<int>ans;
        for(int i=0; i<numbers.size(); i++){
            if(numbers[i] == first){
                ans.push_back(i+1);
                numbers[i] = INT_MAX;
                first = INT_MIN;
            }
            if(numbers[i] == second){
                ans.push_back(i+1);
                numbers[i] = INT_MAX;
                second = INT_MIN;
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
