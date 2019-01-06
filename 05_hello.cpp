#include <iostream>
using namespace std;



int main (int argc, char* argv[])
{
	int atemps, res;
	int helo[4];
	char line[1000];

	// freopen("hello_input.txt", "r", stdin);
	cin >> atemps;

	for (int i = 0; i < atemps; i++) {

		res = 0;
		helo[0] = 0; helo[1] = 0; helo[2] = 0; helo[3] = 0;
		cin >> line;

		for (char* c = line; *c; c++)
			switch (*c) {
				case 'h': helo[0]++; break;
				case 'e': helo[1]++; break;
				case 'l': helo[2]++; break;
				case 'o': helo[3]++; break;
			}

		while (helo[0] > 0 && helo[1] > 0 && helo[2] > 1 && helo[3] > 0) {
			helo[0]--; helo[1]--; helo[2] -= 2; helo[3]--;
			res++;
		}

		cout << "Case #" << i+1 << ": " << res << endl;
	}

	return 0;
}
