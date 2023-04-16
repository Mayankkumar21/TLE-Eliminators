// https://codeforces.com/problemset/problem/126/B

    #include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MOD 1000000007


bool isPrimeNum(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}


bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}


// Generate prime number <lim
const int MAX_PR = 5'000'000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
    isprime.set(); isprime[0] = isprime[1] = 0;
    for (int i = 4; i < lim; i += 2) isprime[i] = 0;
    for (int i = 3; i*i < lim; i += 2) if (isprime[i])
            for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
    vi pr;
    rep(i,2,lim) if (isprime[i]) pr.push_back(i);
    return pr;
}
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
// binary exponentiation
long long bin_power_mod(long long a, long long b,long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%m;
        a = (a * a)%m;
        b >>= 1;
    }
    return res%m;
}
long long bin_power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
long long compute_hash(string const& s,long long p,long long m) {
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


long long compute_substring_hash(int i,int j,string const& s,vector<long long>&prefix,vector<ll>&inv_power){
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_j=prefix[j];
    long long hash_i;
    if(i>0)hash_i=prefix[i-1];
    else return hash_j;


    long long val=hash_j-hash_i+m;
//    long long invpower=bin_power_mod(power,m-2,m);   //mod inverse basically (1/x)%mod = pow(x,mod-2)%mod
    ll invpower=inv_power[i];
    val%=m;
    val*=invpower;
    return val%m;
}

bool valid(int len,vector<ll>&prefix,vector<ll>&suffix,string &s,vector<ll>&inv_power){
//    cout<<prefix[len-1]<<" "<<suffix[len-1]<<endl;

    ll required_hash=prefix[len-1];

    for(int i=1;i<s.size()-len;i++){
        ll curr_hash= compute_substring_hash(i,i+len-1,s,prefix,inv_power);
        if(curr_hash==required_hash){
            return true;
        }
    }
    return false;

}

void solve(){
    string s;
    cin>>s;
    int n=s.size();

    ll p=31;
    ll m=1e9+9;
    vector<ll>prefix(n),suffix(n),powers(n+1);

    powers[0]=1;
    for(int i=1;i<=n;i++)powers[i]=(powers[i-1]*31)%m;

    prefix[0]=s[0]-'a'+1;
    suffix[0]=s[n-1]-'a'+1;

    for(int i=1;i<n;i++){
        prefix[i]=(prefix[i-1]+((s[i]-'a'+1)*powers[i])%m)%m;
    }

    for(int i=1;i<n;i++){
        suffix[i]=(suffix[i-1]*31+(s[n-i-1]-'a'+1)%m)%m;
    }


    vector<ll>inv_power(n+1);
    inv_power[n]=bin_power_mod(powers[n],m-2,m);
    for(int i=n-1;i>=0;i--){
        inv_power[i]= (inv_power[i+1]*p)%m;
    }

    ll l=1,h=n-1;
    ll res=-1;
    while(l<=h){
        ll mid=l+(h-l)/2;
        if(valid(mid,prefix,suffix,s,inv_power)) {
            l = mid + 1;
            res = mid;
        }
        else
            h=mid-1;
    }
    int ans=-1;
    for(int i=res;i>0;i--){
        ll required_hash=prefix[i-1];
        ll curr_hash= suffix[i-1];
        if(required_hash==curr_hash){
            ans=i;
            break;
        }

    }
    if(ans==-1)cout<<"Just a legend";
    else cout<<s.substr(0,ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
#endif
//     auto start1=chrono::high_resolution_clock::now();
    int t=1;
//    cin>>t;
    while(t--) {
        solve();
    }
//     auto stop1=chrono::high_resolution_clock::now();
//     auto duration= chrono::duration_cast<chrono::microseconds>(stop1-start1);
// #ifndef ONLINE_JUDGE
//     cerr<<"Time: "<<duration.count()/1000<<endl;
// #endif
     return 0;
}
