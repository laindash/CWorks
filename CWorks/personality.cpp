#include "personality.h"
#include "input.h"
#include <vector>

void Personality::Show(void) const
{
    std::cout
        << "************************************************" << std::endl
        << "| �������: " << _surname << std::endl
        << "| ���: " << _gender << std::endl
        << "| �����: " << _address.city << std::endl
        << "| �����: " << _address.street << std::endl
        << "| ���: " << _address.appart << std::endl
        << "| ��������: " << _address.flat << std::endl
        << "************************************************" << std::endl;
}

void Personality::SetSurname(void)
{
    std::cout << "������� �������: ";
    GetLine(std::cin, _surname, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Personality::SetSurnameFromFile(std::istream& input)
{
    std::getline(input, _surname);
}

void Personality::SetGender(void)
{
    std::cout << "������� ���: ";
    GetLine(std::cin, _gender, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Personality::SetGenderFromFile(std::istream& input)
{
    std::getline(input, _gender);
}

void Personality::SetAddress(void)
{
    std::cout << "������� �������� ������: ";
    GetLine(std::cin, _address.city, WITH_DIGITS, MANUAL_INPUT);
    std::cout << "������� �������� �����: ";
    GetLine(std::cin, _address.street, WITH_DIGITS, MANUAL_INPUT);

    std::cout << "������� ����� ����: ";
    GetLine(std::cin, _address.appart, ALMOST_ALL_DIGITS, MANUAL_INPUT);
    std::cout << "������� ����� ��������: ";
    GetLine(std::cin, _address.flat, ALMOST_ALL_DIGITS, MANUAL_INPUT);
}

void Personality::SetAddressFromFile(std::istream& input)
{
    std::getline(input, _address.city);
    std::getline(input, _address.street);
    std::getline(input, _address.appart);
    std::getline(input, _address.flat);
}

std::string Personality::GetSurname(void)
{
    return _surname;
}

std::string Personality::GetGender(void)
{
    return _gender;
}

AddressCW2 Personality::GetAddress(void)
{
    return _address;
}

void Personality::Delete(std::vector<Personality*>& personalities, int id)
{
    std::vector<Personality*>::iterator it = personalities.begin();
    advance(it, id);
    personalities.erase(it);
}