#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <login.h>
#include <utils.h>

std::string name, username, password;
std::fstream accounts_file;
std::vector<std::string> user_info;

void receive_information()
{
    std::cout << "\nUsername: ";
    std::cin >> username;

    while (!check_username_exists(username))
    {
        std::cout << "\nUsername not found. Please try again.\n";
        std::cin.ignore();
        std::cin >> username;
    }

    std::cout << "\nPassword: ";
    std::cin.ignore();
    std::cin >> password;

    user_info.push_back(username);
    user_info.push_back(password);
}

void authenticate_credentials()
{
    accounts_file.open("accounts.txt", std::ios::in);
    if (accounts_file.is_open())
    {
        std::string line;
        while (getline(accounts_file, line))
        {
            std::vector<std::string> tokens = parse(line);

            if (tokens[1] == user_info[0] && tokens[2] == user_info[1])
                std::cout << "Login successful." << std::endl;
            accounts_file.close();
        }
        std::cout << "Login failed. Please try again." << std::endl;
        accounts_file.close();
        receive_information();
    }
}

void login()
{
    receive_information();
    authenticate_credentials();
}