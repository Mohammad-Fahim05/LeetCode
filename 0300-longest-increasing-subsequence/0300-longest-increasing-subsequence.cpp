class Solution {
public: 
   int  solve(int index, vector<int> &nums,int prev,vector<vector<int>> &dp){
        if(index >= nums.size()) return 0;

        if(dp[index][prev+1] != -1) return dp[index][prev+1];
        int not_take = solve(index+1, nums, prev, dp);
        int take = 0;
        if(prev == -1 || nums[index] > nums[prev]){
            take = 1 + solve(index+1, nums, index, dp);
        }
        return dp[index][prev+1] = max(take, not_take);
    } 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(0, nums, -1 , dp );
    }
};