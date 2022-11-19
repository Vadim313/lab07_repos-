#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int SearchMinEven(int** a, int* arsum, const int n, const int m);
int main()
{
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 50;
	int n;
	cout << "Висота масива: n = "; cin >> n;
	int m;
	cout << "Довжина масива: m = "; cin >> m;
	int* arsum = new int[n];
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	Create(a, n, m, Low, High);
	Print(a, n, m);

	cout << (SearchMinEven(a, arsum, n, m));
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	delete[] arsum;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int SearchMinEven(int** a, int* arsum, const int n, const int m)
{

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		for (int j = 0; j < m; j++)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
			}
			arsum[i] = max;
		}
	}
	for (int i = 0; i < n; i++)
	{
		sum += arsum[i];

	}
	cout << "сума всiх найбiльших елементiв кожного рядка: ";
	return sum;
}