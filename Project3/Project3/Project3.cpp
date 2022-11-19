// Lab_7_2_2.cpp
// Галаган Вадим
// Лабораторна робота No 7.2.2
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 2
#include <iostream>
#include <iomanip>
#include <time.h>
int SearchSum(int** a, int N, int M, int i, int j, int max, int* arsum);
int Sum(int* arsum, int sum, int i, int N);

using namespace std;
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
int SearchFirstSum(int** a, const int N, const int M, int i, int* arsum)
{
	if (i < N)
	{
		int max = 0;
		SearchSum(a, N, M, i, 0, max, arsum);
	}
	return Sum(arsum, 0, 0, N);
}

int SearchSum(int** a, int N, int M, int i, int j, int max, int* arsum)
{
	if (j < M)
	{
		if (max < a[i][j])
		{
			max = a[i][j];

		}
		arsum[i] = max;
		return SearchSum(a, N, M, i, j + 1, max, arsum);
	}
	return SearchFirstSum(a, N, M, i + 1, arsum);
}

int Sum(int* arsum, int sum, int i, int N)
{
	if (i < N)
	{
		sum += arsum[i];
		return Sum(arsum, sum, i + 1, N);
	}
	return sum;

}

int main()
{
	srand((unsigned)time(NULL));
	int N, M;
	cout << "N = "; cin >> N;
	cout << "M = "; cin >> M;
	cout << endl;
	int* arsum = new int[N];
	int** a = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[M];
	int Low = -10, High = 50;
	CreateRows(a, N, Low, High, 0);
	PrintRows(a, N, 0);
	cout << SearchFirstSum(a, N, M, 0, arsum);
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}