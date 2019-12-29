#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double function1(const double& x)
{
	double y = -(pow(x, 0.5)) * sin(x) * x;
	return y;
}
double function2(const double& x)
{
	double y = -(pow(x, 0.5)) * sin(x) * x * sin(5 * x);
	return y;
}

bool probability(const double& P)
{
	double value = ((double)(rand() % 1000)) / 1000.0;
	if (value <= P) return true;
	else return false;
}
double Rand(double Min, double Max)
{
	double f = (double)rand() / RAND_MAX;
	return Min + f * (Max - Min);
}

int main()
{
	double a = 1, b = 4;
	double Tmax = 10000, Tmin = 0.01, Ti = Tmax;
	double x2, x1 = Rand(a, b);
	double y2, y1 = function1(x1);
	double f_delta;
	double P;
	int n = 0;
	cout << "f(x) = -(pow(x, 0.5)) * sin(x) * x" << endl << endl;
	cout << " N        x          f(x)          Ti" << endl << endl;
	while (Ti > Tmin)
	{
		x2 = Rand(a, b);
		y2 = function1(x2);
		f_delta = y2 - y1;
		if (f_delta <= 0)
		{
			x1 = x2;
			y1 = y2;
		}
		else
		{
			P = exp(-(f_delta / Ti));
			if (probability(P))
			{
				x1 = x2;
				y1 = y2;
			}
		}
		cout << setw(3) << ++n << fixed << "   " << x1 << "   " << y1 << "   " << Ti << endl;
		Ti = Ti * 0.95;
	}

	x1 = Rand(a, b);
	y1 = function2(x1);
	Ti = Tmax;
	n = 0;
	cout << endl << endl << "f(x) = -(pow(x, 0.5)) * sin(x) * x * sin(5x)" << endl << endl;
	cout << " N           x            f(x)           Ti" << endl << endl;
	while (Ti > Tmin)
	{
		x2 = Rand(a, b);
		y2 = function2(x2);
		f_delta = y2 - y1;
		if (f_delta <= 0)
		{
			x1 = x2;
			y1 = y2;
		}
		else
		{
			P = exp(-(f_delta / Ti));
			if (probability(P))
			{
				x1 = x2;
				y1 = y2;
			}
		}
		cout << setw(3) << ++n << fixed << right << setw(6) << "   " << x1 << "   " << setw(12) << y1 << "   " << setw(6) << Ti << endl;
		Ti = Ti * 0.95;
	}


	return 0;

}
