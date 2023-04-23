#include "tests_cw1.h"
#include "clientclass.h"
#include "cw1_functions.h"
#include "filefunctions_cw1.h"

bool UnitTestCW1::TestCaseOne() // list sorted alphabetically
{
	const int clients_amount = 3;
	Name Name1{}, Name2{}, Name3{};
	std::string fullName1{}, fullName2{}, fullName3{}, ansName1{}, ansName2{}, ansName3{};
	Client* clients = nullptr;

	if (!AllocateArray(clients, clients_amount))
	{
		std::cout << "���� 1 ��������. ������ ��������� ������" << std::endl;
		return false;
	}
	else
		clients = new Client[clients_amount];

	GetListFromFile(clients, clients_amount, "test1.txt");
	ansName1 = "IvanIvanovIvanovich";
	ansName2 = "PetrPetrovPetrovich";
	ansName3 = "SidorSidorovSidorovich";
	SearchByAlph(clients, clients_amount);

	Name1 = clients[0].GetName();
	fullName1 = Name1.first_name + Name1.last_name + Name1.patronymic;
	Name2 = clients[1].GetName();
	fullName2 = Name2.first_name + Name2.last_name + Name2.patronymic;
	Name3 = clients[2].GetName();
	fullName3 = Name3.first_name + Name3.last_name + Name3.patronymic;
	system("cls");
	if (fullName1 != ansName1)
	{
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: " << "������ � ������ " << ansName1 << std::endl
			<< "��������: " << fullName1 << std::endl;
		return false;
	}
	if (fullName2 != ansName2)
	{
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: " << "������ � ������ " << ansName2 << std::endl
			<< "��������: " << fullName2 << std::endl;
		return false;
	}
	if (fullName3 != ansName3)
	{
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: " << "������ � ������ " << ansName3 << std::endl
			<< "��������: " << fullName3 << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW1::TestCaseTwo() // list is not sorted alphabetically
{
	const int clients_amount = 4;
	Name Name1{}, Name2{}, Name3{}, Name4{};
	std::string fullName1{}, fullName2{}, fullName3{}, fullName4{}, ansName1{}, ansName2{}, ansName3{}, ansName4{};
	Client* clients = nullptr;

	if (!AllocateArray(clients, clients_amount))
	{
		std::cout << "���� 2 ��������. ������ ��������� ������" << std::endl;
		return false;
	}
	else
		clients = new Client[clients_amount];

	GetListFromFile(clients, clients_amount, "test2.txt");
	ansName1 = "AntonAntonovAntonovich";
	ansName2 = "IvanIvanovIvanovich";
	ansName3 = "PetrPetrovPetrovich";
	ansName4 = "SidorSidorovSidorovich";
	SearchByAlph(clients, clients_amount);

	Name1 = clients[0].GetName();
	fullName1 = Name1.first_name + Name1.last_name + Name1.patronymic;
	Name2 = clients[1].GetName();
	fullName2 = Name2.first_name + Name2.last_name + Name2.patronymic;
	Name3 = clients[2].GetName();
	fullName3 = Name3.first_name + Name3.last_name + Name3.patronymic;
	Name4 = clients[3].GetName();
	fullName4 = Name4.first_name + Name4.last_name + Name4.patronymic;
	system("cls");
	if (fullName1 != ansName1)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "������ � ������ " << ansName1 << std::endl
			<< "��������: " << fullName1 << std::endl;
		return false;
	}
	if (fullName2 != ansName2)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "������ � ������ " << ansName2 << std::endl
			<< "��������: " << fullName2 << std::endl;
		return false;
	}
	if (fullName3 != ansName3)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "������ � ������ " << ansName3 << std::endl
			<< "��������: " << fullName3 << std::endl;
		return false;
	}
	if (fullName4 != ansName4)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "������ � ������ " << ansName4 << std::endl
			<< "��������: " << fullName4 << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW1::TestCaseThree() // all clients in the card range
{
	const int clients_amount = 3;
	std::string answer{};
	Contact Contact1{}, Contact2{}, Contact3{};
	long long cardNum1{}, cardNum2{}, cardNum3{}, ansContact1{}, ansContact2{}, ansContact3{};
	Client* clients = nullptr;

	if (!AllocateArray(clients, clients_amount))
	{
		std::cout << "���� 3 ��������. ������ ��������� ������" << std::endl;
		return false;
	}
	else
		clients = new Client[clients_amount];

	GetListFromFile(clients, clients_amount, "test3.txt");
	ansContact1 = 22223333;
	ansContact2 = 11112222;
	ansContact3 = 33334444;
	int lowBound = 1;
	int upBound = 40000000;

	system("cls");
	Contact1 = clients[0].GetContact();
	if (IsCardInRange(clients[0], upBound, lowBound))
	{
		cardNum1 = Contact1.card_num;
		answer = std::to_string(cardNum1);
	}
	else
		answer = "����� ������� �1 �� ������ � ��������";
	if (cardNum1 != ansContact1)
	{
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact1 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	Contact2 = clients[1].GetContact();
	if (IsCardInRange(clients[1], upBound, lowBound))
	{
		cardNum2 = Contact2.card_num;
		answer = std::to_string(cardNum2);
	}
	else
		answer = "����� ������� �2 �� ������ � ��������";
	if (cardNum2 != ansContact2)
	{
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact2 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	Contact3 = clients[2].GetContact();
	if (IsCardInRange(clients[2], upBound, lowBound))
	{
		cardNum3 = Contact3.card_num;
		answer = std::to_string(cardNum3);
	}
	else
		answer = "����� ������� �3 �� ������ � ��������";
	if (cardNum3 != ansContact3)
	{
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact3 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW1::TestCaseFour() // clients not in card range exist
{
	const int clients_amount = 5;
	std::string answer{}, ansContact4{}, ansContact5{};
	Contact Contact1{}, Contact2{}, Contact3{}, Contact4{}, Contact5{};
	long long cardNum1{}, cardNum2{}, cardNum3{}, cardNum4{}, cardNum5{}, ansContact1{}, ansContact2{}, ansContact3{};
	Client* clients = nullptr;

	if (!AllocateArray(clients, clients_amount))
	{
		std::cout << "���� 4 ��������. ������ ��������� ������" << std::endl;
		return false;
	}
	else
		clients = new Client[clients_amount];

	GetListFromFile(clients, clients_amount, "test4.txt");
	ansContact1 = 22223333;
	ansContact2 = 11112222;
	ansContact3 = 33334444;
	ansContact4 = "����� ������� �4 �� ������ � ��������";
	ansContact5 = "����� ������� �5 �� ������ � ��������";

	int lowBound = 1;
	int upBound = 40000000;

	system("cls");
	Contact1 = clients[0].GetContact();
	if (IsCardInRange(clients[0], upBound, lowBound))
	{
		cardNum1 = Contact1.card_num;
		answer = std::to_string(cardNum1);
	}
	else
		answer = "����� ������� �1 �� ������ � ��������";
	if (cardNum1 != ansContact1)
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact1 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	Contact2 = clients[1].GetContact();
	if (IsCardInRange(clients[1], upBound, lowBound))
	{
		cardNum2 = Contact2.card_num;
		answer = std::to_string(cardNum2);
	}
	else
		answer = "����� ������� �2 �� ������ � ��������";
	if (cardNum2 != ansContact2)
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact2 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	Contact3 = clients[2].GetContact();
	if (IsCardInRange(clients[2], upBound, lowBound))
	{
		cardNum3 = Contact3.card_num;
		answer = std::to_string(cardNum3);
	}
	else
		answer = "����� ������� �3 �� ������ � ��������";
	if (cardNum3 != ansContact3)
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact3 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	Contact4 = clients[3].GetContact();
	if (IsCardInRange(clients[3], upBound, lowBound))
	{
		cardNum4 = Contact4.card_num;
		answer = std::to_string(cardNum4);
	}
	else
		answer = "����� ������� �4 �� ������ � ��������";
	if (answer != ansContact4)
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact4 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	Contact5 = clients[4].GetContact();
	if (IsCardInRange(clients[4], upBound, lowBound))
	{
		cardNum5 = Contact5.card_num;
		answer = std::to_string(cardNum5);
	}
	else
		answer = "����� ������� �5 �� ������ � ��������";
	if (answer != ansContact5)
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact5 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW1::TestCaseFive() // no clients in card range
{
	const int clients_amount = 2;
	std::string answer{}, ansContact1{}, ansContact2{};
	Contact Contact1{}, Contact2{}, contact;
	long long cardNum1{}, cardNum2{};
	Client* clients = nullptr;

	if (!AllocateArray(clients, clients_amount))
	{
		std::cout << "���� 5 ��������. ������ ��������� ������" << std::endl;
		return false;
	}
	else
		clients = new Client[clients_amount];

	GetListFromFile(clients, clients_amount, "test5.txt");
	ansContact1 = "����� ������� �1 �� ������ � ��������";
	ansContact2 = "����� ������� �2 �� ������ � ��������";

	int lowBound = 1;
	int upBound = 40000000;

	system("cls");
	Contact1 = clients[0].GetContact();
	if (IsCardInRange(clients[0], upBound, lowBound))
	{
		cardNum1 = Contact1.card_num;
		answer = std::to_string(cardNum1);
	}
	else
		answer = "����� ������� �1 �� ������ � ��������";
	if (answer != ansContact1)
	{
		std::cout
			<< "���� 5 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact1 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	Contact2 = clients[1].GetContact();
	if (IsCardInRange(clients[1], upBound, lowBound))
	{
		cardNum2 = Contact2.card_num;
		answer = std::to_string(cardNum2);
	}
	else
		answer = "����� ������� �2 �� ������ � ��������";
	if (answer != ansContact2)
	{
		std::cout
			<< "���� 5 ��������." << std::endl
			<< "���������: " << "������ � ������� ����� " << ansContact2 << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	bool isThereAtLeastOne = false;
	for (int i = 0; i < clients_amount; i++)
		if (IsCardInRange(clients[i], upBound, lowBound))
		{
			isThereAtLeastOne = true;
			answer = std::to_string(contact.card_num);
			break;
		}
	if (isThereAtLeastOne)
	{
		std::cout
			<< "���� 5 ��������." << std::endl
			<< "���������: " << "�������� � �������� ��������� ���" << std::endl
			<< "��������: " << answer << std::endl;
		return false;
	}

	return true;
}

bool UnitTestCW1::TestCaseSix() // zero clients
{
	const int clients_amount = 0;
	Client* clients = nullptr;
	if (AllocateArray(clients, clients_amount))
	{
		std::cout << "���� 6 ��������. ������ ��������� ������" << std::endl;
		return false;
	}
	else
	{
		system("cls");
		return true;
	}
}

void UnitTestCW1::RunAllTests()
{
	UnitTestCW1 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive() && test.TestCaseSix())
		std::cout << "��� ��������� ����� ��������!" << std::endl;
	else
		std::cout << "��������� ����� �� ��������." << std::endl;
}
