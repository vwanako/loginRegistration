#include <iostream>

#include <login.h>
#include <registration.h>
#include <utils.h>

int main()
{
    char user_input;
    do
    {
        std::cout << "What would you like to do:\n1: login\n2: register\nq: quit program";
        switch (user_input)
        {
        case '1':
            login();
            break;
        case '2':
            register_account();
            break;
        case 'q':
            return 0;
        default:
            std::cout << "\nInvalid input. Try again.";
        }

    } while (user_input != 'q');

    return 0;
}