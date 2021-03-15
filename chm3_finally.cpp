#include<iostream>
#include<iomanip>
using namespace std;
void outputall(double matrixA[4][4], double vectorB[4]);
void iteration(double matrixA[4][4], double vectorB[4], double X1[4], double X2[4]);
void outputone(double a[4]);
void copy(double X1[4], double X2[4]);
double comparison(double X1[4], double X2[4]);
void resvec(double matrixA[4][4], double vectorB[4], double X2[4]);

int main()
{
	double eps;
	setlocale(0, "");
	cout << "Введiть точнiсть:" << endl;
	cin >> eps;
	cout << "\nПочаткова матриця А i вектор В:" << endl;
	cout << " 8.3    3.02   4.1    1.90   |  -10.25\n 3.92   8.45   8.38   2.46   |  12.21\n\ 3.77   7.61   8.04   2.28   |  15.05\n\ 2.21   3.25   1.69   6.99   |  -8.35\n";
	cout << "\nПеретворена матриця А з дiагональною перевагою i вектор В:" << endl;
	double vectorB[4] = { -7.41, -2.84, 31.535, -5.51 };
	double matrixA[4][4] = { {8.15, 2.18, 3.76, 1.72},
							 {0.15, 0.84, 0.34, 0.18},
							 {-0.98, 2.74, 4.63, 0.61},
							 {2.06, 2.41, 1.35, 6.81} };
	double X1[4] = { 0, 0, 0, 0 };
	double X2[4] = { 0, 0, 0, 0 };
	outputall(matrixA, vectorB);
	cout << "\nЗгiдно з методом простої iтерацii вектор Х0 рівен:" << endl;
	outputone(X1);
	int k = 1;
	bool stop = false;
	double max;
	do {
		cout << "__________________________________________________________________________" << endl;
		cout << "\nIteration " << k << endl;
		iteration(matrixA, vectorB, X1, X2);     //подаются одинаковые векторы Х1 и Х2
		outputone(X2);							 //вывод полученного вектора Х2
		max = comparison(X1, X2);            //подаются разные значения векторов Х1 и Х2
		copy(X1, X2);						//копирование Х2 в вектор Х1
		resvec(matrixA, vectorB, X2);
		if (max < eps)							//сравнение максимальной разницы с заданной точностью
			stop = true;
		k++;
	} while (stop == false);
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "\nmax|X2[i]-X1[i]|= " << max << endl;
	cout << "\nЗначить отримане рiшення системи із заданою точнiстю: " << endl;
	outputone(X2);
	resvec(matrixA, vectorB, X2);
	system("pause");
	return 0;
}

void outputall(double matrixA[4][4], double vectorB[4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 4 - 1) {
				printf("%.7f", matrixA[i][j]);
				cout << "  |   ";
				printf("%.7f", vectorB[i]);
			}
			else
			{
				printf("%.7f", matrixA[i][j]);
				cout << "    ";
			}
		}
		cout << endl;
	}
}

void iteration(double matrixA[4][4], double vectorB[4], double X1[4], double X2[4]) //метод простой итерации
{
	for (int i = 0; i < 4; i++)
	{
		double sum = 0;
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				continue;
			}
			else
			{
				sum += (-1) * matrixA[i][j] * X1[j] / matrixA[i][i];
			}
		}
		sum += vectorB[i] / matrixA[i][i];
		X2[i] = sum;
	}
}

void outputone(double a[4])
{
	for (int i = 0; i < 4; i++)
	{
		cout << setw(5) << "x" << i << "= " << a[i];
	} cout << endl;
}

void copy(double X1[4], double X2[4])
{
	for (int i = 0; i < 4; i++)
	{
		X1[i] = X2[i];
	}
}

double comparison(double X1[4], double X2[4])     //нахождение модуля максимальной разницы между Х2 и Х1
{
	double X[4];
	for (int i = 0; i < 4; i++)
	{
		X[i] = abs(X2[i] - X1[i]);
	}
	double max = X[0];
	for (int i = 0; i < 4; i++)
	{
		if (X[i] >= max)
		{
			max = X[i];
		}
		else continue;
	}
	return max;
}

void resvec(double matrixA[4][4], double vectorB[4], double X2[4])   //вектор нев'язки
{
	double r[4];
	for (int i = 0; i < 4; i++)
	{
		double multip = 0;
		for (int j = 0; j < 4; j++)
		{
			multip += matrixA[i][j] * X2[j];
		}
		r[i] = vectorB[i] - multip;
	}
	cout << "Вектор нев'язки: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setw(15) << r[i];
	} cout << endl;
}
