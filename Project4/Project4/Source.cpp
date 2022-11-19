#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int Part1_Count(int** a, const int rowCount, const int colCount);
void Sort(int** a, int* sumar , int** result,  const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);

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
	Create(a, rowCount, colCount, Low, High);
	//Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	cout << "the number of columns that do not have any null elements: " << (Part1_Count(a, rowCount, colCount)) << endl<<endl;

	Sort(a, sumar, result,rowCount, colCount);
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	delete[] sumar;
	for (int i = 0; i < rowCount; i++)
		delete[] result[i];
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
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
int Part1_Count(int** a, const int rowCount, const int colCount)
{
	
	int count = 0;
	for (int j = 0; j < colCount; j++)
	{
		int k_zero = 0;
		for (int i = 0; i < rowCount; i++)
			if (a[i][j] != 0)
			{
				k_zero++;
			}
		if (k_zero == rowCount)
			count++;
	}
	return count;
}

void Sort(int** a, int* sumar, int** result, const int rowCount, const int colCount)
{
	

	for (int i = 0; i < rowCount; i++)
	{
		int sum = 0;
		for (int j = 0; j < colCount; j++)
		{
			if (a[i][j] > 0 && a[i][j] % 2 == 0)
			{
				sum += a[i][j];
			}

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
			{
				min = sumar[i];
				min_index = i;
			}
		}
		sumar[min_index] = -1;
		
		for (int k = 0; k < colCount; k++)
		{
			result[j][k] = a[min_index][k];
		}


	}
	cout << "Array after sort:";
	Print(result, rowCount, colCount);
}

