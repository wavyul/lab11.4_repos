#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include "../LB11.4/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestAnalyzeFile)
        {
            ofstream infile("t.txt");
            infile << "aabbaa\n";
            infile << "aaaaaa\n";
            infile << "\n";
            infile << "bbabba\n";
            infile << "abcde\n";
            infile.close();

            AnalyzeFile('a');

            ifstream outfile("result.txt");
            Assert::IsTrue(outfile.is_open(), L"Failed to open result.txt for reading");

            string line;
            getline(outfile, line);
            Assert::AreEqual(string("Number of lines starting with character 'a': 3"), line);

            getline(outfile, line);
            Assert::AreEqual(string("Number of lines starting and ending with the same character: 2"), line);

            getline(outfile, line);
            Assert::AreEqual(string("Number of lines with identical characters: 1"), line);

            getline(outfile, line);
            Assert::AreEqual(string("Number of empty lines: 1"), line);

            outfile.close();
        }
    };
}
