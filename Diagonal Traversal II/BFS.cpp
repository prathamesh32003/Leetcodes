// I was never able to come up with this but after reading it, I understand how wonderful this solution is.
// We're using BFS and considering (0, 0) as source and using adding rows first then columns
// the col == 0 is necessary because we don't want to go down a row when our current column is say, 10 because the element below that also has 10th element in row migh not exist

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> q;
        vector<int> ans;

        q.push({0, 0});

        while(!q.empty()) {
            auto [row, col] = q.front();
            ans.push_back(nums[row][col]);
            q.pop();

            if(col == 0 && row + 1 < nums.size()) {
                q.push({row + 1, col});
            }
            
            if(col + 1 < nums[row].size()) {
                q.push({row, col + 1});
            }
        }

        return ans;
    }
};
