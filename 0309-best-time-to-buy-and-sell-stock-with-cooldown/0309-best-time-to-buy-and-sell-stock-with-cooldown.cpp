class Solution {
public:
        int solve(int i ,int canBuy, vector<vector<int>> &dp, vector<int> &prices){
            if(i >= prices.size()) return 0;
            if(dp[i][canBuy] != -1) return dp[i][canBuy];
            
            if(canBuy){
                int buy = -prices[i] + solve(i+1, 0, dp,prices);
                int skip = solve(i+1,1,dp,prices);
                return dp[i][canBuy] = max(buy, skip);
            }
            else {
                 int sell = prices[i] + solve(i+2, 1, dp,prices);
                int skip = solve(i+1,0,dp,prices);
                return dp[i][canBuy] = max(sell, skip);
            }
        }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,-1));
        return solve(0,1, dp, prices);
    }
};