// How I understand this:
// GCD of two prime numbers is going to be 1. So, if we encounter a prime number the gcd at some point is going to be 1.
// And when one of the element of gcd becomes 1, the gcd for all the remaining elements becomes 1
// If there were no prime numbers, the gcd will never become 1 and thus, the array will never be good.

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];

        for(int i = 1; i < nums.size(); i += 1) {
            g = gcd(g, nums[i]);
        }

        return g == 1;
    }
};
