class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if(s.size() != t.size()) return false;
        for(auto ch : s){
            mp[ch]++;
        }
        for(auto ch : t) mp[ch]--;
        for(auto x : mp){
            if(x.second >= 1) return false;
        }
        return true;
    }
};