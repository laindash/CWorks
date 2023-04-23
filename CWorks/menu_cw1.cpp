#include "cw_info.h"
#include "input.h"
#include "cw1_functions.h"

void StartModMenuCW1(Client* clients, int amount)
{
    int current_id{};
    Client current_Client{};

    ShowClients(clients, amount);
    do
    {
        std::cout << "������� id �������: " << std::endl;
        current_id = GetPosInt() - 1;
        if (current_id > amount - 1)
        {
            std::cout << "������! ������� � ������ ID �� ����������." << std::endl;
            continue;
        }
    } 
    while (current_id > amount - 1);

    current_Client = clients[current_id];
    ShowModMenuCW1();
    int user_choice = GetKey(MOD_NAME, DELETE);
    switch (user_choice)
    {
        case MOD_NAME:
            current_Client.SetName();
            break;

        case MOD_ADDRESS:
            current_Client.SetAddress();
            break;

        case MOD_CONTACT:
            current_Client.SetContact();
            break;

        case DELETE:
            current_Client.Delete();
            break;

        case QUIT:
            std::cout << "......................." << std::endl;
            break;
    }

    if (user_choice != QUIT)
    {
        std::cout
            << "����������� ���������?" << std::endl
            << "1 - ��, 2 - ���." << std::endl;
        if (GetKey(YES, NO) == YES)
            clients[current_id] = current_Client;
    }
}
