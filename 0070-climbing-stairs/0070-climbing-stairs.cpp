class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int curr = 1;
        for(int i = 2;i<=n;i++){
            int result = prev  + curr;
            prev = curr;
            curr = result;
        }
        return curr;
    }
};