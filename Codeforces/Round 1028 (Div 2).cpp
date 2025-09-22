#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mapin map<ll, ll>
#define mapchar map<char, ll>
#define forloop(l, n) for (ll i = l; i < n; i++)
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define take(n);  ll n; cin >> n;
#define all(x) x.begin(), x.end()

using namespace std;

ll bins[32];

vector<char> to_binary(ll n)
{
    vector<char> bin;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            bin.pb('0');
        }
        else
        {
            bin.pb('1');
        }
        n = n / 2;
    }
    reverse(bin.begin(), bin.end());

    return bin;
}

vector<ll> prime_nums(ll n)
{
    vector<bool> vis;
    vector<ll> nums;

    for (ll i = 0; i <= n; i++)
    {
        vis.pb(false);
    }

    for (ll i = 2; i <= n; i++)
    {
        if (vis[i] == false)
        {
            nums.pb(i);
            for (ll j = i * i; j <= n; j += i)
                vis[j] = true;
        }
    }

    return nums;
}

ll sqrrt(ll n)
{
    for (ll i = 1;; i++)
    {
        if (i * i > n)
        {
            return i - 1;
        }
    }
}

vector<ll> divisors(ll n)
{
    ll s = sqrrt(n);
    vector<ll> divs;

    for (ll i = 1; i <= s; i++)
    {
        if (n % i == 0)
            divs.pb(i);
    }
    ll ss = divs.size();

    for (ll i = 0; i < ss; i++)
    {
        divs.pb(n / divs[i]);
    }
    sort(divs.begin(), divs.end());

    return divs;
}

void solveA()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a >= d && c >= d)
    {
        cout << "Gellyfish" << endl;
    }
    else if (b <= a && b <= c)
        cout << "Gellyfish" << endl;
    else
        cout << "Flower" << endl;
}

const int mod = 998244353;
const int maxn = 100001;

vector<ll> pow2(maxn + 1);

void precompute() {
    pow2[0] = 1;
    for (ll k = 1; k <= maxn; k++) {
        pow2[k] = (pow2[k - 1] * 2) % mod;
    }
}

void solveB()
{
    ll n;
    cin >> n;
    ll a[n], b[n];

    vector<ll> r;

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll max_a = INT_MIN;
    ll max_b = INT_MIN;

    ll idx_max_a = 0;
    ll idx_max_b = 0;
    for (ll i = 0; i < n; i++)
    {
        if (max_a < a[i])
        {
            max_a = a[i];
            idx_max_a = i;
        }
        else if(max_a == a[i]){
            if(b[0]>b[i - idx_max_a])
            {
                idx_max_a = i;
            }

        }
        if (max_b < b[i])
        {
            max_b = b[i];
            idx_max_b = i;
        }
        else if(max_b == b[i]){
            if(a[0]>a[i - idx_max_b]){
                idx_max_b = i;
            }

        }

        if (max_a > max_b)
        {
            ll val_a = max_a;
            ll val_b = b[i - idx_max_a];

            val_a = pow2[val_a];
            val_b = pow2[val_b];

            ll val = (val_a + val_b) % mod;

            r.pb(val);
        }
        else if (max_b > max_a)
        {
            ll val_b = max_b;
            ll val_a = a[i - idx_max_b];

            val_b = pow2[val_b];
            val_a = pow2[val_a];

            ll val = (val_a + val_b) % mod;

            r.pb(val);
        }
        else if (max_a == max_b)
        {
            ll sec_a = b[i - idx_max_a];
            ll sec_b = a[i - idx_max_b];

            if (sec_a >= sec_b)
            {
                ll val_a = max_a;
                ll val_b = b[i - idx_max_a];

                val_a = pow2[val_a];
                val_b = pow2[val_b];

                ll val = (val_a + val_b) % mod;

                r.pb(val);
            }
            else
            {
                ll val_b = max_b;
                ll val_a = a[i - idx_max_b];

                val_b = pow2[val_b];
                val_a = pow2[val_a];

                ll val = (val_a + val_b) % mod;

                r.pb(val);
            }
        }
    }

    for(auto x: r){
        cout<<x<<" ";
    }
    cout<<endl;
}

vector<ll>primes;
map<ll,ll>prime_marker;

void solveC(){//unnecessary bigger solution, fucked, why did I think it in this complex way. fuckkk!
    ll n;
    cin>>n;
    ll a[n];
    ll check_prime = 0;

    for(ll i=0; i<n; i++){
        cin>>a[i];
        if(prime_marker[a[i]]==1)check_prime=1;
    }
    sort(a, a+n);

    if(a[0]==1){
        ll cnt = 0;
        for(ll i=0; i<n; i++)if(a[i]==1)cnt++;

        cout<<n-cnt<<endl;
        return;
    }

    if(check_prime==1){
        ll count = 0;

        if(prime_marker[a[0]]!=1)cout<<n<<endl;
        else if(prime_marker[a[0]]){
            for(ll i=0; i<n; i++){
                if(a[i]%a[0]!=0){
                    cout<<n<<endl;
                    return;
                }
                if(a[i]==a[0])count++;
            }
            cout<<n-count<<endl;
        }

    }
    else{
        ll checker = 0;
        ll count = 0;

        for(ll i=1; i<n; i++){
            if(a[i]%a[0]!=0){
                checker = 1;
            }
            if(a[i]==a[0])count++;
        }

        if(checker==0){
            cout<<n-count-1<<endl;
            return;
        }

        ll ans = 2;

        count = 0;
        ll val = a[0];
        ll gc = val;
        

        for(ll i=1; i<n; i++){
            val = gc;
            gc = __gcd(val, a[i]);
        }
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(i!=j){
                    ll gc_again = __gcd(a[i], a[j]);

                    if(gc_again==gc){
                        ans = 1;
                        cout<<n<<endl;
                        return;
                    }
                }
            }
        }

        checker = 0;

        for(ll i=0; i<n-1; i++){
            if(a[i]+1==a[i+1]){
                checker = 1;
                break;
            }
        }
        if(checker){
            cout<<min(n, ans+(n-1))<<endl;
            return;
        }
        cout<<ans+ (n-1)<<endl;

    }
}

int main()
{
    for (ll i = 0; i < 32; i++)
    {
        bins[i] = pow(2, i);
    }

    primes = prime_nums(5000);

    for(ll i=0; i<primes.size(); i++){
        prime_marker[primes[i]]=1;
    }

    ll t;
    cin >> t;
    while (t--)
    {
        solveC();
    }
}
