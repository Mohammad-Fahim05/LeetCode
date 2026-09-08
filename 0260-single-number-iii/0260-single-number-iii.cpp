class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto x : nums) xr ^= x;

     long long  mask = (long long)xr & - (long long)xr;

        int   a = 0;
        int  b = 0;
        for (auto x : nums){
            if( x & mask) a ^= x;
            else b ^= x;
        }
        // a = int(a);
        // b = int(b);
        return {a,b};
    }
};