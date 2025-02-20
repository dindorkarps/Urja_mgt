#include ".\headers\User.h"
#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Constructor

User::User() {} // Default constructor

User::User(int id, const std::string& name, const std::string& role) 
    : id(id), name(name), role(role) {}

// Getters
int User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

std::string User::getRole() const {
    return role;
}

// Setters
void User::setId(int id) {
    this->id = id;
}

void User::setName(const std::string& name) {
    this->name = name;
}

void User::setRole(const std::string& role) {
    this->role = role;
}

bool User::validate_user(const std::string &inputUsername, const std::string &inputPassword)
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