#include <filesystem>
#include <fstream>
#include "personality.h"
#include "universityemployee.h"
#include "input.h"


bool IsDataCorrectCW2(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};
    double test_double{};
    while (!file.eof())
    {
        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //surname
        if (test_string.empty())
        {
            std::cout << "������ ���������� �������" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //gender
        if (test_string.empty())
        {
            std::cout << "������ ���������� ����" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //city
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //street
        if (test_string.empty())
        {
            std::cout << "������ ���������� �����" << std::endl;
            return false;
        }

        GetLine(file, test_string, ALMOST_ALL_DIGITS, FILE_INPUT); //appart
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������ ����" << std::endl;
            return false;
        }

        GetLine(file, test_string, ALMOST_ALL_DIGITS, FILE_INPUT); //flat
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������ ��������" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //position
        if (test_string.empty())
        {
            std::cout << "������ ���������� ��������� ����������" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITHOUT_DIGITS, FILE_INPUT); //department
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������� ����������" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //resp
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������������ ����������" << std::endl;
            return false;
        }

        file >> test_double;
        if (test_double > DBL_WRONG)
        {
            std::cout << "������ ���������� �������� ����������, ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (file.fail())
        {
            std::cout << "������ ���������� �������� ����������" << std::endl;
            return false; //Returns false if salary not be read
        }
        file.get();
    }
    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file

    return true;
}

std::string CheckFileCW2(void)
{
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do
    {
        std::cout << "������� ���� � �����: ";
        GetLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (!std::ifstream(path))
        {
            std::cout << "��������� ���� �� ������!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error))
        {
            std::cout << "������, ������������ ����� �����!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file)
        {
            std::cout << "������ �������� �����!" << std::endl;
            file.close();
        }
        else if (!IsDataCorrectCW2(file))
        {
            std::cout << "������ �����������!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "���� ������!" << std::endl;
    file.close();

    return path;
}

void GetEmployeesFromFile(std::vector<Personality*>& employees, int amount, std::string path = CheckFileCW2())
{
    std::ifstream file(path);

    for (int i = 0; i < amount && !file.eof(); i++)
    {
        UniversityEmployee* new_employee = new UniversityEmployee;
        new_employee->SetSurnameFromFile(file);
        new_employee->SetGenderFromFile(file);
        new_employee->SetAddressFromFile(file);
        new_employee->SetPositionFromFile(file);
        new_employee->SetDepartmentFromFile(file);
        new_employee->SetResponsibilitiesFromFile(file);
        new_employee->SetSalaryFromFile(file);
        employees.push_back(new_employee);
    }

    std::cout << "������ ��������!" << std::endl;

    file.close();
}

void SaveToFile(std::vector<Personality*>& employees)
{
    std::ofstream file;
    std::string path{};
    bool isOpened = false;

    std::error_code error{};

    do
    {
        std::cout
            << "������� ���� � ����� ��� ����������. "
            << "���� ������� ������ ��� � ���������� �����, ����������� ���� ����� �������� ���� � ��������� ���� ���������." << std::endl;
        std::getline(std::cin, path);

        if (std::ifstream(path))
        {
            if (!std::filesystem::is_regular_file(path, error))
            {
                std::cout << "������, ������������ ����� �����!" << std::endl;
                continue;
            }

            std::cout
                << "������ ���� ��� ����������!." << std::endl
                << "1 - ������������." << std::endl
                << "2 - ������� ������." << std::endl;

            if (GetKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "������ �������� �����!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    std::string outputSurname{}, outputGender{},
        outputPosition{}, outputDepartment{}, outputResponsibilities{};
    AddressCW2 outputAddress{};
    double outputSalary{};
    for (std::vector<Personality*>::iterator it = employees.begin(); it != employees.end() && !(dynamic_cast<UniversityEmployee*>(*it)->IsEmpty()); it++)
    {
        outputSurname = (*it)->GetSurname();
        outputGender = (*it)->GetGender();
        outputAddress = (*it)->GetAddress();
        outputPosition = dynamic_cast<UniversityEmployee*>(*it)->GetPosition();
        outputDepartment = dynamic_cast<UniversityEmployee*>(*it)->GetDepartment();
        outputResponsibilities = dynamic_cast<UniversityEmployee*>(*it)->GetResponsibilities();
        outputSalary = dynamic_cast<UniversityEmployee*>(*it)->GetSalary();

        if (it != employees.begin())
            file << std::endl;
        file << outputSurname << std::endl;
        file << outputGender << std::endl;
        file << outputAddress.city << std::endl 
             << outputAddress.street << std::endl 
             << outputAddress.appart << std::endl 
             << outputAddress.flat << std::endl;
        file << outputPosition << std::endl;
        file << outputDepartment << std::endl;
        file << outputResponsibilities << std::endl;
        file << outputSalary;
    }
    std::cout << "������� ��������� � " << path << std::endl;
}

int CountStringsCW2(std::string path)
{
    int stringsAmount{};

    std::ifstream file;
    file.open(path);
    std::string tmp{};

    while (!file.eof())
    {
        std::getline(file, tmp);
        stringsAmount++;
    }

    return stringsAmount;
}