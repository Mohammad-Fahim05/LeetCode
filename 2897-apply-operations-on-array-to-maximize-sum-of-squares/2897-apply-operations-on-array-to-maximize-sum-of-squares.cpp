
class Solution {
public:
    int mod = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        vector<int> bit(32, 0);
        for (int ele : nums) {
            for (int i = 0; i < 32; i++) {
                if ((ele >> i) & 1) {
                    bit[i]++;
                }
            }
        }

        long long ans = 0;
        while (k--) {
            long long num = 0;

            for (int i = 0; i < 32; i++) {
                if (bit[i] > 0) {
                    num |= (1LL << i);
                    bit[i]--;
                }
            }

            ans = (ans + num * num) % mod;
        }

        return ans;
    }
};
