class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0; // position to place the next non-zero

        // Move all non-zero numbers to the front
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left] = nums[right];
                if (left != right) nums[right] = 0; // set the old position to 0
                left++;
            }
        }
    }
};
