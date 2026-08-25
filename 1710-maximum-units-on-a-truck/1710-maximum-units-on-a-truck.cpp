class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin() ,boxTypes.end(), [](auto &a, auto &b){
            return a[1] > b[1];
        });
        int ans = 0;
        int remaining = truckSize;
        for(auto box : boxTypes){
            int x = box[0];
            int y = box[1];

            int take = min(x, remaining);
            ans += take * y;
            remaining -= take;

            if(remaining == 0) break;
        }
        return ans;
    }
};