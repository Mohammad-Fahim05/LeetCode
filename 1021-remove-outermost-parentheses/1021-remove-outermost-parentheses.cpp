class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string temp;

        for (auto ch : s) {
            if (ch == '(') {
                if (!stk.empty())
                    temp.push_back(ch);
                stk.push(ch);
            }else{
                stk.pop();
                if(!stk.empty()) temp.push_back(ch); 
            }
        }
        return temp;
    }
};