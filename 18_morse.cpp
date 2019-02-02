#define DOT   "."
#define DASH  "-"
#define SPACE "|"

#include <iostream>
using namespace std;

int chars = 0;
const char *latin = "**ETIANMSURWDKGOHVF*L*PJBXCYZQ**"; // 32

void conv (int decimal)
{
	if (decimal) {
		conv(decimal/2);
		if (decimal != 1) {
			decimal%2 ? printf(DASH) : printf(DOT);
			chars++;
		}
	}
}

void morse (char c)
{
	if (c >= 'a' && c <= 'z') c -= 32; // convert to uppercase
	if (c < 'A' || c > 'Z') return;
	int i = 0;
	while (latin[++i] != c);
	conv(i);
}

int main (int argc, char* argv[])
{
	if (argc == 1) return 0;

	for (int i = 1; i < argc; i++) {
		
		char* c = argv[i];
		
		while (*c) {
			morse(*c);
			printf(SPACE);
			chars++;
			c++;
		}

		printf(SPACE);
		chars++;
	}

	printf("\nLength: %i \n",chars);
	
	return 0;
}

/* 
for my rouse 		42		..-.|---|.-.||--|-.--||.-.|---|..-|...|.||
i love you 			35		..||.-..|---|...-|.||-.--|---|..-||
for my darling ann	60		..-.|---|.-.||--|-.--||-..|.-|.-.|.-..|..|-.|--.||.-|-.|-.||
from rolan to ann	54		..-.|.-.|---|--||.-.|---|.-..|.-|-.||-|---||.-|-.|-.||
you are in my hart	55 		-.--|---|..-||.-|.-.|.||..|-.||--|-.--||....|.-|.-.|-||
*/
