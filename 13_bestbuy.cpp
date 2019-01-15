// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

// greedy algorithm - bruteforce
// footprint O(n^2), memory O(1)
int maxProfit_greedy (int* prices, int pricesSize)
{
	int profit = 0, candidate;
	for (int i = 0; i < pricesSize-1; i++) {
		for (int j = i; j < pricesSize; j++) {
			candidate = prices[j] - prices[i];
			profit = MAX(profit,candidate);
		}
	}
	return profit;
}

// dynamic programing - itarative
// footprint O(n), memory O(1)
int maxProfit_dynamic (int* prices, int pricesSize)
{
	int min = 0, max = 0, profit = 0, candidate;

	for (int id = 0; id < pricesSize; id++) {
		if (prices[max] < prices[id]) {
			max = id;
		} else if (prices[id] < prices[min]) {
			candidate = prices[max] - prices[min];
			profit = MAX(profit, candidate);
			min = max = id;
		}
	}

	candidate = prices[max] - prices[min];
	return MAX(profit, candidate);
}

int main ()
{
	int series[] = {7, 1, 5, 3, 6, 4}; // output 5
    // int series[] = {3, 3, 5, 0, 0, 3, 1, 4}; // output 4
	int size = sizeof(series) / sizeof(int);
    int res = maxProfit_dynamic(series,size);
    cout << res << endl;
    return 0;
}
