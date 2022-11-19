// Lab_7_3.cpp
// Галаган Вадим
// Лабораторна робота No 7.3.
// Опрацювання динамічних багатовимірних масивів. Рекурсивний спосіб.
// Варіант 2

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int Part1_CountCols(int** a, const int rowCount, const int colCount, int& count, int j, int k_zero);

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void Sorts(int** a, int* sumar, int** result, const int rowCount, const int colCount)
{

	for (int i = 0; i < rowCount; i++)
	{
		int sum = 0;
		for (int j = 0; j < colCount; j++)
		{
			if (a[i][j] > 0 && a[i][j] % 2 == 0)
			{sum += a[i][j];}
		}
		sumar[i] = sum;
	}
	int min_index = 0;
	for (int j = 0; j < rowCount; j++)
	{
		int min = 100;
		for (int i = 0; i < colCount; i++)
		{
			if (sumar[i] < min && sumar[i] >= 0)
			{min = sumar[i];min_index = i;}
		}
		sumar[min_index] = -1;
		for (int k = 0; k < colCount; k++)
		{result[j][k] = a[min_index][k];		}
	}
	cout << "Array after sort:";
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << result[i][j];
		cout << endl;
	}
	cout << endl;
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void CreateRow(int** a, const int rowNo, const int colCount,
	const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}
void CreateRows(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}
void Part1_ZeroCol(int** a, int& k_zero, int count, int rowCount, int colCount, int j)
{
	if (k_zero == rowCount)
	{
		count++;
	}
	Part1_CountCols(a, rowCount, colCount, count, j + 1, k_zero);
	
}
int Part1_CountCol(int** a, const int rowCount, int& count, int j, int i , int k_zero, int colCount)
{
	if(i < rowCount)
	{
		if (a[i][j] != 0)
		{
			k_zero++;
		}
		return Part1_CountCol(a, rowCount, count, j, i + 1, k_zero, colCount);
	}
	return k_zero;
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
int Part1_CountCols(int** a, const int rowCount, const int colCount, int& count, int j, int k_zero)
{
	if (j < colCount)
	{
		if(Part1_CountCol(a, rowCount, count, j, 0, k_zero, colCount) == rowCount)
		{
			count++;
		}
		return Part1_CountCols(a, rowCount, colCount, count, j + 1, 0);
	}
	return count;
}
int Sort5(int** a, int** result, int min_index, int j, int k, int colCount)
{
	if (k < colCount)
	{
		result[j][k] = a[min_index][k];
		return Sort5(a, result, min_index, j, k + 1, colCount);
	}
}
int Sort4 (int* sumar, int colCount, int i, int j, int min, int min_index)
{
	if (sumar[i] < min)
	{
		if (sumar[i] >= 0)
		{
			min = sumar[i];	
			min_index = i;
		}
		return Sort4(sumar, colCount, i+1, j, min, min_index);
	}
	return min_index;
}
void Sort3(int** a, int* sumar, int** result, const int rowCount, const int colCount, int i, int j, int min_index, int min)
{
	if (j < rowCount)
	{
		int min = 100;
		min_index = Sort4(sumar, colCount, i, j, min, min_index);
		sumar[min_index] = -1;

		Sort5(a, result, min_index, j, 0, colCount);
		j++;
	}

}
int Sort2(int** a, int*sumar, int colCount, int i, int j, int sum)
{
	if (j < colCount)
	{
		if (a[i][j] > 0)
			if(a[i][j] % 2 == 0)
				sum += a[i][j];
		return Sort2(a, sumar, colCount, i, j+1, sum);
	}
	return sum;
}
void Sort(int** a, int* sumar, int** result, const int rowCount, const int colCount, int i, int j, int sum)
{
	if (i < rowCount)
	{
		sumar[i] = Sort2(a, sumar, colCount, i, 0, 0);
		Sort(a, sumar, result, rowCount, colCount, i + 1, 0, 0);
	}
	cout << endl;
	
	Sort3(a, sumar, result, rowCount, colCount, 0, 0, 0, 100);
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 15;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	int** result = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		result[i] = new int[colCount];
	int* sumar = new int[colCount];
		CreateRows(a, rowCount, colCount, Low, High, 0);
		//InputRows(a, rowCount, colCount, 0);
	PrintRows(a, rowCount, colCount, 0);
	int count = 0;
	
	cout << "the number of columns that do not have any null elements: "<< Part1_CountCols(a, rowCount, colCount, count, 0, 0);
	Sorts(a, sumar, result, rowCount, colCount);
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}