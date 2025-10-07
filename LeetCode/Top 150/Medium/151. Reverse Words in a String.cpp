string reverseWords(string s) {
        vector<string>rev;
        string rin="";
        int st=-1 , ls=-1;

        for(int i=0; i<s.size(); i++){
            if(st==-1&&s[i]!=' '){
                st = i;
            }
            if(s[i]!=' '){
                ls = i;
            }
        }
        int checker = 0;

        for(int i=st; i<=ls; i++){
            if(s[i]==' '&&checker==0){
                rev.push_back(rin);
                rin="";
                checker = 1;
            }
            else if(s[i]!=' '){
                rin+=s[i];
                checker = 0;
            }
        }
        rev.push_back(rin);
        int n = rev.size();

        s="";

        for(int i=n-1; i>=1; i--){
            s+=rev[i];
            s+=" ";
        }
        s+=rev[0];

        return s;
    }
