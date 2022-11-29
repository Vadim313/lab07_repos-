// Lab_7_1.cpp
// Галаган Вадим
// Лабораторна робота No 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 2
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int N, const int Low,
	const int High, int colNo);
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int N, int rowNo);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount, int j);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -41;
	int High = 23;
	int rowCount = 7;
	int colCount = 7;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	CreateRows(a, rowCount, Low, High, 0);
	PrintRows(a, rowCount, 0);
	Sort(a, rowCount, colCount);
	PrintRows(a, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k, 0, 0);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	PrintRows(a, rowCount, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void CreateRow(int** a, const int rowNo, const int N, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((a[i1][0] > a[i1 + 1][0])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] > a[i1 + 1][1])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] == a[i1 + 1][1] &&
					a[i1][4] < a[i1 + 1][4]))
				Change(a, i1, i1 + 1, colCount, 0);
}
void Change(int** a, const int row1, const int row2, const int colCount, int j)
{
	int tmp;
	if (j < colCount)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
		Change(a, row1, row2, colCount, j + 1);
	}
}
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{

	if (i < rowCount)
	{
		if(j < colCount)
		{
			if (a[i][j] < 0)
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
				Calc(a, rowCount, colCount, S, k, i, j + 1);
			}
		}
		Calc(a, rowCount, colCount, S, k, i + 1, 0);

	}
}
