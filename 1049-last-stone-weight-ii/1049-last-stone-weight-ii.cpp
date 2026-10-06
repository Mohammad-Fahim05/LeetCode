class Solution {
public:

    int solve(int i, int n, int target, vector<int> &arr, vector<vector<int>> &dp){
            
            if(target == 0) return 0;
            
            if(i == n) return 0;
            
            if(dp[i][target] != -1)
                return dp[i][target];
                
            int not_take = solve(i+1, n, target, arr, dp);
            int take = 0;
            if(arr[i] <= target){
                take  = arr[i] + solve(i+1, n, target - arr[i], arr, dp);
            }
            return dp[i][target] = max (take, not_take);
        }
    int lastStoneWeightII(vector<int>& arr) {
         int n = arr.size();
        int sum = 0;
        for(int i = 0; i< n;i++){
            sum += arr[i];
        }
        int target = sum /2;
        
        vector<vector<int>> dp(n , vector<int> (target+1, -1));
        int subest_one_Ans = solve(0, n, target, arr, dp);
        
        return sum - 2 * subest_one_Ans;
    }
};