#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

#define TERMS 10000
 
// imp:GradshtejnInt 3.716.2 p. 417
// \int_0^{\pi/2} \sin(a \cdot \tan(x)) dx = \frac{\pi}{2} e^{-a}

double simpson (double from, double to, const std::function<double(double)> &func)
{
	if (from >= to) return 0;

	double h = (to - from) / TERMS;
	double I = 0;

	double a = from;
	double b = from + h;
	double f_a = func(a);
	double f_ab = func((a + b)/2);
	double f_b = func(b);

	while (b <= to) {
		I += f_a + 4 * f_ab + f_b;
		a = b;
		b += h;
		f_a = f_b;
		f_ab = func((a + b)/2);
		f_b = func(b);
	}

	return I * (to - from) / TERMS / 6;
}

int main () 
{
	double x0 = 0;
	double x1 = M_PI_2;

	cout << left << fixed;
	cout << setw(20) << "Paramiter" << setw(20) << "Numerical" << "Analitics";
	cout << endl << string(60, '-') << endl;
	
	for (double a = 0; a < 5; a++) {
		auto f = [a] (double x) { return std::cos(a*std::tan(x)); };
		auto F = M_PI_2 * std::pow(M_E,-a);
		cout << setw(20) << a << setw(20) << simpson(x0,x1,f) << F << endl;
	}

	return 0;
}
