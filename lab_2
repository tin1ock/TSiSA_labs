#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Func
{
	double x;
	double y;
};

double function1(const double& x)
{
	double y;
	y = -(pow(x, 0.5)) * sin(x) * x;
	return y;
}
double function2(const double& x)
{
	double y;
	y = -(pow(x, 0.5)) * sin(x) * x * sin(5 * x);
	return y;
}
int Round(const double& N)
{
	int n;
	if ((int)N < N) n = N + 1;
	else n = (int)N;
	return n;
}
double Rand(double Min, double Max)
{
	double f = (double)rand() / RAND_MAX;
	return Min + f * (Max - Min);
}


int main()
{
	double a = 1, b = 4;
	double N;
	vector <Func> functions;
	cout << "  q/P      0.9   0.91   0.92   0.93   0.94   0.95   0.96   0.97   0.98   0.99" << endl << endl;
	for (double q = 0.005; q < 0.105; q = q + 0.005)
	{
		cout << right << setw(6) << q << "  ";
		for (double P = 0.9; P < 1; P = P + 0.01)
		{
			N = (log(1 - P)) / (log(1 - q));
			cout << right << setw(6) << Round(N) << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "  q/P       0.9     0.91     0.92     0.93     0.94     0.95     0.96     0.97     0.98     0.99" << endl << endl;

	for (double q = 0.005; q < 0.105; q = q + 0.005)
	{
		cout << right << setw(6) << q << "  ";
		for (double P = 0.9; P < 1; P = P + 0.01)
		{
			N = (log(1 - P)) / (log(1 - q));
			functions.resize(Round(N));
			for (auto i = 0; i < Round(N); i++)
			{
				functions[i].x = Rand(a, b);
				functions[i].y = function1(functions[i].x);
			}
			sort(begin(functions), end(functions), [](auto a, auto b) { return a.y < b.y; });
			cout << right << setw(8) << functions[0].y << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "  q/P       0.9       0.91      0.92      0.93      0.94      0.95      0.96      0.97      0.98      0.99" << endl << endl;

	for (double q = 0.005; q < 0.105; q = q + 0.005)
	{
		cout << right << setw(6) << q << "  ";
		for (double P = 0.9; P < 1; P = P + 0.01)
		{
			N = (log(1 - P)) / (log(1 - q));
			functions.resize(Round(N));
			for (auto i = 0; i < Round(N); i++)
			{
				functions[i].x = Rand(a, b);
				functions[i].y = function2(functions[i].x);
			}
			sort(begin(functions), end(functions), [](auto a, auto b) { return a.y < b.y; });
			cout << right << setw(9) << functions[0].y << " ";
		}
		cout << endl;
	}
}
