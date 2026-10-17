class Solution {
public:
    int first(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;

        int ans = -1;
        while(low <= high ){
            int mid = low + (high - low) /2 ;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans ;
    }
    int last(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;

        int ans = -1;
        while(low <= high ){
            int mid = low + (high - low) /2;
            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int x = first(nums, target);
        int y = last(nums, target);
        if(x == -1 || nums[x] != target) return {-1, -1};
        if (y == -1)
        return {x, (int)nums.size() - 1};

        return {x , y - 1};
    }
};