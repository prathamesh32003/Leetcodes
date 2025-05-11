// I can see why this is one of the most hated problems cause usually you'd come up with this solution but the log(m + n) adds the actual "Hard" part 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                sorted.push_back(nums1[i]);
                i += 1;
            } else {
                sorted.push_back(nums2[j]);
                j += 1;
            }
        }

        while(i < nums1.size()) {
            sorted.push_back(nums1[i]);
            i += 1;
        }

        while(j < nums2.size()) {
            sorted.push_back(nums2[j]);
            j += 1;
        }

        if(sorted.size() % 2 == 0) {
            return double(sorted[(sorted.size() / 2)] + sorted[(sorted.size() / 2) - 1]) / 2;
        } else {
            return double(sorted[(sorted.size() / 2)]);
        }
    }
};
