class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i = 0; i< n;i++){
            arr[i] = nums[i] * nums[i];
        }
        sort(begin(arr), end(arr));
        long long sub = 0;
        long long add = 0;
        for(int i = 0; i<n/2;i++){
            sub += arr[i];
        }
        for(int i = n/2; i<n;i++){
            add += arr[i];
        }
        return add - sub;
    }
};