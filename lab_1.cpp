#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<iomanip>

using namespace std;

double function(const double& x) 
{
	double y;
	y = sqrt(x) * sin(x) + 2;
	return y;
}

struct Function 
{
	double x;
	double y;
};

void Print(const vector<Function>& v1, const double& size)
{
	cout << left << setw(10) << "N" << setw(10) << "x" << setw(10) << "f(x)" << '\n';
	for (int i = 0; i <= size; i++)
	{
		cout << fixed << left << setw(10) << i << setw(10) << v1[i].x << setw(10) << v1[i].y << '\n';
	}
}

void Min(const double& sigma, const int& k, double& a, double& b)
{
	double x1, x2;
	x1 = ((a + b) / 2) + sigma;
	x2 = ((a + b) / 2) - sigma;
	if (function(x2) < function(x1)) { b = a + (b - a) / 2; }
	else { a += (b - a) / 2; };
	cout << fixed << setprecision(5) << left << setw(10) << k << setw(10) << a << setw(10) << b << setw(10) << x1 << setw(10) << x2 << setw(10) << function(x1) << setw(10) << function(x2) << setw(10) << (b-a) << '\n';
}

void main()
{
	double a = 1.0, b = 4.0, E = 0.1;
	double N;
N  = 2 * (b - a) / E + 1;
vector<Function> v(N + 1);
for (int i = 0; i <= N; i++)
{
	v[i].x = (b - a) / (N + 1) * i + a;
	v[i].y = function(v[i].x);
}
Print(v, N);
double sigma;
cout << "enter sigma: ";
cin >> sigma;
cout << '\n';
N = 1;
int k = 1;
cout << left << setw(10) << "N" << setw(10) << "a" << setw(10) << "b" << setw(10) << "x1" << setw(10) << "x2" << setw(10) << "f(x1)" << setw(10) << "f(x2)" << setw(10) << "l" << '\n';
do {
	Min(sigma, k, a, b);
	k++;

} while ((b - a) >= sigma);
	double x = (a + b) / 2;
	cout << "minimal x = " << x << '\n' << "minimal f(x) = " << function(x) << '\n';

}
