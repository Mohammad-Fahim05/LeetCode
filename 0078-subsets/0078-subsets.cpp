class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &nums, vector<int> &arr){
        if(i >= nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        solve(i + 1, nums, arr);

        arr.pop_back();
        solve(i+1, nums, arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        solve(0 , nums, arr);
        return ans;
    }
};