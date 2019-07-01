#include <iostream>
#define CANDIDATES 1000000
#define MAX(a,b) (((a)>(b))?(a):(b))

struct Vertex { int l1{}, l2{}; };

Vertex prev[CANDIDATES], next[CANDIDATES];

int split (int* K, int N)
{
    if (N < 2) return 0;
    int max = 0, total = 2;

    prev[0].l1 = K[0]; prev[0].l2 = 0;
    prev[1].l1 = prev[1].l2 = 0;

    for (int i = 1; i < N; i++, total *= 3) {
        for (int j = 0, j3 = 0; j < total; j++, j3 = 3*j) {

            next[j3] =  prev[j];
            next[j3].l1 += K[i];
            if (next[j3].l1 == next[j3].l2) max = MAX(max,next[j3].l1);

            next[j3+1] =  prev[j];
            next[j3+1].l2 += K[i];
            if (next[j3+1].l1 == next[j3+1].l2) max = MAX(max,next[j3+1].l1);

            next[j3+2] = prev[j];
        }
        for (int j = 0; j < 3*total; j++) prev[j] = next[j];
    }

    return max;
}

int main ()
{
    freopen("22_input.txt", "r", stdin);

    int RUNS, K[50], N;
    std::cin >> RUNS;

    for (int i = 0; i < RUNS; i++) {
        std::cin >> N;
        for (int j = 0; j < N; j++) std::cin >> K[j];
        std::cout << split(K, N) << std::flush << std::endl;
    }

    return 0;
}