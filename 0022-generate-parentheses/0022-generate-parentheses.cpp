class Solution {
public:
    vector<string> result;
    void solve(int i, int n, string& s) {
        if (i >= 2 * n) {
            if (isvalid(s)) {
                result.push_back(s);
            }
                return;
        }
        s.push_back('(');
        solve(i + 1, n, s);
        s.pop_back();

        s.push_back(')');
        solve(i + 1, n, s);
        s.pop_back();
    }

    bool isvalid(string& s) {
        int count = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(') count ++;
            else count --;

            if(count <0) return false ;
        }
        return count == 0;
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        solve(0,  n, str);
        return result;
    }
};