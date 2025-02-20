#include ".\headers\Login.h"
#include <iostream>
using namespace std;
void Login::accept_user()
    {
        cout << "Enter your username: ";
        std::cin >> username;
        std::cout << "Enter your password: ";
        std::cin >> password;
    }

    // void Login::add_user_in_file()
    // {
    //     std::ofstream file;
    //     file.open("login.txt", ios::app);
    //     file << username << " " << password << std::endl;
    //     file.close();
    // }

    // void Login::read_user_from_file()
    // {
    //     std::ifstream file;
    //     file.open("login.txt");
    //     if (file.is_open())
    //     {
    //         while (!file.eof())
    //         {
    //             file >> username >> password;
    //             std::cout << "Username: " << username << " Password: " << password << std::endl;
    //         }
    //     }
    //     file.close();
    // }

    bool Login::validate_user(const std::string &inputUsername, const std::string &inputPassword)
    {
        std::ifstream file("login.txt");
        std::string fileUsername, filePassword;
        if (file.is_open())
        {
            while (file >> fileUsername >> filePassword)
            {
                if (inputUsername == fileUsername && inputPassword == filePassword)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void Login::login()
    {
        std::string inputUsername;
        std::string inputPassword;
        std::cout << "Enter your username: ";
        std::cin >> inputUsername;
        std::cout << "Enter your password: ";
        std::cin >> inputPassword;

        if (validate_user(inputUsername, inputPassword))
        {
            std::cout << "You are logged in!" << std::endl;
        }
        else
        {
            std::cout << "Invalid username or password!" << std::endl;
        }
    }
