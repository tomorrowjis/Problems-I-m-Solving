class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>zigzag(numRows);
        int n = numRows;

        if(n>=s.size()){
            return s;
        }
        if(n == 1) return s;
        int dir = 0;
        int idx = 0;
        zigzag[0].push_back(s[0]);

        for(int i=1; i<s.size(); i++){
            char val = s[i];
            if(dir == 0){
                idx++;
                zigzag[idx].push_back(val);
            }
            else if(dir == 1){
                idx--;
                zigzag[idx].push_back(val);
            }

            if(idx==n-1){
                dir = 1;
            }
            else if(idx==0){
                dir = 0;
            }
        }

        idx = 0;
        s ="";
        for(auto x: zigzag){
            s+=x;
        }
        return s;
    }
};
