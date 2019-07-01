// https://leetcode.com/problems/permutations/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void print_array (const vector<int>& array)
{
    for (auto i : array) cout << i << ' ';
    cout << endl;
}

int permut_number (int n)
{
    int res = 1;
    while (n > 0) res *= n--;
    return res;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    sort(nums.begin(), nums.end());

    do {
        vector<int> temp;
        temp = nums;
        permutations.push_back(temp);
    } while(next_permutation(nums.begin(), nums.end()));

    return permutations;
}

int main ()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> perms = permute(nums);

    cout << "Permutations expected: " << permut_number(nums.size()) << endl;
    cout << "Permutations returned: " << perms.size() << endl;
    return 0;
}
