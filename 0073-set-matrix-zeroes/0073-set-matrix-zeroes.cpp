class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<pair<int, int >> idx;
        vector<int> row;
        vector<int> col;
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < matrix[0].size() ;j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                    // idx.push_back({i,j});
                }
            }
        }
        for(auto rows  : row){
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[rows][i] = 0;
            }
        }
            for(auto cols  : col){
            for(int j = 0; j < n; j++) matrix[j][cols] = 0;
        }
    }
};