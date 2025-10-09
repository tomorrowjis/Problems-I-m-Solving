class Solution {
public:
    int maxArea(vector<int>& height) {

        int first = 0;
        int last = height.size() - 1;

        int ans = INT_MIN;
        int base;
        int high;

        while(first<last){
            base = last - first ;

            if(height[first]<=height[last])high = height[first];
            else high = height[last];

            if(high * base > ans) ans = high * base ;

            if(height[first]<=height[last]){
                first++;
            }
            else last--;
        }
        return ans; 
    }
};
