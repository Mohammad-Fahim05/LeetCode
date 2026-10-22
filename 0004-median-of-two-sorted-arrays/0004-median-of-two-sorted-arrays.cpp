class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i = 0;
        int j = 0;
        int m = nums1.size();
        int n = nums2.size();

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                merge.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j] ){
                merge.push_back(nums2[j]);
                j++;
            }
            else {
                merge.push_back(nums1[i]);
                merge.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        while(i < m){
            merge.push_back(nums1[i]);
                i++;
        }
        while(j < n){
             merge.push_back(nums2[j]);
                j++;
        }
        int x = merge.size();

        if(x %2 == 1) return double(merge[x/2]);
        else {
            double sum = merge[x/2] + merge[(x -1) /2];
            return sum / 2;
        }
    }
};