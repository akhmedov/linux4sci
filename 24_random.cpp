#include <iostream>
using namespace std;

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

#define STEPS 40
#define RANDOM_MAX 32767

static unsigned long rand_next = 1;

int rand_int () // linear congruential generator
{
    rand_next = rand_next * 1103515245 + 12345;
    return(static_cast<unsigned>(rand_next/65536) % 32768);
}

double rand_float (int from, int to)
{
    double rnd = static_cast<double>(rand_int()) / RANDOM_MAX;
    return (to - from) * rnd + from;
}

int stat[STEPS] = {0};

int main ()
{
    int from = -1, to = 1;
    float step = static_cast<float>(to-from) / STEPS;

    for (int i = 0; i < 10000; i++) {

        double rnd = rand_float(from,to);
        double tmp = from;
        int idx = 0;

        while (tmp < rnd) {
            tmp += step;
            idx += 1;
        }

        stat[idx] += 1;
    }

    int sum = 0, min = stat[0], max = stat[0];
    
    for (int i = 0; i < STEPS; i++) {
        max = MAX(max, stat[i]);
        min = MIN(min, stat[i]);
        sum += stat[i];
        cout << stat[i] << ' ';
    }
    cout << endl;

    cout << "SUM: " << sum << endl;
    cout << "MIN: " << min << endl;
    cout << "MAX: " << max << endl;

    return 0;
}
