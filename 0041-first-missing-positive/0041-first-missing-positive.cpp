class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st(nums.begin() , nums.end());
        for(int i = 1; ;i++){
            if(!st.count(i)) return i;
        }
    }
};