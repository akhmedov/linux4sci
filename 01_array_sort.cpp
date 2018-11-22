// list of used headers from STL
#include <iostream> // std::cout, std::boolalpha, std::endl
#include <stdlib.h> // rand(), srand()

// global values
const int SEED = 42; // seed for random number generator
const int LENGTH = 10; // size of array
const int MIN_NUMBER = 0; // minimum value of an int in random sequence
const int MAX_NUMBER = 10; // minimum value of an int in random sequence

// declaration of functions that are used in the program
void unit_test (int* array); // prints "true" if the array is sorted and false if not
void roll_array (int* array); // fill the array by random numbers
void sort_array (int* array); // sort the array by your algorithm
void print_array (const int* array); // print the sequence

int main ()
{
	int* array = new int[LENGTH];
	print_array(array);
	roll_array(array);
	print_array(array);
	sort_array(array);
	print_array(array);
	unit_test(array);
	delete[] array;
	return 0;
}

void unit_test (int* array)
{
	bool sort_status = true;
	int iter = 0;
	while (iter < LENGTH-1) {
		int prev = *(array+iter);
		int next = *(array+1+iter);
		if (prev > next) {
			sort_status = false;
			break;
		}
		iter++;
	}
	std::cout << std::boolalpha << sort_status << std::endl;
	// std::boolalpha is used to print "true" insted of "1"
}

void roll_array (int* array)
{
	srand(SEED);
	for (int i = 0; i < LENGTH; i++) {
		int rnd = rand() % (MAX_NUMBER + 1 - MIN_NUMBER) + MIN_NUMBER;
		array[i] = rnd;
	}
	// rand() - is a function that returns a random floating number is range 0 .. 1
	// % - modulo operation (binary oparation)
	// array[i] returns a value with index i from array
}

void print_array (const int* array)
{
	int iter = 0;
	while (iter < LENGTH)
		std::cout << *(array+iter++) << ' ';
	std::cout << std::endl;
	// iter++ is an unary operation (incriment) that incris 
	// the variable iter by 1
	// The array variable is a pointer to an element with index 0
	// so you can itarate throw it by adding some integer
}

void sort_array (int* array)
{
	/* TODO: sort the "array" in incrising order
	You are allowed to use only "array" and "LENGTH" variables here
	The function must work for arbitrary SEED, LENGTH, MIN_NUMBER, MAX_NUMBER 
	You are recomened to use bubble sort algorithm */

	/* Мake sure that you are familiar with
	1. Operators: < > ++ -- + - =
	2. Key words: for if
	3. Data type: int, int*
	3. Algorithms: swap values, bubble sort
	*/

	for (int i = 0; i < LENGTH - 1; i++) {
		for (int j = 0; j < LENGTH-i-1; j++) {
			if (array[j] > array[j+1]) {
				int tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}
}
