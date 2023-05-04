#include "tests_cw4.h"
#include "cw4_functions.h"
#include "filefunctions_cw4.h"
#include <iostream>
#include <fstream>
#include <filesystem>


bool UnitTestCW4::TestCaseOne() // test modify 1 substring
{
	size_t substring_size = 2;
	std::string 
		testString = "testovaya stroka",
		resultString{},
		expectedResult = "testovaya {3, 2}roka";

	StartModify(testString, resultString, substring_size);
	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::TestCaseTwo() // test modify more than 1 substring
{
	size_t substring_size = 4;
	std::string 
		testString = "testovaya stroka stroka troka strstrroka",
		resultString{},
		expectedResult = "testovaya stroka {11, 4}ka {12, 4}a strstr{13, 4}";

	StartModify(testString, resultString, substring_size);
	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::TestCaseThree() // test restore 1 substring
{
	std::string 
		testString = "testovaya {3, 2}roka",
		resultString{},
		expectedResult = "testovaya stroka"; 

	StartRestore(testString, resultString);
	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::TestCaseFour() // test restore more than 1 substring
{
	std::string 
		testString = "testovaya stroka {11, 4}ka {12, 4}a strstr{13, 4}",
		resultString{},
		expectedResult = "testovaya stroka stroka troka strstrroka";

	StartRestore(testString, resultString);
	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW4::TestCaseFive() // check getting text from file
{
	std::string 
		path = "test5cw4.txt", 
		resultString{},
		expectedResult = "Neque porro quisquam est qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit...";

	if (!std::ifstream(path))
	{
		std::cout
			<< "���� 5 ��������." << std::endl
			<< "���������: " << "���� ������!" << std::endl
			<< "��������: " << "���� �� ������!" << std::endl;
		return false;
	}

	GetTextFromFile(resultString, path);

	if (resultString != expectedResult)
	{
		std::cout
			<< "���� 5 ��������." << std::endl
			<< "���������: " << expectedResult << std::endl
			<< "��������: " << resultString << std::endl;
		return false;
	}

	return true;
}


void UnitTestCW4::RunAllTests()
{
	UnitTestCW4 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
	{
		system("cls");
		std::cout << "��� ��������� ����� ��������!" << std::endl;
	}
	else
		std::cout << "��������� ����� �� ��������." << std::endl;
}
