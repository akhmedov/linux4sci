#include <iostream>
using namespace std;

int reverse1 (int x)
{
    int rev = 0;

    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }

    return rev;
}

int reverse2 (int value)
{
    int threshold = INT_MAX/10;
    int reverse = 0;
    
    while (value) {
        if (reverse > threshold) return 0;
        if (-reverse > threshold) return 0;
        reverse *= 10;
        reverse += value % 10;
        value /= 10;
    }

    return reverse;
}

int main ()
{
    for (int i = INT_MIN; i <= INT_MAX; i++) {
        int n1 = reverse1(i);
        int n2 = reverse2(i);
        if (n1 != n2) cout << i << endl;
    }
    
    return 0;
}
