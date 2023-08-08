#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <registration.h>

std::string name, username, password;
std::fstream accounts_file;
std::vector<std::string> user_info;

void receive_information()
{
    std::cout << "\nName: ";
    std::cin.ignore();
    std::cin >> name;

    std::cout << "\nUsername: ";
    std::cin.ignore();
    std::cin >> username;

    std::cout << "\nPassword: ";
    std::cin.ignore();
    std::cin >> password;

    user_info.push_back(name);
    user_info.push_back(username);
    user_info.push_back(password);
}

void save_to_file()
{
    accounts_file.open("res/accounts.txt");

    if (accounts_file.is_open())
        accounts_file << user_info[0] << "," << user_info[1] << "," << user_info[2] << std::endl;
    else
        std::cerr << "\nError opening file." << std::endl;
}
