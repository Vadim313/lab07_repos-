#include "pch.h"
#include "CppUnitTest.h"
#include "../Project4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest4
{
	TEST_CLASS(UnitTest4)
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

			Create(a, rowCount, colCount, Low, High);
			//Input(a, rowCount, colCount);
			Print(a, rowCount, colCount);
			Part1_Count(a, rowCount, colCount);
			Sort(a, sumar, result, rowCount, colCount);
		}
	};
}
