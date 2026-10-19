class Solution {
public:

    int lower(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() -1;
           int ans = -1;
        while(low <= high){
            int mid = low + (high - low) /2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

        int upper(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() -1;
           int ans = -1;
        while(low <= high){
            int mid = low + (high - low) /2;
            if(nums[mid] <= target){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        int x = lower(nums, target);
        int y = upper(nums, target);

        if(x == -1  || nums[x] != target ) return ans;
        for(int i = x ; i <= y; i++) ans.push_back(i);
        return ans;
    }
};