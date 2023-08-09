#include <iostream>
#include <fstream>
#include <vector>

#include <utils.h>

std::fstream accounts_file;

std::vector<std::string> parse(const std::string &line)
{
    // each text between ","
    std::vector<std::string> tokens;
    std::string temp_line;

    for (unsigned int i = 0; i < line.size(); i++)
    {
        if (line[i] == ',')
        {
            tokens.push_back(temp_line);
            temp_line.clear();
            continue;
        }

        temp_line += line[i];
    }

    tokens.push_back(temp_line);
    return tokens;
}

bool check_username_exists(const std::string &username)
{
    accounts_file.open("accounts.txt", std::ios::in);

    if (accounts_file.is_open())
    {
        std::string line;
        while (getline(accounts_file, line))
        {
            std::vector<std::string> tokens = parse(line);
            if (tokens[1] == username)
            {
                accounts_file.close();
                return true;
            }
        }
        accounts_file.close();
        return false;
    }
    else
    {
        std::cerr << "Error opening file" << std::endl;
        return false;
    }
}