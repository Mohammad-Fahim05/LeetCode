class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        long long  maxi = INT_MIN;
        while(i < j){
            long long  mini = min(height[i] , height[j]);
            maxi = max(maxi , (j - i) * mini );
            if(height[i] < height[j] ) i++;
            else j--;
        }
        return maxi;
    }
};