
#ifndef LOGIN_H
#define LOGIN_H


#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
class Login
{
private:
    std::string username;
    std::string password;

public:
    void accept_user();
    // void add_user_in_file();
    // void read_user_from_file();
    bool validate_user(const std::string &inputUsername, const std::string &inputPassword);
    void login();
};
#endif