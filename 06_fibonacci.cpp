#include <iostream>
using namespace std;

// -O1 -O2 -O3 optimizations incrises runtime

size_t recurs (size_t arg)
{
	if (arg < 2) return arg;
	return recurs(arg-1) + recurs(arg-2);
}

size_t dynamic (size_t arg)
{
	size_t grand = 0, parent = 1, child = 0;
	for (size_t n = 0; n < arg; n++) {
		grand = parent;
		parent = child;
		child = parent + grand;
	}
	return child;
}

int main (int argc, char* argv[]) 
{
	for (size_t n = 0; n < 51; n++)
		cout << n << ' ' << recurs(n) << endl;
}
