class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for (int currentElement : nums) {
            if (currentElement != val) {
                nums[idx] = currentElement;
                idx++;
            }
        }
        return idx;
    }
};