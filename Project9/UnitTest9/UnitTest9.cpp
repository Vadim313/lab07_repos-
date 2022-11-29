#include "pch.h"
#include "CppUnitTest.h"
#include "../Project9/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9
{
	TEST_CLASS(UnitTest9)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
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
			int S = 0;
			int k = 0;
			Calc(a, rowCount, colCount, S, k, 0, 0);
			PrintRows(a, rowCount, 0);
		}
	};
}
