#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "header.h"

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
   
            if (inputUsername == "admin" && inputPassword == "admin")
            {
                return true;
            }
    return false;
}