class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int first = 0;

        map<char, int>lastIdx;

        for(int i=0; i<s.size(); i++){
            lastIdx[s[i]] = -1;
        }

        int len = 1;
        lastIdx[s[0]] = 0;

        if(s.empty())return 0;
        for(int i=1; i<s.size(); i++){

            if(lastIdx[s[i]]==-1){
                len = max(len, i - first + 1);
                lastIdx[s[i]] = i;
            }
            else{

                if(lastIdx[s[i]]<first){
                    len = max(len, i - first + 1);
                    lastIdx[s[i]] = i;
                }
                else{
                    len = max(len, i - first);
                    first = lastIdx[s[i]] + 1;
                    lastIdx[s[i]] = i;
                }
                
            }

        }

        return len;
    }
};
