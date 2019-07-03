// https://github.com/algosolver01/algorithms/tree/master/Отрезки

#include <iostream>
using namespace std;

#define MAXN 50
#define MAXSUM 1000

int K[MAXN], RUNS, N;
bool DP[MAXSUM+1][MAXN+1];

int subset_sum (int* K, int N)
{
    for (int j = 0; j <= N; j++) DP[0][j] = true;
    for (int i = 1; i <= MAXSUM; i++) DP[i][0] = false;

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= MAXSUM; i++) {
            if (DP[i][j-1]) DP[i][j] = true;
            else if (K[j-1] > i) DP[i][j] = false;
            else DP[i][j] = DP[i-K[j-1]][j-1];
        }
    }

    for (int i = MAXSUM; i > 0; i--) if (DP[i][N] && DP[i/2][N]) return i/2;
    return 0;
}

int main ()
{
    freopen("22_input.txt", "r", stdin);
    cin >> RUNS;

    for (int i = 0; i < RUNS; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) cin >> K[j];
        cout << subset_sum(K, N) << endl;
    }

    return 0;
}
