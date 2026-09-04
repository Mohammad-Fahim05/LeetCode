class Solution {
public:
    vector<vector<int>> ans;
    set<int> st;
    void solve(vector<int> &nums, vector<int> &temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int j = 0; j < nums.size();j++){
            if(st.find(nums[j]) ==    st.end()){

            temp.push_back(nums[j]);
            st.insert(nums[j]);
            solve(nums,temp);
            temp.pop_back();
            st.erase(nums[j]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums, temp);
        return ans;
    }
};