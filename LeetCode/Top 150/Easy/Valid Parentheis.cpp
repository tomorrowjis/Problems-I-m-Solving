// Author: S M Nasimul Hasan (tomorrow_jis)
// Date : 05 Nov, 2025
// Topic: stack


class Solution {
public:
    bool isValid(string s) {
        map<char, char>counter;
        counter[')'] = '(';
        counter['}'] = '{';
        counter[']'] = '[';

        stack<char>opens;

        for(int i=0; i<s.size(); i++){
            if(!counter[s[i]]){
                opens.push(s[i]);
            }
            else{
                if(opens.empty())return false;
                char close = opens.top();
                if(close != counter[s[i]]){
                    return false;
                }
                else{
                    opens.pop();
                }
            }
        }

        if(opens.size()>0)return false;
        else return true;
    }
};
