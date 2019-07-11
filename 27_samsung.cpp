// https://www.codechef.com/AUG14/problems/CRAWA#

#include <iostream>
using namespace std;

#define ABS(x) ((x>0)?(x):(-x))
#define SIGN(x) ((x>0)?(1):(-1)) // SIGN(0) = -1

int main ()
{
    freopen("27_input.txt","r",stdin);

    int requests;
    cin >> requests;

    while (requests-->0) {
        int x, y;
        cin >> x >> y;
        bool vertical = ((x>0 && x%2!=0) || (x<0 && x%2==0)) && (y >= -(x-1)) && (y <= x+1);
        bool horizont = (y%2==0) && (x >= -ABS(y)) && (x <= SIGN(y)*(y-1));
        cout << flush << (vertical || horizont ? "YES" : "NO") << endl;
    }

    return 0;
}
