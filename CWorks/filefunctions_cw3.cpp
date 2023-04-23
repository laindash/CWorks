#include <filesystem>
#include <fstream>
#include "input.h"
#include <iostream>
#include "cw3_functions.h"

bool IsDataCorrectCW3(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    int test_int{};
    int rows{}, columns{};
    std::string sort_name{};

    if (!file.eof())
    {
        file >> rows;
        if (rows > INT_MAX)
        {
            std::cout
                << "������ ���������� ���������� �����"
                << ", ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (file.fail() || rows <= 0)
        {
            std::cout << "������ ���������� ���������� �����" << std::endl;
            return false;
        }

        file >> columns;
        if (columns > INT_MAX)
        {
            std::cout
                << "������ ���������� ���������� ��������"
                << ", ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (file.fail() || columns <= 0)
        {
            std::cout << "������ ���������� ���������� ��������" << std::endl;
            return false;
        }

        file.get();
        GetLine(file, sort_name, WITHOUT_DIGITS, FILE_INPUT);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                file >> test_int;
                if (test_int > INT_MAX)
                {
                    std::cout
                        << "������ ���������� �������� ������"
                        << i + 1 << ' ' << j + 1
                        << ", ��������� ������������ ��������!" << std::endl;
                    return false;
                }
                if (file.fail())
                {
                    std::cout
                        << "������ ���������� �������� ������"
                        << i + 1 << ' ' << j + 1 << std::endl;
                    return false;
                }
            }
        }
        while (file.get() != EOF);
    }
    else 
        std::cout << "���� ����!";
    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file
    return true;
}

std::string CheckFileCW3()
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
        else if (!IsDataCorrectCW3(file))
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

void GetMatrixFromFile(std::vector<std::vector<int>>& matrix, int& rows, int& columns, std::string& path)
{
    std::ifstream file(path);
    std::string sort_name{};

    file >> rows >> columns;
    file.get();
    GetLine(file, sort_name, WITHOUT_DIGITS, FILE_INPUT);

    matrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i].resize(columns);
        for (int j = 0; j < columns; j++)
            file >> matrix[i][j];
    }

    std::cout << "������� ���������!" << std::endl;
    file.close();
}

void SaveToFile(std::vector<ISort*>& sorts, std::vector<ChessMatrix*>& cmatrices, std::vector<std::vector<int>>& arr, int rows, int columns)
{
    std::ofstream file;
    std::string path{};
    bool isOpened = false;

    std::error_code error{};
    int white_cage(0), black_cage(1);

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

    file << rows << ' ' << columns << std::endl;  //input rows and columns

    file << "����������� ������: " << std::endl; //input unsorted matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if ((i + j) % 2 == white_cage)
                file << arr[i][j] << ' ';
            else
                file << arr[i][j] << ' ';
        }
        file << std::endl;
    }

    std::vector<ChessMatrix*>::iterator cm_it = cmatrices.begin();  //input sorted matrices
    std::vector<ISort*>::iterator it = sorts.begin();
    for (; (it != sorts.end()) && (cm_it != cmatrices.end()); it++, cm_it++)
    {
        file << std::endl << (*it)->GetSortName() << std::endl;
        std::vector<std::vector<int>> sortedRows = (*cm_it)->GetSortedRows(), sortedColumns = (*cm_it)->GetSortedColumns();
        int el_index_even_row(0), el_index_odd_row(0), b_index(0), w_index(0);
        for (int i = 0; i < rows; i++)
        {
            int el_index = 0;
            if (columns != 1)
                w_index = i;

            for (int j = 0; j < columns; j++)
            {
                if (rows != 1)
                    b_index = j;

                if ((i + j) % 2 == white_cage)
                    file << sortedRows[w_index][el_index++] << ' ';
                else if (((i + j) % 2 == black_cage) && (i % 2 == 0))
                    file << sortedColumns[b_index++][el_index_even_row] << ' ';
                else if (((i + j) % 2 == black_cage) && (i % 2 == 1))
                    file << sortedColumns[b_index++][el_index_odd_row] << ' ';
            }
            if ((columns == 1) && (i % 2 == white_cage))
                w_index++;

            if (i % 2 == 0)
                el_index_even_row++;

            else
                el_index_odd_row++;

            file << std::endl;
        }
    }

    for (it = sorts.begin(); it != sorts.end(); it++) //input comparison table
    {
        file 
            << std::endl << (*it)->GetSortName() << std::endl
            << "(���������: " << (*it)->GetComparisons()
            << ", ������������: " << (*it)->GetSwaps() << ")" << std::endl;
    }
    std::cout << "������� ��������� � " << path << std::endl;
}
