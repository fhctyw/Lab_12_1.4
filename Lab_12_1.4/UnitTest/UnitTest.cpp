#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_1.4\Student.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student s;
			s.Init("Іван Іванович", "IT-12", 4.1);
			Assert::AreEqual(s.getGroup(), string("IT-12"));
		}
	};
}
