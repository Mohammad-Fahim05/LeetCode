class Solution {
public:
    int solve(int i , int target , vector<int> &nums, vector<vector<int>> &dp){

        // if(target == 0) return 1;
        // if( i== nums.size()) return 0;

        if(i == nums.size()) return target == 0 ? 1 : 0;

        if(dp[i][target] != -1) return dp[i][target];
        int not_take = solve(i + 1, target, nums, dp);
        int take = 0;
        if(nums[i] <= target ){
            take = solve(i + 1, target - nums[i] , nums, dp);
        }

        return dp[i][target] = take + not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n =  nums.size();

        int sum = 0;
        for(auto x : nums) sum += x;

        if(abs(target) > sum)  return 0;

        if((sum + target ) %2 != 0) return 0;

        int t = (sum + target ) / 2;

        vector<vector<int>> dp(n + 1 , vector<int> (t+ 1, -1));
        return solve(0, t, nums, dp);
    }
};