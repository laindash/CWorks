#include <filesystem>
#include <fstream>
#include "input.h"
#include <iostream>
#include "cw4_functions.h"

bool IsDataCorrectCW4(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};
    if (file.eof())
    {
        std::cout << "���� ����!";
        return false;
    }

    return true;
}

std::string CheckFileCW4()
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
        else if (!IsDataCorrectCW4(file))
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

void GetStringsFromFile(std::vector<std::string>& strings, std::string& path)
{
    std::ifstream file(path);
    std::string text{};

    while (!file.eof())
    {
        GetLine(file, text, WITH_DIGITS, FILE_INPUT);
        strings.push_back(text);
    }

    std::cout << "����� ��������!" << std::endl;
    file.close();
}

void SaveToFile(std::vector<std::string>& strings, std::vector<std::string>& changedStrings, int save_choice)
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
        GetLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);
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


    if (save_choice == SAVE_RESTORED)
    {
        for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
        {
            file << (*it);
            if (!(it == strings.end() - 1))
                file << std::endl;
        }
    }

    else if (save_choice == SAVE_MODIFIED)
    {
        for (std::vector<std::string>::iterator it = changedStrings.begin(); it != changedStrings.end(); it++)
        {
            file << (*it);
            if (!(it == changedStrings.end() - 1))
                file << std::endl;
        }
    }

    std::cout << "������� ��������� � " << path << std::endl;
}
