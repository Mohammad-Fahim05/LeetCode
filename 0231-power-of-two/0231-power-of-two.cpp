class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n<1) return 0;
        // int count = 0;
        // while(n >0){
        //     count += n&1;
        //     n = n >> 1;
        // }
        // return count == 1;

        return n > 0 && (n & (n-1)) == 0;
    }
};