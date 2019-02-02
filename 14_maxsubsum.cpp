// https://leetcode.com/problems/maximum-subarray/

#define MAX(a,b) (((a)>(b))?(a):(b))
#include <iostream>
using namespace std;

// Kadane's algorithm
// footprint - O(n), memory - O(1)
int maxSubArray (int* nums, int numsSize)
{
	int absolut = nums[0], current = nums[0];

	for (int i = 1; i < numsSize; i++) {
		current = MAX(nums[i], current+nums[i]);
		absolut = MAX(absolut, current);
	}

	return absolut;
}

int main ()
{
	int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // ans 6
	int size = sizeof(array) / sizeof(int);
	int ans = maxSubArray(array, size);
	cout << ans << endl;
    return 0;
}
