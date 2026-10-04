class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];

        for(int i = 2; i<= n;i++){
            int take = nums[i-1] + prev2;
            int n_take = prev;

            int curr = max(take, n_take);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};