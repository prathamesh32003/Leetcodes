# Had to search for this algorithm. I mean you can do it in two passes by storing the number of 0s, 1s and 2s and rewriting the array but watend to know this one.
# Logic makes sense here, low will count 0s, mid 1s and high 2s. If mid isn't 1 then just swap the number with either low of high depending on what mid is. We don't increment mid when swapped with high because swapped number might be 0 and we do increment mid when swapped with low because we know for a fact that all numbers before mid are either 0 or 1.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                int temp = nums[mid];
                nums[mid] = nums[low];
                nums[low] = temp;
                low += 1;
                mid += 1;
            } else if(nums[mid] == 2) {
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high -= 1;
            } else {
                mid += 1;
            }
        }
    }
};
