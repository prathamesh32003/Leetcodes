// Always know that if you sorted the given array, it will start from 0 and end it arr.size() - 1.
// So, it an array was already sorted, then we can make n chunks for each element? Thus a sorted array will have n chunks.
// We also know that 4th element or 3 in a sorted array will be at 4th position or 3rd index.
// If it wasn't at 3rd index and instead at 0th then we would need to sort the subarray from 0th to 3rd position
// This is the logic it is using. 

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxElement = 0, chunks = 0;

        for(int i = 0; i < arr.size(); i += 1) {
            maxElement = max(arr[i], maxElement);
            if(maxElement == i) 
                chunks += 1;
        }
        return chunks;
    }
};
