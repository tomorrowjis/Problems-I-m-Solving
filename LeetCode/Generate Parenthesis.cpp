
// Author : S M Nasimul Hasan
// Date : 05 Nov, 2025
// topic : Stack, Bit Masking
// Medium

class Solution {
public:

    int bitCounter(int num){
        int cnt = 0;
        while(num){
            if(num%2){
                cnt++;
                num/=2;
            }
            else{
                num = num / 2;
            }
        }
        return cnt;
    }

    string generateParentheses(int num, int N){
        char fil = ')';
        string str(N, fil);
        int idx = 0;
        while(num){
            if(num%2)str[idx] = '(';
            else str[idx] = ')';

            num = num / 2;
            idx++;
        }

        return str;

    }

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
    vector<string> generateParenthesis(int n) {
        int N = 2 * n;

        int limitSum = 0;
        int startSum = 0;
        for(int i=n; i<N; i++){
            limitSum+= pow(2, i);
        }
        for(int i=0; i<n; i++){
            startSum+= pow(2, i);
        }

        vector<string>valids;

        for(int i=startSum; i<=limitSum; i++){
            int bits = bitCounter(i);

            if(bits == n){
                string parentheses = generateParentheses(i, N);
                if(isValid(parentheses))valids.push_back(parentheses);
            }
        }

        return valids;
    }
};
