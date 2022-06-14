#include "pch.h"
#include "CppUnitTest.h"
#include "ini_parser.h"
#include "img_proces.h"
#include <iostream>
#include "multithread.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(ini_directiories_exist)
		{
			Assert::AreEqual(0, ini_read());
		}

		TEST_METHOD(vector_size)
		{
			ini_read();
			read_input_folder_info();
			int x = Image.size();
			Assert::AreEqual(1, x);
		}
	};
}
