#include <iostream> // cout, endl
#include <stdlib.h> // rand, srand
#include <vector> // push_back

const int SEED = 42; // seed for random number generator
const int LENGTH = 10; // size of array
const int MIN_NUMBER = 0; // minimum value of an int in random sequence
const int MAX_NUMBER = 10; // minimum value of an int in random sequence

int main ()
{
	std::vector<int> array;

	srand(SEED);
	for (int i = 0; i < LENGTH; i++) {
		int rnd = rand() % (MAX_NUMBER + 1 - MIN_NUMBER) + MIN_NUMBER;
		array.push_back(rnd);
	}

	std::sort(array.begin(), array.end());

	for (auto i : array) std::cout << i << ' ';
	std::cout << std::endl;

	return 0;
}
