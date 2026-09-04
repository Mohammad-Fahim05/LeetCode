class Solution {
public:
set<vector<int>> st;
void solve(int i, vector<int> &nums){
    if(i == nums.size()){
        st.insert(nums);
        return;
    }
    for(int j = i; j< nums.size();j++){
        swap(nums[i], nums[j]);
        solve(i+1, nums);
        swap(nums[i], nums[j]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0, nums);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};