class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x : t) mp[x]++;
        for(auto x : s) mp[x] --;
        for(auto x : mp){
            if(x.second >= 1){
                return x.first;
                break;
            }
        }
        return '0';
    }
};