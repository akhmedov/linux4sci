#include <string> // begin end
#include <vector> // begin end
#include <iostream> // cout endl
#include <algorithm> // reverse sort
#include <cstdlib> // atoi

void std_reverse (std::string& text)
{
	std::cout << "Custom std::reverse() is called!" << std::endl;
	int start = 0;
	int end = text.length() - 1;
	while (start < end) {
		char tmp = text[start];
		text[start] = text[end];
		text[end] = tmp;
		start++;
		end--; 
	}
}

void std_reverse (const std::string::iterator& a, const std::string::iterator& b)
{
	std::cout << "Custom std::reverse() is called!" << std::endl;
	std::string::iterator start = a;
	std::string::iterator end = b - 1;
	while (start < end) {
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

int std_atoi (const char* cstring)
{
	std::cout << "Custom std::atoi() is called!" << std::endl;
	int integer = 0;
	int str_length = strlen(cstring);
	int exponent = 1;
	for (int i = str_length; i > 0; i--) {
		int number = cstring[i-1] - '0';
		integer += number * exponent;
		exponent *= 10;
	}
	return integer;
}

int main (int argc, char* argv[]) {
	std::string text = argv[1];
	std_reverse(text.begin(), text.end());
	int sum = std_atoi(text.c_str()) + std_atoi(argv[1]);
	std::cout << sum << std::endl;
	return 0;
}
