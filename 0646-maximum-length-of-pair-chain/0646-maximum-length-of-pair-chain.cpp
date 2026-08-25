class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin() , pairs.end() , [](auto &a , auto &b){
            return a[1]  < b[1];
        });
        int count = 1;
        int end = pairs[0][1];
        for(int i = 1; i < n; i++){
            int start = pairs[i][0];
            if(start > end){
                count++;
                end = pairs[i][1];
            }
        }
        return count;
    }
};