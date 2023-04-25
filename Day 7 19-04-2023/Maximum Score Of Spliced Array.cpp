//https://leetcode.com/problems/maximum-score-of-spliced-array/
class Solution {
public:
    
    int solve(vector<int>& nums1, vector<int>& nums2){
        int sum=0,maxi=0;
        for(int i=0;i<nums1.size();i++){
            sum = max(nums2[i] - nums1[i], sum + nums2[i] - nums1[i]);
            maxi=max(maxi,sum);
          
        }
        return maxi;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n1=solve(nums1,nums2);
        int n2=solve(nums2,nums1);
        int sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
        }
        return max(n1+sum1,n2+sum2);
    }
};
