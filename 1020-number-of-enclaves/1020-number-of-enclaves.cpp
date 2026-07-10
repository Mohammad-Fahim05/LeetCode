class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>  q;

        for(int i = 0; i<n;i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                grid[i][0] = 2; // visited
            }
            if(grid[i][m-1] == 1){
                q.push({i,m-1});
                grid[i][m-1] = 2;
            }
        }
        for(int i = 0;i<m;i++){
            if(grid[0][i] == 1){
                q.push({0,i});
                grid[0][i] = 2;
            }
            if(grid[n-1][i] == 1){
                q.push({n-1,i});
                grid[n-1][i] = 2;
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            auto [row, col ] = q.front();
            q.pop();

            for(int i = 0; i< 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < n && nc >=0  && nc < m && grid[nr][nc] == 1){
                    q.push({nr,nc});
                    grid[nr][nc] = 2;
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n;i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};