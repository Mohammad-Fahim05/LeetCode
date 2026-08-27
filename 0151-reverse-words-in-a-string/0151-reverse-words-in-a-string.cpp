class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin() , s.end());

        stringstream ss(s);
        string temp;

        string ans;
        // reverse(s.begin() , s.end());
        while(ss >> temp){
            reverse(temp.begin() , temp.end());
            if(!ans.empty()){
                ans += " ";
            }
            ans += temp;
        }

        return ans;
    }
};