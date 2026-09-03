class Solution {
public:
    set<vector<int>> ans;
    vector<int> temp;

    void solve(int i, vector<int> &nums, vector<int> &arr){
        if( i == nums.size()){
            temp = arr;
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            temp.clear();
            return;
        }
        arr.push_back(nums[i]);
        solve(i+1, nums, arr);

        arr.pop_back();

        solve(i+1, nums, arr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> arr;
        solve (0, nums, arr);
        vector<vector<int>> p;
        for(auto i : ans) p.push_back(i);
        return p;
    }
};