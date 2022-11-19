#include "pch.h"
#include "CppUnitTest.h"
#include "../Project3/Project3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 5;
			int M = 5;
			int* arsum = new int[N];
			int** a = new int* [N];
			for (int i = 0; i < N; i++)
				a[i] = new int[M];
			int Low = -10, High = 50;
			CreateRows(a, N, Low, High, 0);
			PrintRows(a, N, 0);
			SearchFirstSum(a, N, M, 0, arsum);
		}
	};
}
