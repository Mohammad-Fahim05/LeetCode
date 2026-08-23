class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxjump = 0;
        int end = 0;
        for(int i = 0; i< n -1 ;i++){
            if(i > maxjump ) return 0;
            maxjump = max(maxjump , i + nums[i]);
            if( i == end){
                count ++;
                end = maxjump;
            }
        }
        return count;
    }
};