//https://codeforces.com/problemset/problem/271/D
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


long long compute_substring_hash(int i,int j,string const& s,vector<long long>&prefix,vector<ll>&inv_power,ll p,ll m){
//    const int p = 31;
//    const int m = 1e9 + 9;
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



void solve() {
string s,t;
cin>>s>>t;
ll k;
cin>>k;
ll n=s.size();

    ll p=31,p1=37;
    ll m=1e9+9,m1=1e9+7;

    vector<ll>prefix(n),powers(n+1),prefix1(n),powers1(n+1);

    powers[0]=1;
    powers1[0]=1;
    for(int i=1;i<=n;i++)powers[i]=(powers[i-1]*31)%m;
    for(int i=1;i<=n;i++)powers1[i]=(powers1[i-1]*37)%m1;


    prefix[0]=s[0]-'a'+1;
    for(int i=1;i<n;i++){
        prefix[i]=(prefix[i-1]+((s[i]-'a'+1)*powers[i])%m)%m;
    }

    prefix1[0]=s[0]-'a'+1;
    for(int i=1;i<n;i++){
        prefix1[i]=(prefix1[i-1]+((s[i]-'a'+1)*powers1[i])%m1)%m1;
    }

    vector<ll>inv_power(n+1);
    inv_power[n]=bin_power_mod(powers[n],m-2,m);
    for(int i=n-1;i>=0;i--){
        inv_power[i]= (inv_power[i+1]*p)%m;
    }
    vector<ll>inv_power1(n+1);
    inv_power1[n]=bin_power_mod(powers1[n],m1-2,m1);
    for(int i=n-1;i>=0;i--){
        inv_power1[i]= (inv_power1[i+1]*p1)%m1;
    }

    set<pair<ll,ll>>st;
    for(int i=0;i<n;i++){
        ll bad=0;
        for(int j=i;j<n;j++){
            if(t[s[j]-'a']=='0')
                bad++;
            if(bad>k)
                break;
        ll hash= compute_substring_hash(i,j,s, prefix,inv_power,p,m);
        ll hash1= compute_substring_hash(i,j,s,prefix1,inv_power1,p1,m1);
//        cout<<s.substr(i,j)<<" ";
        st.insert({hash,hash1});

        }
    }
    cout<<st.size()<<"\n";


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
