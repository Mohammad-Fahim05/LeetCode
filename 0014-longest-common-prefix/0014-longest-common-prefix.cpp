class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string beg = strs[0];
        string end = strs[strs.size()-1];

        string ans ="";
        if(beg[0] != end[0]) return ans;
        int i = 0;
        int j = 0;
        while(i < beg.size() && j < end.size()){
            if(beg[i] == end[j]) ans+=beg[i];
            else break;
            i++;
            j++;
        }
        return ans;
    }
};