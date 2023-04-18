//https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int maxjump=nums[0],jumps=1,currjump=nums[0],i=0;
        
        while(i<n){
            maxjump=max(maxjump,nums[i]+i);
            
            if(currjump==i){
                jumps++;
                currjump=maxjump;
            }
            if(currjump>=n-1)return jumps;
            i++;
        }
        return jumps;
    }
};
