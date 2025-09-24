void moveZeroes(int* nums, int numsSize) {
    int cnt = 0;
    for (int i =0; i<numsSize; i++) {
        if (nums[i] != 0) {
            nums[cnt++] = nums[i];
        }
    }
    while (cnt < numsSize) {
        nums[cnt++] = 0;
    }
}