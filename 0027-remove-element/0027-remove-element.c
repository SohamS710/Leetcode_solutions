int removeElement(int* nums, int numsSize, int val) {
    int i, s=0;
    int n = numsSize;
    
    for (i=0;i<n;i++) {
        if (nums[i] != val) {
            nums[s++] = nums[i];
        }
    }
    return s;
}