class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string > result(m, string(n,'#'));
        int row = 0;
        int col = 0;

        result[0][0] = '.';
        while(col+1 < n){
            col++;
            result[row][col] = '.';
        }
        while(row+1<m){
            row++;
            result[row][col] = '.';
        }
        return result;
    }
};