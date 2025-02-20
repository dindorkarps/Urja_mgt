#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    int id;
    std::string name;
    std::string role;

public:
    // Constructor
    User(); 
    User(int id, const std::string& name, const std::string& role);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getRole() const;

    // Setters
    void setId(int id);
    void setName(const std::string& name);
    void setRole(const std::string& role);
    bool validate_user(const std::string &inputUsername, const std::string &inputPassword);
    };

#endif // USER_H