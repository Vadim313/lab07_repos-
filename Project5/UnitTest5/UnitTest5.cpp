#include "pch.h"
#include "CppUnitTest.h"
#include "../Project5/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
	TEST_CLASS(UnitTest5)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int Low = -10;
			int High = 15;
			int rowCount = 5;
			int colCount = 6;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			int** result = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				result[i] = new int[colCount];
			int* sumar = new int[colCount];
			int count = 0;
			CreateRows(a, rowCount, colCount, Low, High, 0);
			PrintRows(a, rowCount, colCount, 0);
			Part1_CountCols(a, rowCount, colCount, count, 0, 0);
			Sorts(a, sumar, result, rowCount, colCount);
		}
	};
};
