#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Data
{
	double h;
	double dist;
	vector<double> alpha;
	double w;
	double d;
};


double function(const double& x)
{
	return sin(x) + 0.5;
}

double random(double Min, double Max)
{
	double f = (double)rand() / RAND_MAX;
	return Min + f * (Max - Min);
}

double noise(const double& f, const double& a1, const double& a2)
{
	return f + random(a1, a2);
}

double xk(const int& k, const double& xmax, const double& xmin, const int& K)
{
	return xmin + k * (xmax - xmin) / K;
}

vector <double> function_noise(const vector<double>& x, const double& a1, const double& a2)
{
	vector <double> func(101);
	for (auto i = 0; i <= 100; i++)
	{
		func[i] = noise(function(x[i]), a1, a2);
	}
	return func;
}

vector <double> geometric_mean(const vector<double>& foo, vector<double>& alpha, const int& r)
{
	vector<double> gm(101);
	int M = (r - 1) / 2;
	for (auto i = 0; i <= 100; i++)
	{
		double mul = 1;
		for (auto j = i - M; j <= i + M; j++)
		{
			try
			{//пояснение для этого говна
				foo.at(j); //это хуйня выбрасывает исключение если мы используем значение вне вектора
				mul *= pow(foo[j], alpha[j + M - i]);//это прочто функция но она иногда может использовать значения вне своего вектора
			}
			catch (const out_of_range & s)//эта хуйня ловит исключение и обрабатывает его
			{
				mul *= 1;// это обработка исключения
			}
		}
		gm[i] = mul;
	}

	return gm;
}

void set_alpha(vector<double>& alpha, const int& r)
{
	alpha.clear();
	alpha.resize(r);
	alpha[(r - 1) / 2] = random(0, 1);
	for (auto i = (r - 1) / 2 - 1; i > 0; i--)
	{
		double sum1 = 0;
		for (auto i1 = i; i1 < r - i - 1; i1++)
		{
			sum1 += alpha[i1];
		}
		alpha[i] = 0.5 * random(0, 1 - sum1);
		sum1 = 0;
	}
	for (auto i = (r - 1) / 2 + 1; i < r - 1; i++)
	{
		alpha[i] = alpha[r - i - 1];
	}
	double sum2 = 0;
	for (auto i = 1; i < r - 1; i++)
	{
		sum2 += alpha[i];
	}
	alpha[0] = 0.5 * (1 - sum2);
	alpha[r - 1] = 0.5 * (1 - sum2);
}

double prob(const double& P, const double& ep, const double& xmax, const double& xmin)
{
	return (log(1 - P)) / (log(1 - (ep) / (xmax - xmin)));
}

double dist(const double& w, const double& d)
{
	return abs(w) + abs(d);
}

double w(const vector<double>& f_filtred)
{
	double w = 0;
	for (auto i = 1; i <= 100; i++)
	{
		w += abs(f_filtred[i] - f_filtred[i - 1]);
	}
	return w;
}

double d(const vector<double>& f_filtred, const vector<double>& f_noise)
{
	double d = 0;
	for (auto i = 0; i <= 100; i++)
	{
		d += abs(f_filtred[i] - f_noise[i]);
	}
	d /= 100;
	return d;
}

double J(double h, double w, double d)
{
	return h * w + (1 - h) * d;
}

int main()
{
	setlocale(LC_ALL, "ru");
	vector<Data> data;
	int r1 = 3, r2 = 5;
	vector <double> alpha, alphamin;
	double xmin = 0, xmax = M_PI;
	double a1 = -0.25, a2 = 0.25;
	int K = 100;
	int L = 10;
	double h = 0;
	double P = 0.95;
	double ep = 0.01;
	double W, Wmin;
	double D, Dmin;
	double Dist, Distmin = 99999;
	double N = prob(P, ep, xmax, xmin);
	vector<double>Xk(101);
	for (int i = 0; i <= K; i++)
	{
		Xk[i] = xk(i, xmax, xmin, K);
	}
	vector<double> Fk(101);
	for (auto i = 0; i <= K; i++)
	{
		Fk[i] = function(Xk[i]);
	}
	//вывод функции
	cout << "функция" << endl;
	for (auto i : Fk) cout << i << endl;
	cout << endl << endl;
	vector<double> f_noise = function_noise(Fk, a1, a2);
	//вывод зашумленного графика
	cout << "отфильтрованная функция" << endl;
	for (auto i : f_noise) cout << i << endl;
	cout << endl << endl;

	// r=3

	vector<double> f_filtred;
	cout << " h    dist             alpha              w        d" << endl;
	for (auto l = 0; l <= 10; l++)
	{
		for (auto i = 0; i < N; i++)
		{
			set_alpha(alpha, r1);
			f_filtred = geometric_mean(f_noise, alpha, r1);
			W = w(f_filtred);
			D = d(f_filtred, f_noise);
			Dist = dist(W, D);

			if (Dist < Distmin)
			{
				Distmin = Dist;
				Wmin = W;
				Dmin = D;
				alphamin = alpha;
			}
		}
		h = (double)l / L;
		data.push_back({ h, Distmin, alphamin, Wmin, Dmin });
		cout << fixed << setprecision(1) << h << "  " << setprecision(4) << Distmin << "   [ ";
		for (auto i : alphamin) cout << i << " ";
		cout << "]  " << Wmin << "   " << Dmin << endl;
	}

	//вывод для первого отфильтрованного графика(потом удалить 4 строчки)
	cout << "отфильтрованная функция 1" << endl;
	f_filtred = geometric_mean(f_noise, alphamin, r1);
	for (auto i : f_filtred) cout << i << endl;
	cout << endl;

	sort(data.begin(), data.end(), [](auto a, auto b) {return a.dist < b.dist; });
	cout << endl << " h*     J        w        d" << endl;
	cout << setprecision(1) << data[0].h << "   " << setprecision(4) << J(data[0].h, data[0].w, data[0].d) << "   " << data[0].w << "   " << data[0].d << endl;


	// r = 5
	Distmin = 999999;
	data.clear();
	f_filtred.clear();
	alphamin.clear();
	Dmin = 0;
	Wmin = 0;

	cout << endl << endl;
	cout << " h    dist                   alpha                      w        d" << endl;
	for (auto l = 0; l <= 10; l++)
	{
		for (auto i = 0; i < N; i++)
		{
			set_alpha(alpha, r2);
			f_filtred = geometric_mean(f_noise, alpha, r2);
			W = w(f_filtred);
			D = d(f_filtred, f_noise);
			Dist = dist(W, D);

			if (Dist < Distmin)
			{
				Distmin = Dist;
				Wmin = W;
				Dmin = D;
				alphamin = alpha;
			}
		}
		h = (double)l / L;
		data.push_back({ h, Distmin, alphamin, Wmin, Dmin });
		cout << fixed << setprecision(1) << h << "  " << setprecision(4) << Distmin << "   [ ";
		for (auto i : alphamin) cout << i << " ";
		cout << "]  " << Wmin << "   " << Dmin << endl;
	}

	//вывод для второго отфильтрованного графика
	cout << "отфильтрованная функция  2" << endl;
	f_filtred = geometric_mean(f_noise, alphamin, r2);
	for (auto i : f_filtred) cout << i << endl;
	cout << endl;

	sort(data.begin(), data.end(), [](auto a, auto b) {return a.dist < b.dist; });
	cout << endl << " h*     J        w        d" << endl;
	cout << setprecision(1) << data[0].h << "   " << setprecision(4) << J(data[0].h, data[0].w, data[0].d) << "   " << data[0].w << "   " << data[0].d << endl;

	system("pause");

	return 0;
}
