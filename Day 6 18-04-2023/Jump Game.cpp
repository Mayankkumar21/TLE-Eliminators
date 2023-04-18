//https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
       int max_jump=nums[0];
        for(int i=1;i<n;i++){
            if(max_jump<i)return false;
            if(i+nums[i]>max_jump){
                max_jump=i+nums[i];
            }
        }
        if(max_jump>=n-1)return true;
        return false;
    }
};
