class Solution {
public:
    bool solve(vector<int>& piles, int h, int mid) {

        long long  total_hour = 0;
        for(auto pile : piles){
            if(pile>= mid){
                total_hour += pile / mid;
                if(pile % mid != 0) total_hour++;
            }
            else total_hour++;
        }
        return total_hour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // int ans =
            if (solve(piles, h, mid)) {
                ans = mid;
                 high = mid - 1;
            } else 
                low = mid + 1;
        }
        return ans;
    }
};