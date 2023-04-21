//https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long int pro=1;
        long long int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            pro*=nums[i];
            maxi=max(maxi,pro);
            if(pro==0){
                pro=1;
            }
        }
        pro=1;
        for(int i=n-1;i>=0;i--){
            pro*=nums[i];
            maxi=max(maxi,pro);
            if(pro==0){
                pro=1;
            }
            
    }
        return maxi;
    }
};
