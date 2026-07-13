class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<int> prev(n+1,0), curr(n+1,0);

        for(int i = 1; i<=n;i++){
            for(int j = 1; j<=n;j++){
                if(rev[i-1] == s[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return n - prev[n];
    }
};