#ifndef RECEPTION_H
#define RECEPTION_H

#include "User.h"

class Receptionist : public User {
public:
    // Constructor
    Receptionist(int id, const std::string& name, const std::string& role);
};

#endif // RECEPTION_H