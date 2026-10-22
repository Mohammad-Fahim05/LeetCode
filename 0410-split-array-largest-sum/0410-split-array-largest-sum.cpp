class Solution {
public:

    bool solve(vector<int> & nums, int k, int mid){
        int student = 1;
        long long sum = 0;
        for(auto x : nums){
            if(sum + x <= mid){
                sum += x;
            }
            else {
                student++;
                sum = x ;
            }
        }
        return student <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0LL);

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) /2;
            if(solve(nums, k, mid)){
                ans = mid;
                high = mid -1 ;
            }
            else low = mid + 1;
        }
        return ans;
    }
};