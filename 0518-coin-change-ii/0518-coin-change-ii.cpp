class Solution {
public:
        const int INF = 1e9;
        int solve(int i , int amount ,  vector<vector<int>> &dp, vector<int> &coins){
            if(i == 0){
                if(amount % coins[i] == 0) {
                   return 1;
                }
                return 0;
            }
            if(dp[i][amount] != -1) return dp[i][amount];
           int not_take = solve(i-1 , amount , dp , coins);
           int take = 0;
           if(coins[i] <= amount) take = solve(i, amount-coins[i],dp,coins);
           return dp[i][amount] = take + not_take; 
        }
    int change(int amount, vector<int>& coins) {
   int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = solve(n-1, amount, dp, coins);
        return ans;
    }
};