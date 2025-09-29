class Solution {
public:
    int hIndex(vector<int>& citations) {

        int st = 1;
        int en = citations.size();

        while(st<=en){
            int mid = (st + en) / 2;
            int cnt = 0;
            for(int i = 0; i<citations.size(); i++){
                if(citations[i]>=mid)cnt++;
            }

            if(cnt >= mid){
                st = mid + 1;
            }
            else en = mid - 1;

        }

        return st-1;
        
    }
};
