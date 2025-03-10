#ifndef USER_H
#define USER_H

#include <iostream>

class ManagerSubclass; // Forward declaration

class User {
private:
    char uid[20];
    char password[20];
    char role[10];

public:
    const char* getuid() const;      // Marked as const
    const char* getpassword() const; // Marked as const
    const char* getrole() const;

    friend class ManagerSubclass; // ManagerSubclass can access private members
};

#endif // USER_H
