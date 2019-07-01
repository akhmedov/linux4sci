// https://leetcode.com/problems/top-k-frequent-elements/

#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    vector<int> res;
    unordered_map<int,int> m;
    map<int,vector<int>, greater<int>> om;
    for (auto& num : nums) ++m[num];
    for (auto& it : m) om[it.second].push_back(it.first); 
    for (auto& it : om) {
        for (auto& it :it.second)
            if (k--) res.push_back(it);
            else goto End;
    }
    End:
    return res;
}

int main ()
{
    int k = 2;
    vector<int> in {1,1,1,2,2,3};
    vector<int> out = topKFrequent(in, k);
    
    for (int i : out) cout << i << ' ';
    cout << endl;

    return 0;
}
