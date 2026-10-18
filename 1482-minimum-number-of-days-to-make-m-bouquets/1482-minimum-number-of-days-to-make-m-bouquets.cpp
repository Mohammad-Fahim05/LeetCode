class Solution {
public:
    bool bloom(vector<int>& arr, int mid, int m, int k) {
        int boque_count = 0;
        int consecutive_count = 0;
        for (auto x : arr) {
            if (x <= mid)
                consecutive_count++;
            else
                consecutive_count = 0;

            if (consecutive_count == k) {
                boque_count++;
                consecutive_count = 0;
            }
        }
        return boque_count >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (bloom(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};