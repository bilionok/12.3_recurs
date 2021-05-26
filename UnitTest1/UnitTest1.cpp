#include "pch.h"
#include "CppUnitTest.h"
#include "../l_12_3_recur/l_12_3_recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL;
			Elem* last = NULL;
			enqueue(first, last, 1, 2);
			Assert::IsNotNull(last);

		}
	};
}
