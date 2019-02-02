// https://leetcode.com/problems/valid-parentheses/

#define MAX(a,b) (((a)>(b))?(a):(b))
#include <iostream>
using namespace std;

// operator precedence
//	7	2		6	4		1	 5	  3	    8
// if (!items  || stack[--items] !=  *s) return false;

// stack memorizaation tecnique
// footprint O(n) memory O(n)
bool isValid (char* s)
{
	int items = 0;
	char stack[1000000]; // first in last out
	
	while (*s) {
		
		switch (*s) {
			case '(': stack[items++] = ')'; break;
			case '[': stack[items++] = ']'; break;
			case '{': stack[items++] = '}'; break;
			default: if (!items || stack[--items] != *s) return false;
		}
		
		s++;
	}
	
	return (items) ? false : true;
}

int main ()
{
	// char text[] = "{[()(){}}]()"; // false
	char text[] = "{[()(){}]}()"; // true
	cout << boolalpha << isValid(text) << endl;
    return 0;
}
