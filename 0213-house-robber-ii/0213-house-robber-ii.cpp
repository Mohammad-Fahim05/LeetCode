class Solution {
public:
    int solve(int start , int end , vector<int> &nums, vector<int> &dp){
        if(start == end) return nums[end];
        if(start > end) return 0;
        if(dp[start] != -1) return dp[start];
        int take = nums[start ] + solve(start + 2 , end, nums,dp);;
        int not_take = solve(start +1 , end , nums, dp);

        return dp[start] = max(take , not_take );
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <=1) return nums[0];
        vector<int> dp1(n , -1);
        vector<int> dp2(n , -1);
        int exe_last = solve(0, n -2 , nums, dp1);
        int inc_last = solve(1, n-1, nums , dp2);

        return max(exe_last,inc_last);
    }
};