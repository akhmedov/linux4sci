#include <iostream>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_LESSONS 510
#define MAX_SKIPS 510
using namespace std;

int DAYS, LESSONS, SKIPS;
char buffer[MAX_LESSONS]; // input text buffer
int table[MAX_LESSONS];
int old[MAX_SKIPS], optim[MAX_SKIPS]; // dynamic

int range (int* table, int* from, int* to)
{
	while (!table[*from] && *from < LESSONS) (*from)++;
	while (!table[*to] && *to > 0) (*to)--;
	return *to < *from ? 0 : *to - *from + 1;
}

int skip (int* table, int* from, int* to)
{
	if (!range(table,from,to)) return 0;

	int left = *from+1;
	int range1 = range(table, &left, to);
	int right = *to-1;
	int range2 = range(table, from, &right);

	if (range1 > range2) {
		*to = right;
		return range2;
	}
	*from = left;
	return range1;
}

int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("timetable_input.txt", "r", stdin);
	cin >> DAYS >> LESSONS >> SKIPS;

	int week = 0;

	while (DAYS--) {

		for (int k = 0; k <= SKIPS; k++) {
			old[k] = optim[k];
			optim[k] = 0;
		}

		cin >> buffer;
		for (int l = 0; l < LESSONS; l++) {
			switch (buffer[l]) {
				case '1': table[l] = 1; break;
				case '0': table[l] = 0; break;
			}
		}

		int from = 0, to = LESSONS-1;
		int must = range(table, &from, &to);
		week += must;

		int hist[SKIPS+1]; hist[0] = 0;
		for (int k = 1; k <= SKIPS; k++) {
			hist[k] = must - skip(table, &from, &to);
			for (int i = 0; i <= k; i++) {
				int cand = old[k-i] + hist[i];
				optim[k] = MAX(optim[k],cand);
			}
		}
	}

	cout << week-optim[SKIPS] << endl;
	return 0;
}
