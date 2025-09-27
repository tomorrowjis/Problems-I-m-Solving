class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[0]<prices[i]){
                ans+= (prices[i] - prices[0]);
                prices[0] = prices[i];
            }
            else prices[0] = prices[i];
        }
        return ans;
    }

    
};
