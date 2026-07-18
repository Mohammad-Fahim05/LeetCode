class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int small = nums[0];
        int large = nums[nums.size()-1];
        return __gcd(small,large);
    }
};