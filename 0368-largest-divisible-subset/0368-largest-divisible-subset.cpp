class Solution {
public:
    int solve(int i, int prev, vector<vector<int>>& dp, vector<int>& nums) {
        if (i >= nums.size())
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int take = 0;
        if (prev == -1 || (nums[i] % nums[prev]) == 0) {
            take = 1 + solve(i + 1, i, dp, nums);
        }
        int not_take = solve(i + 1, prev, dp, nums);

        return dp[i][prev + 1] = max(take, not_take);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        cout << solve(0, -1, dp, nums);

        vector<int> ans;

        int i = 0;
        int prev = -1;
        while (i < n) {
            int not_take = solve(i + 1, prev, dp, nums);

            int take = -1;
            if (prev == -1 || nums[i] % nums[prev] == 0) {
                take = 1 + solve(i + 1, i, dp, nums);
            }
            if (take >= not_take) {
                ans.push_back(nums[i]);
                prev = i;
            }
            i++;
        }
        return ans;
    }
};