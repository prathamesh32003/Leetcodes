// Took me a while to understand but I finally did understand it. I usually struggled with understand when to update left and right so here's my understanding:
// You always want to have smallest number in your custom pointers so if right of bigger array is smaller than left of smaller then decrease smaller array because we want the smaller element
// Similarly if right of smaller array is smaller than left of bigger array then we want it in our custom array so increase the smaller array by increment left
// Basically if you increment left you increase the length of smaller array and decrease that of bigger arrat and if you decrement right, you decrease the size of smaller array and increase that of bigger array
// Depending on where the smaller element exists you either increase smaller array of bigger array by decreasing the other

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
