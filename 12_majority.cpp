// https://leetcode.com/problems/majority-element/submissions/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// quick sort + linear counter
// footprint O(n), memory O(n*log(n))
int majorityElement_sort (vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	return nums[nums.size()/2];
}

// memorization of numbers
// footprint O(n), memory O(n)
int majorityElement_dict (vector<int>& nums)
{
	map<int,int> freqency;
	for (auto value : nums) freqency[value]++;

	pair<int,int> majority;
	for (auto it = freqency.begin(); it != freqency.end(); it++)
		if (majority.second < it->second) majority = *it;

	return majority.first;
}

// Boyer–Moore majority vote algorithm
// footprint O(n), memory O(1), NO STL
int majorityElement (int* nums, int numsSize)
{
	int majority = nums[0], counter = 0;

	for (int i = 0; i < numsSize; i++) {

		if (majority == nums[i]) counter++;
		else counter--;

		if (counter == 0) {
			majority = nums[i];
			counter = 1;
		}
	}

	return majority;
}

int main ()
{
	int array[] = {3, 2, 3};
	int res = majorityElement(array,3);
	cout << res << endl;
	return 0;
}
