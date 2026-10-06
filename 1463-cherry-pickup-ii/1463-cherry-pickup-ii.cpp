class Solution {
public:
    int M;
    int solve(int i, int j1,int j2,  vector<vector<vector<int>>> &dp,vector<vector<int>>& grid ){
        int m = grid.size();
        int n = grid[0].size();

        if(j1<0 || j1 >= n || j2 < 0 || j2 >=n) return -1e9;

        if(i == m- 1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int cherries;
        if(j1 == j2)
            cherries = grid[i][j1];
        else
            cherries = grid[i][j1] + grid[i][j2];
        int maxi = -1e9;
        for(int move1 = -1; move1 <= 1; move1++){
            for(int move2 = -1; move2 <= 1; move2++){
                int next = solve(i+1, j1+move1, j2+move2, dp, grid);
                maxi = max(maxi, next);
            }
        }
        return dp[i][j1][j2] = cherries + maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(n , -1)));
        M = m;
        return solve(0,0,n -1 , dp, grid);

    }
};