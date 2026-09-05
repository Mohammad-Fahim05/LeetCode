class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> map(n);
        int mini = nums[n-1];
        int maxi = nums[0];
        map[n-1] = nums[n-1];
        for(int i = n-2; i>=0;i--){
            mini = min(mini, nums[i] );
            map[i] = mini;

        }
        for(int i = 0;i<n;i++){
            maxi = max(maxi , nums[i]);
            if((maxi - map[i] <= k)) return i;
        }
        return -1;
    }
};