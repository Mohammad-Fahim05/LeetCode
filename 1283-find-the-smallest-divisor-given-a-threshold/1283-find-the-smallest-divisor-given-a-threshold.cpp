class Solution {
public:

        int solve(vector<int>& nums, int mid){
           int sum = 0;
            for(auto x : nums){
                sum += ceil(double(x) / mid);
            }
            return sum;
        }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(nums,mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            }else low = mid +1;
        }
        return ans;
    }
};