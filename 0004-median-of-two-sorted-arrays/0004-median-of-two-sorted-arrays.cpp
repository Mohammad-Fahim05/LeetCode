class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        for(int i  = 0; i<nums1.size();i++) merge.push_back(nums1[i]);
        for(int i  = 0; i<nums2.size();i++) merge.push_back(nums2[i]);

        sort(merge.begin(), merge.end());

        int x = merge.size();

        if(x %2 == 1) return double(merge[x/2]);
        else {
            double sum = merge[x/2] + merge[(x -1) /2];
            return sum / 2;
        }
    }
};