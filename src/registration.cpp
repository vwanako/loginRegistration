#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <registration.h>
#include <utils.h>

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

    while (check_username_exists(username))
    {
        std::cout << "\nUsername already exists. Please enter a new username or press 'q' to exit registration process.";
        std::cin.ignore();
        std::cin >> username;
        if (username == "q")
        {
            return;
        }
    }

    std::cout << "\nPassword: ";
    std::cin.ignore();
    std::cin >> password;

    user_info.push_back(name);
    user_info.push_back(username);
    user_info.push_back(password);
}

void save_to_file()
{
    accounts_file.open("res/accounts.txt", std::ios::app);

    if (accounts_file.is_open())
        accounts_file << user_info[0] << "," << user_info[1] << "," << user_info[2] << std::endl;
    else
        std::cerr << "\nError opening file." << std::endl;
}

void register_account()
{
    void receive_information();
    void save_to_file();
}
