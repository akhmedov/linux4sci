// http://codeforces.com/problemset/problem/366/C

#include <iostream>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define BUFFER_SIZE 12
#define MAX_FRUIT_NUMBER 100
using namespace std;

int from, to, mid = BUFFER_SIZE/2, conf[BUFFER_SIZE];

int sweet[MAX_FRUIT_NUMBER], calorie[MAX_FRUIT_NUMBER];
int FRUITS, BALANCE;

int main () 
{
	// freopen("salad_input.txt", "r", stdin);
	cin >> FRUITS >> BALANCE;
	conf[from=to=mid] = 1;

	for (int i = 0; i < FRUITS; i++)
		cin >> sweet[i];
		
	for (int i = 0; i < FRUITS; i++) {

		cin >> calorie[i];
		int bias = sweet[i] - BALANCE * calorie[i];

		if (bias < 0) {

			for (int j = from; j <= to; j++) {
				if (conf[j]) {
					int update = conf[j] + sweet[i];
					conf[j+bias] = MAX(update, conf[j+bias]);
				}
			}

			from += bias;

		} else {

			for (int j = to; j >= from; j--) {
				if (conf[j]) {
					int update = conf[j] + sweet[i];
					conf[j+bias] = MAX(update, conf[j+bias]);
				}
			}

			to += bias;
		}

	}

	int res = conf[mid] > 1 ? conf[mid] - 1 : -1;
	cout << res << endl;
}
