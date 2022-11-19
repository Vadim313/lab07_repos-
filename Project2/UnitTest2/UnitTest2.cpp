#include "pch.h"
#include "CppUnitTest.h"
#include "../Project2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int Low = -10;
			int High = 50;
			int n = 4;
			int m = 5;
			int* arsum = new int[m];
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[m];
			Create(a, n, m, Low, High);
			Print(a, n, m);
			SearchMinEven(a, arsum, n, m);
		}
	};
}
