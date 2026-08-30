class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int  ans = 0;
        int count = 0;
        for (auto ch : s){
            if(ch == '(') count++;
            else if(ch == ')') count--;
            ans = max(ans, count);
        }
        return ans;
    }
};