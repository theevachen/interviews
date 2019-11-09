//=================================================================================================
//
// 1. Two Sum
//
// Description:
// Given an array of integers, return indices of the two numbers such that they add up
// to a specific target. You may assume that each input would have exactly one solution, and you
// may not use the same element twice.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
// Thoughts:
// - Is the given list of numbers sorted?
// - Negative numbers are valid.
// - Can have duplicate numbers. Just can't reuse same number.
//
//=================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//
// Note: The returned array must be malloced, assume caller calls free().
//
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    if ((nums == NULL) || (returnSize == NULL)) {
        return NULL;
    }

    //
    // Potentially not needed since it says that we can assume that each input wiil have exactly
    // one solution.
    //
    if ((numsSize == 0) || (numsSize == 1)) {
        return NULL;
    }

    int *result = malloc(sizeof(int) * 2);
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j =  i + 1; j < numsSize; j++) {
            if ((nums[i] + nums[j]) == target) {
                *returnSize = 2;
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return NULL;
}

int main(void) {
    //
    // Test given example.
    //
    int nums[4] = { 2, 7, 11, 15 };
    int target = 9;
    int return_size = 0;
    int *result = twoSum(nums, 4, target, &return_size);
    
    assert(return_size == 2);
    assert(result[0] == 0);
    assert(result[1] == 1);

    free(result);

    return 0;
}