// Usually you'd come up with this but still here's to explanation:
// Diagonals have this property where addition of row index and column index of an element is same as previous diagonal element
// We're using the same logic here, start from last row and add the (row + col) elements in their appropriate place using map
// Then add the answers in the final array. This is in hints and I kinda did come up with the solution but still had to see a youtube explanation to understand the proper approach

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> m;
        vector<int> ans;

        for(int i = nums.size() - 1; i >= 0; i -= 1) {
            for(int j = 0; j < nums[i].size(); j += 1) {
                m[i + j].push_back(nums[i][j]);
            }
        }

        int key = 0;

        while(m.contains(key)) {
            for(int k:m[key])
                ans.push_back(k);
            key += 1;
        }

        return ans;
    }
};
