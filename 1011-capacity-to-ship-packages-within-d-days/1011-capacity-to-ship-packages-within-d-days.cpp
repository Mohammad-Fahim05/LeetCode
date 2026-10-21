class Solution {
public:

    bool solve(vector<int> &weights, int days, int mid ){
        int sum = 0;
        int count_day = 0;
        for(auto weight : weights){
            sum += weight;
            if(sum > mid){
                sum = weight;
                count_day++;
            }
        }
        return count_day +1  <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0LL);

        int ans = -1; 
        while(low <= high){
            int mid = low + (high - low)/2;
            if(solve(weights, days , mid)){
                ans = mid ;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans ;
    }
};