class Solution {
public:
    int N;
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> anti;

    void solve(vector<string>& board, int row) {
         if(row >= N){
        result.push_back(board);
        return;
    }
    for(int col = 0; col <N; col++){
        int dc = row+col;
        int adc = row - col;

        if(cols.find(col) != cols.end() || diag.find(dc) != diag.end() || anti.find(adc) != anti.end()) continue;

        cols.insert(col);
        diag.insert(dc);
        anti.insert(adc);

        board[row][col] ='Q';
        solve(board, row+1);

        cols.erase(col);
        diag.erase(dc);
        anti.erase(adc);

        board[row][col] = '.';
    }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        N = n;
        solve(board, 0);
        return result;
    }
};