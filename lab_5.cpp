#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<double> set_vector_criterion(const vector<double>& criterion)
{
	vector <double> criterionret(4);
	for (auto i1 = 0; i1 <= 3; i1++)
	{
		for (auto i2 = 0; i2 <= 3; i2++)
		{
			if (i1 != i2)
			{
				if (criterion[i1] > criterion[i2]) criterionret[i1]++;
				if (criterion[i1] == criterion[i2]) criterionret[i1] = criterionret[i1] + 0.5;
			}
		}
	}
	return criterionret;
}

vector<double> norm4(const vector<double>& matrix)
{
	vector <double> matrixret(4);
	double sum = 0;
	for (auto i = 0; i <= 3; i++) sum += matrix[i];
	for (auto i = 0; i <= 3; i++) matrixret[i] = matrix[i] / sum;
	return matrixret;
}
void sort_matrix(vector<vector<double>>& matrix)
{
	double temp;
	for (auto i1 = 0; i1 <= 3; i1++)
	{
		for (auto i2 = 0; i2 <= 3; i2++)
		{
			for (auto j = i2; j <= 3; j++)
			{
				if (matrix[i2][i1] > matrix[j][i1])
				{
					temp = matrix[i2][i1];
					matrix[i2][i1] = matrix[j][i1];
					matrix[j][i1] = temp;
				}
			}
		}
	}
}

vector<vector<double>> norm_matix_criterion(const vector<vector<double>>& matrix, const int& criterion)
{
	vector<vector<double>> matrix2 = matrix;
	sort_matrix(matrix2);
	vector <vector<double>> matrixret(4, vector<double>(4));

	for (auto i1 = 0; i1 <= 3; i1++)
	{

		for (auto i2 = 0; i2 <= 3; i2++)
		{
			if (i1 != criterion)
			{
				matrixret[i2][i1] = (matrix[i2][i1] - matrix2[0][i1]) / (matrix2[3][i1] - matrix2[0][i1]);
			}
			else
			{
				matrixret[i2][i1] = matrix[i2][i1];
			}
		}
	}
	return matrixret;
}

vector<vector<double>> norm4x4(const vector<vector<double>>& matrix)
{
	vector <double> sum(4);
	vector <vector<double>> matrixret(4, vector<double>(4));
	for (auto i1 = 0; i1 <= 3; i1++)
	{
		for (auto i2 = 0; i2 <= 3; i2++)
		{
			sum[i1] += matrix[i2][i1];
		}
	}
	for (auto i1 = 0; i1 <= 3; i1++)
	{
		for (auto i2 = 0; i2 <= 3; i2++)
		{
			matrixret[i2][i1] = matrix[i2][i1] / sum[i1];
		}
	}
	return matrixret;
}

vector <double> multiplication_matrix(const vector<vector<double>>& matrix4x4, const vector<double>& matrix1x4)
{
	vector <double> matrix(4);
	for (auto i1 = 0; i1 <= 3; i1++)
	{
		for (auto i2 = 0; i2 <= 3; i2++)
		{
			matrix[i1] += matrix4x4[i1][i2] * matrix1x4[i2];
		}
	}
	return matrix;
}

vector <vector<double>> set_matrix_criterion(const vector<vector<double>>& matrix, const int& criterion)
{
	vector <vector<double>> matrixret(4, vector<double>(4));
	for (auto i1 = 0; i1 <= 3; i1++)
	{
		for (auto i2 = 0; i2 <= 3; i2++)
		{
			if (matrix[i1][criterion] == matrix[i2][criterion]) matrixret[i1][i2] = 1;
			if (matrix[i1][criterion] > matrix[i2][criterion])
			{
				if (matrix[i1][criterion] - matrix[i2][criterion] == 1) matrixret[i1][i2] = 3;
				if (matrix[i1][criterion] - matrix[i2][criterion] == 2) matrixret[i1][i2] = 5;
				if (matrix[i1][criterion] - matrix[i2][criterion] == 3) matrixret[i1][i2] = 7;
				if (matrix[i1][criterion] - matrix[i2][criterion] == 4) matrixret[i1][i2] = 9;
			}
			if (matrix[i1][criterion] < matrix[i2][criterion])
			{
				if (matrix[i2][criterion] - matrix[i1][criterion] == 1) matrixret[i1][i2] = 1. / 3;
				if (matrix[i2][criterion] - matrix[i1][criterion] == 2) matrixret[i1][i2] = 1. / 5;
				if (matrix[i2][criterion] - matrix[i1][criterion] == 3) matrixret[i1][i2] = 1./ 7;
				if (matrix[i2][criterion] - matrix[i1][criterion] == 4) matrixret[i1][i2] = 1. / 9;
			}
		}
	}
	return matrixret;
}

vector <vector<double>> matrix_of_criterions(const vector<double>& criterion)
{
	vector <vector<double>> matrixret(4, vector<double>(4));
	for (auto i1 = 0; i1 <= 3; i1++)
	{
		for (auto i2 = 0; i2 <= 3; i2++)
		{
			if (criterion[i1] == criterion[i2]) matrixret[i2][i1] = 1;
			if (criterion[i1] > criterion[i2])
			{
				if (criterion[i1] - criterion[i2] == 1) matrixret[i2][i1] = 3;
				if (criterion[i1] - criterion[i2] == 2) matrixret[i2][i1] = 5;
				if (criterion[i1] - criterion[i2] == 3) matrixret[i2][i1] = 7;
				if (criterion[i1] - criterion[i2] == 4) matrixret[i2][i1] = 9;
			}
			if (criterion[i1] < criterion[i2])
			{
				if (criterion[i2] - criterion[i1] == 1) matrixret[i2][i1] = 1. / 3;
				if (criterion[i2] - criterion[i1] == 2) matrixret[i2][i1] = 1. / 5;
				if (criterion[i2] - criterion[i1] == 3) matrixret[i2][i1] = 1. / 7;
				if (criterion[i2] - criterion[i1] == 4) matrixret[i2][i1] = 1. / 8;
			}
		}
	}
	return matrixret;
}

vector <double> sumstr(const vector <vector<double>>& matrix)
{
	vector <double> sum(4);
	for (auto i1 = 0; i1 <= 3; i1++)
	{
		for (auto i2 = 0; i2 <= 3; i2++)
		{
			sum[i1] += matrix[i1][i2];
		}
	}
	return sum;
}

double utopia_coordinate(const vector<vector<double>>& matrix, const int& criterion)
{
	vector <double> v(4);
	for (auto i = 0; i <= 3; i++)
	{
		v[i] = matrix[i][criterion];
	}
	sort(begin(v), end(v));
	return v[3];
}

double manhattan_distance(const vector<vector<double>>& matrix, const double& utopia1, const double& utopia2, const int& criterion1, const int& criterion2, const int& alternative)
{
	double distance;
	distance = sqrt(pow(utopia1 - matrix[alternative][criterion1], 2) + pow(utopia2 - matrix[alternative][criterion2], 2));
	return distance;
}

// выводы

void print_abcd(const vector<vector<double>>& matrix)
{
	cout << "     1     2     3    4" << endl;
	cout << "A  ";
	for (auto i = 0; i <= 3; i++) cout << fixed << setprecision(2) << matrix[0][i] << "  ";
	cout << endl << "B  ";
	for (auto i = 0; i <= 3; i++) cout << matrix[1][i] << "  ";
	cout << endl << "C  ";
	for (auto i = 0; i <= 3; i++) cout << matrix[2][i] << "  ";
	cout << endl << "D  ";
	for (auto i = 0; i <= 3; i++) cout << matrix[3][i] << "  ";
}

void print_aabbccdd(const vector<vector<double>>& matrix, const vector<double>& sum, const vector<double>& normsum)
{
	cout << "     A      B      C      D     sum   norm" << endl;
	cout << "A  ";
	for (auto i = 0; i <= 3; i++) cout << fixed << setprecision(2) << setw(5) << matrix[0][i] << "  ";
	cout << setw(5) << sum[0] << "  " << normsum[0];
	cout << endl << "B  ";
	for (auto i = 0; i <= 3; i++) cout << setw(5) << matrix[1][i] << "  ";
	cout << setw(5) << sum[1] << "  " << normsum[1];
	cout << endl << "C  ";
	for (auto i = 0; i <= 3; i++) cout << setw(5) << matrix[2][i] << "  ";
	cout << setw(5) << sum[2] << "  " << normsum[2];
	cout << endl << "D  ";
	for (auto i = 0; i <= 3; i++) cout << setw(5) << matrix[3][i] << "  ";
	cout << setw(5) << sum[3] << "  " << normsum[3];
	cout << endl;
}

void print_1234(const vector < vector<double>>& matrix, const vector<double>& sum, const vector<double>& normsum)
{
	cout << "     1      2      3      4     sum   norm" << endl;
	cout << "1  ";
	for (auto i = 0; i <= 3; i++) cout << fixed << setprecision(2) << setw(5) << matrix[0][i] << "  ";
	cout << setw(5) << sum[0] << "  " << normsum[0];
	cout << endl << "2  ";
	for (auto i = 0; i <= 3; i++) cout << setw(5) << matrix[1][i] << "  ";
	cout << setw(5) << sum[1] << "  " << normsum[1];
	cout << endl << "3  ";
	for (auto i = 0; i <= 3; i++) cout << setw(5) << matrix[2][i] << "  ";
	cout << setw(5) << sum[2] << "  " << normsum[2];
	cout << endl << "4  ";
	for (auto i = 0; i <= 3; i++) cout << setw(5) << matrix[3][i] << "  ";
	cout << setw(5) << sum[3] << "  " << normsum[3];
	cout << endl;
}

void print4x1(const vector<double>& matrix)
{
	for (auto i : matrix) cout << i << endl;
}

int main()
{
	vector <vector<double>> matrix = { {4, 4, 7, 3}, {5, 6, 5, 5}, {7, 7, 7, 6}, {8, 6, 5, 7} };
	vector <double> criterion = { 2, 4, 8, 6 };
	setlocale(LC_ALL, "Russian");
	cout << endl << endl; // подключить русланг
	vector <double> matrix4x1 = norm4(criterion);
	print_abcd(matrix);
	cout << endl << endl;
	print4x1(matrix4x1);
	cout << endl;

	//метод змены критериев ограничения
	cout << "Метод замены критериев" << endl << endl;
	vector <vector<double>> matrix4x4 = norm_matix_criterion(matrix, 2);

	cout << "Нормированная матрица (кроме главного критерия: качество пляжа)" << endl;
	print_abcd(matrix4x4);
	cout << endl << endl;


	//метод сужения множества Парето длоя критериев 1 и 3
	cout << "Формирование и сужение множества Парето" << endl << endl;
	double utopia1 = utopia_coordinate(matrix, 0);
	double utopia2 = utopia_coordinate(matrix, 3);
	cout << "координаты точки утопии для критериев 1 и 4 (" << utopia1 << ", " << utopia2 << ")" << endl << endl;
	cout << "Расстояние Евклида:" << endl;
	cout << "Анатолий: " << manhattan_distance(matrix, utopia1, utopia2, 0, 3, 0) << endl;
	cout << "Александ: " << manhattan_distance(matrix, utopia1, utopia2, 0, 3, 1) << endl;
	cout << "Владимр: " << manhattan_distance(matrix, utopia1, utopia2, 0, 3, 2) << endl;
	cout << "Сергей: " << manhattan_distance(matrix, utopia1, utopia2, 0, 3, 3) << endl;
	cout << endl;

	//взвешивание и объединение критериев
	cout << "Взвешивание и объединение критериев" << endl << endl;
	cout << "Нормализованная матрица рейтингов альтернатив по критериям" << endl;

	matrix4x4 = norm4x4(matrix);
	print_abcd(matrix4x4);
	cout << endl << endl;

	cout << "Вектор весов критериев" << endl;
	matrix4x1 = set_vector_criterion(criterion);
	print4x1(matrix4x1);
	cout << endl;

	cout << "Нормализованный вектор весов критериев" << endl;
	matrix4x1 = norm4(matrix4x1);
	print4x1(matrix4x1);
	cout << endl;

	cout << "Значения объединенного критерия для всех альтернатив" << endl;
	matrix4x1 = multiplication_matrix(matrix4x4, matrix4x1);

	print4x1(matrix4x1);
	cout << endl;

	// метод анализа иерархий
	cout << "Метод анализа критериев" << endl << endl;

	vector <double> matrix1(4), matrix2(4), matrix3(4), matrix4(4), matrix5(4);
	vector <double> matrix1sum(4), matrix2sum(4), matrix3sum(4), matrix4sum(4), matrix5sum(4);

	matrix4x4 = set_matrix_criterion(matrix, 0);
	matrix1sum = sumstr(matrix4x4);
	matrix1 = norm4(matrix1sum);
	cout << endl << "Образование" << endl;

	print_aabbccdd(matrix4x4, matrix1sum, matrix1);

	matrix4x4 = set_matrix_criterion(matrix, 1);
	matrix2sum = sumstr(matrix4x4);
	matrix2 = norm4(matrix2sum);
	cout << endl << "Физподгатовка" << endl;

	print_aabbccdd(matrix4x4, matrix2sum, matrix2);

	matrix4x4 = set_matrix_criterion(matrix, 2);
	matrix3sum = sumstr(matrix4x4);
	matrix3 = norm4(matrix3sum);
	cout << endl << "Внешность" << endl;

	print_aabbccdd(matrix4x4, matrix3sum, matrix3);

	matrix4x4 = set_matrix_criterion(matrix, 3);
	matrix4sum = sumstr(matrix4x4);
	matrix4 = norm4(matrix4sum);
	cout << endl << "Характер" << endl;

	print_aabbccdd(matrix4x4, matrix4sum, matrix4);

	matrix4x4 = matrix_of_criterions(criterion);
	matrix5sum = sumstr(matrix4x4);
	matrix5 = norm4(matrix5sum);
	cout << endl << "Оценка приоритетов критериев" << endl;

	print_1234(matrix4x4, matrix5sum, matrix5);
	cout << endl << endl;

	for (auto i = 0; i <= 3; i++)
	{
		matrix4x4[i][0] = matrix1[i];
		matrix4x4[i][1] = matrix2[i];
		matrix4x4[i][2] = matrix3[i];
		matrix4x4[i][3] = matrix4[i];
	}

	for (auto i1 : matrix4x4)
	{
		for (auto i2 : i1) cout << i2 << " ";
		cout << endl;
	}

	cout << endl << endl;

	matrix4x1 = multiplication_matrix(matrix4x4, matrix5);

	print4x1(matrix4x1);
	cout << endl;

	system("pause");

	return 0;
}
