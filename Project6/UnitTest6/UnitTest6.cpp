#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest6
{
	TEST_CLASS(UnitTest6)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int  size = 10;
			int i = 0;
			int* a = new int[size];
			
			arr(size, a, i, i);
			rand(size, a, i);
			in(a, size, i, a[0]);

		}
	};
}
