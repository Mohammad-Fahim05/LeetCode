class Solution {
public:

            bool check (string &a , string &b){
                 int x = a.size();
                 int y = b.size();

                 if(y - x  != 1) return false;
                 int i =0;
                 int j =0;

                 while( i< x && j < y){
                    if(a[i] == b[j]) i++;
                    j++;
                 }
                 return i == x;
            }
    int solve(int i , int prev, vector<string> &words,vector<vector<int>> &dp){
        if(i >= words.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int not_take = solve(i +1, prev , words , dp);
        
        int take = 0;
        if(prev == -1 || check(words[prev] , words[i])){
            take = 1 + solve(i + 1 , i, words , dp);
        }
        return dp[i][prev+1] = max(take, not_take);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end() , [](const string &a, const string &b){
            return a.size() < b.size();
        });
        // solve using LIS
        int n = words.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0 , -1, words, dp);
    }
};