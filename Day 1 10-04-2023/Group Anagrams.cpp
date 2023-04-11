// https://leetcode.com/problems/group-anagrams/
class Solution {
    private:
    long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<long long,int>>hashes;
        int i=0;
        string t="";
        for(auto &s:strs){
            t=s;
            sort(s.begin(),s.end());
            hashes.push_back({compute_hash(s),i});
            i++;
            s=t;
        }
        unordered_map<long long,vector<int>>mp;
        
        for(auto &p:hashes){
            mp[p.first].push_back(p.second);
        }
        
        vector<vector<string>>res;
        
        for(auto &it:mp){
            vector<string>t;
            for(int j=0;j<it.second.size();j++){
                t.push_back(strs[it.second[j]]);
            }
            res.push_back(t);
        }
        return res;

    }
};
