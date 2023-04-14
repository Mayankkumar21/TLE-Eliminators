//  https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
    private:
    long long compute_hash(string const& s,long long p,long long m) {
    // p-> base m->modulo val
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // if(s.size()<10)return {};
        map<pair<long long,long long>,long long> hash_occurances;
        map<pair<long long,long long>,string>hash_to_string;
        long long p=31,m=1e9+9;
        long long p1=37,m1=1e9+7;
        
        int i=0,j=9;
        vector<string>res;
        int len=10;
        while(i+len-1<s.size()){
            // cout<<s.substr(i,j)<<endl;
            long long hash1=compute_hash(s.substr(i,len),p,m);
            long long hash2=compute_hash(s.substr(i,len),p1,m1);
            hash_occurances[{hash1,hash2}]++;
            hash_to_string[{hash1,hash2}]=s.substr(i,len);
            i++;
        }
        
        // for(auto i:hash_to_string)cout<<i.first<<" "<<i.second<<endl;
        
        for(auto it:hash_occurances){
            if(it.second>1){
                res.push_back(hash_to_string[it.first]);
            }
        }
        return res;
    }
};
