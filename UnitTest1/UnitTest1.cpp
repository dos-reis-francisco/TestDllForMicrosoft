#include "pch.h"
#include "CppUnitTest.h"
#include "../MyClass.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double A [] ={ 1, 2, 
							3, 4};
			double B [] ={ 5, 6,
							7, 8};
			double expected [] ={ 19, 22,
							43, 50};

			MyMatrix mA(2, 2, A);
			MyMatrix mB(2, 2, B);
			MyMatrix mC = mA.Mul(mB);
			MyMatrix mExpected(2, 2, expected);

			Assert::IsTrue(mC == mExpected);
		}
	};
}
