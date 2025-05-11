class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A, B;
        int l = 0, r, i, j, median = nums1.size() + nums2.size();
        int A_LEFT, A_RIGHT, B_LEFT, B_RIGHT;

        if(nums1.size() < nums2.size()) {
            A = nums1;
            B = nums2;
        } else {
            A = nums2;
            B = nums1;
        }

        r = A.size(), i = (l + r) / 2;

        while(l <= r) {
            i = (l + r) / 2;
            j = ((A.size() + B.size() + 1) / 2) - i;
            A_LEFT = (i > 0) ? A[i - 1] : INT_MIN;
            A_RIGHT = (i < A.size()) ? A[i] : INT_MAX;
            B_LEFT = (j > 0) ? B[j - 1] : INT_MIN;
            B_RIGHT = (j < B.size()) ? B[j] : INT_MAX;

            if(A_LEFT <= B_RIGHT && A_RIGHT >= B_LEFT)
                if((A.size() + B.size()) % 2 == 1)
                    return max(A_LEFT, B_LEFT);
                else
                    return (max(A_LEFT, B_LEFT) + min(A_RIGHT, B_RIGHT)) / 2.0;
            else if(A_LEFT  > B_RIGHT)
                r = i - 1;
            else
                l = i + 1;
        }
        return 1;
    }
};
