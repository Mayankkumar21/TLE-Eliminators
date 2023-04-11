// https://cses.fi/problemset/task/1755/
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
 
void solve(){
string s;
cin>>s;
map<char,int>mp;
for(auto i:s)mp[i]++;
 
int cnt=0;
string res="";
for(auto it:mp)if(it.second%2!=0)cnt++;
if(cnt>1)cout<<"NO SOLUTION"<<endl;
else{
    for(auto it:mp){
        int size=it.second;
        if(size%2==0)
        for(int i=0;i<size/2;i++){
            res+=it.first;
        }
    }
    string t=res;
 
    for(auto it:mp)if(it.second%2!=0){
        while(it.second>0){
            res+=it.first;
            it.second--;
        }
    }
    reverse(t.begin(),t.end());
    res+=t;
 
    cout<<res<<endl;
  }
}
 
 
 
int main() {
 
#ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
#endif
    auto start1=chrono::high_resolution_clock::now();
    int t=1;
//    cin>>t;
    while(t--) {
       solve();
    }
    auto stop1=chrono::high_resolution_clock::now();
    auto duration= chrono::duration_cast<chrono::microseconds>(stop1-start1);
#ifndef ONLINE_JUDGE
    cerr<<"Time: "<<duration.count()/1000<<endl;
#endif
    return 0;
}
