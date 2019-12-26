#include <iostream>

#include <vector>

#include <algorithm>

#include <iomanip>

using namespace std;

struct GA

{

	double x;

	double y;

	double foo;

};

double Rand(double Min, double Max);

int crossover(const double& p1, const double& p2, const double& p3, const double& p4)

{

	double value = Rand(0, (p1 + p2 + p3 + p4));

	if (value < p1) return 0;

	if (value > p1&& value < (p1 + p2)) return 1;

	if (value > (p1 + p2) && value < (p1 + p2 + p3)) return 2;

	if (value > (p1 + p2 + p3) && value < (p1 + p2 + p3 + p4)) return 3;

}

double function(const double& x, const double& y)

{

	return exp(-(x * x) - (y * y));

}

double Rand(double Min, double Max)

{

	double f = (double)rand() / RAND_MAX;

	return Min + f * (Max - Min);

}

double probability(const double& f1, const double& f2, const double& f3, const double& f4)

{

	return 1 - f1 / (f1 + f2 + f3 + f4);

}

bool mutation_prob()

{

	double value = Rand(0, 1);

	if (value <= 0.25) return true;

	else return false;

}

double mutation(const double& gen)

{

	if (gen >= 0) return gen - 0.05;

	else return gen + 0.05;

}

int main()

{

	double ax = -2, bx = 2, ay = -2, by = 2;

	int n = 1;

	vector <GA> ga(4);

	for (auto i = 0; i < 4; i++)

	{

		ga[i].x = Rand(ax, bx);

		ga[i].y = Rand(ay, by);

		ga[i].foo = function(ga[i].x, ga[i].y);

	}

	// вывод 0 популяции

	double avg = 0;

	cout << "0" << endl;

	cout << " x y f(x,y)" << endl;

	sort(ga.begin(), ga.end(), [](auto a, auto b) { return a.foo < b.foo; });

	for (auto i : ga)

	{

		cout << fixed << setprecision(4) << setw(7) << i.x << " " << setw(7) << i.y << " " << setw(7) << i.foo << " " << endl;

		avg += i.foo;

	}

	avg /= 4;

	cout << endl << "max: " << ga[3].foo << " average: " << avg << endl << endl;

	
	for (int j = 1; j <= 50; j++)
	{

		vector <double> prob(4);

		prob[0] = probability(ga[0].foo, ga[1].foo, ga[2].foo, ga[3].foo);

		prob[1] = probability(ga[1].foo, ga[0].foo, ga[2].foo, ga[3].foo);

		prob[2] = probability(ga[2].foo, ga[1].foo, ga[0].foo, ga[3].foo);

		prob[3] = probability(ga[3].foo, ga[1].foo, ga[2].foo, ga[0].foo);

		int i = crossover(prob[0], prob[1], prob[2], prob[3]);

		ga.erase(ga.begin() + i);

		ga.push_back({});

		vector <GA> ga_copy = ga;

		ga[0].x = ga_copy[2].x;

		ga[1].x = ga_copy[2].x;

		ga[2].x = ga_copy[0].x;

		ga[3].x = ga_copy[1].x;

		ga[0].y = ga_copy[1].y;

		ga[1].y = ga_copy[0].y;

		ga[2].y = ga_copy[2].y;

		ga[3].y = ga_copy[2].y;

		for (auto i = 0; i < 4; i++)

		{

			if (mutation_prob) ga[i].x = mutation(ga[i].x);

			if (mutation_prob) ga[i].y = mutation(ga[i].y);

		}

		for (auto i = 0; i < 4; i++) ga[i].foo = function(ga[i].x, ga[i].y);

		double avg = 0;

		cout << j << " " << endl;

		cout << " x y f(x,y)" << endl;

		sort(ga.begin(), ga.end(), [](auto a, auto b) { return a.foo < b.foo; });

		for (auto i : ga)

		{

			cout << fixed << setprecision(4) << setw(7) << i.x << " " << setw(7) << i.y << " " << setw(7) << i.foo << " " << endl;

			avg += i.foo;

		}

		avg /= 4;

		cout << endl << "max: " << ga[3].foo << " average: " << avg << endl << endl;

	}

	return 0;

}
