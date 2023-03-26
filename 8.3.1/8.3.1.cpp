#include "pch.h"
#include "CppUnitTest.h"
#define _CRT_SECURE_NO_WARNINGS
#include "../8.1.3/8.1.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My831
{
	TEST_CLASS(My831)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[] = "abc++c-b===";

			const int numberOfPluses = countAppearences(str, "+");
			const int numberOfMinuses = countAppearences(str, "-");
			const int numberOfEquels = countAppearences(str, "=");

			Assert::AreEqual(numberOfPluses, 2);
			Assert::AreEqual(numberOfMinuses, 1);
			Assert::AreEqual(numberOfEquels, 3);

			const char* replacedString = replace(str, "++", "***");

			Assert::AreEqual(replacedString, "abc***c-b===");
		}
	};
}
