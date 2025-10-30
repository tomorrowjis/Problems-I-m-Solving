//Codeforces Round 1056 Div 2 
//Nasimul Hasan
//Currently have solutions to A and B

#include<bits/stdc++.h>
#define ll          long long int
#define pb          push_back
#define mapin       map<ll, ll>
#define mapchar     map<char, ll>
#define forloop(l, n)    for(ll i=l; i<n; i++)
#define faster()    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define take(n);    ll n; cin>>n;
#define all(x)      x.begin(), x.end()

using namespace std;

ll bins[32];

vector<char> to_binary(ll n){
    vector<char>bin;
    while(n>0){
        if(n%2==0){
            bin.pb('0');
        }else{
            bin.pb('1');
        }
        n=n/2;
    }
    reverse(bin.begin(), bin.end());

    return bin;
}

vector<ll>prime_nums(ll n){
    vector<bool>vis;
    vector<ll>nums;

    for(ll i = 0; i<=n; i++){
        vis.pb(false);
    }

    for(ll i=2; i<=n; i++){
        if(vis[i]==false){
            nums.pb(i);
            for(ll j = i*i ; j<=n; j+=i)vis[j]=true;
        }
    }

    return nums;

}



ll sqrrt(ll n){
    for(ll i=1; ; i++){
        if(i*i>n){
            return i-1;
        }
    }
}

vector<ll>divisors(ll n)
{
    ll s = sqrrt(n);
    vector<ll>divs;

    for(ll i=1; i<=s; i++)
    {
        if(n%i==0)divs.pb(i);
    }
    ll ss = divs.size();

    for(ll i=0; i<ss; i++)
    {
        divs.pb(n/divs[i]);
    }
    sort(divs.begin(), divs.end());

    return divs;

}



void solveA()
{
    ll n;
    cin>>n;
    ll winners = n;
    ll losers = 0;

    ll totalMatches = 0;

    while(winners+losers>1){

        if(winners == 1 && losers == 1){
            totalMatches++;
            break;
        }
        ll toBeInTheLosers = 0;
        if(winners%2==0){
            toBeInTheLosers = winners / 2;
            totalMatches+= winners / 2;
            winners = winners / 2;
        }
        else{
            toBeInTheLosers = winners / 2;
            totalMatches+= winners / 2;
            winners = winners/2 + 1;
        }
        ll toBeElimin = 0;

        if(losers%2==0){
            toBeElimin = losers / 2;
            losers = losers/2 ;
            totalMatches+= toBeElimin;
        }
        else{
            toBeElimin = losers / 2;
            losers = losers / 2 + 1;
            totalMatches+= toBeElimin;
        }
        losers = losers + toBeInTheLosers;

    }

    cout<<totalMatches<<endl;
}

void solveB(){
    ll n, k;
    cin>>n>>k;
    char maze[n][n];
    char escapeChecker[n][n];

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            escapeChecker[i][j]='.';
        }
    }

    if(k>0){
        escapeChecker[0][0] = 'E';
        maze[0][0] = 'U';
        k--;
    }
    ll X[4] = {0, 0, 1, -1};
    ll Y[4] = {1, -1, 0, 0};
    char dir[4] = {'R', 'L', 'D', 'U'};
    ll ranX = 0, ranY = 0;

    ll nonEscape = n*n - k;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(escapeChecker[i][j]=='.'){
                for(ll p = 0; p<4; p++){
                   if((i+X[p]>=0 && i+X[p]<n) && (j+Y[p]>=0&&j+Y[p]<n)){
                    if(escapeChecker[i+X[p]][j+Y[p]]=='E'){
                        maze[i][j] = dir[p];
                        escapeChecker[i][j] = 'E';
                        k--;
                        if(k==0)break;
                        break;
                     }
                   }
                }
            }
            if(k==0)break;
        }
        if(k==0)break;
    }




    char direc[4] = {'R','L', 'D', 'U'};



    for(ll i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(escapeChecker[i][j]== '.'){
                //if it's a empty cell
                int flag = 0;
                for(int p = 0; p<4; p++){
                    //checking direections
                    if((i+X[p]>=0 && i+X[p]<n) && (j+Y[p]>=0&&j+Y[p]<n)){
                        //if the cell is inside
                        if(escapeChecker[i+X[p]][j+Y[p]]== 'N' || escapeChecker[i+X[p]][j+Y[p]]=='.'){
                            escapeChecker[i][j] = 'N';
                            maze[i][j] = dir[p];
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 0){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }


    cout<<"YES"<<endl;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<maze[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    for(ll i=0; i<32; i++){
        bins[i]=pow(2, i);
    }

    ll t;
    cin>>t;
    while(t--)
    {
        solveB();
    }

}
