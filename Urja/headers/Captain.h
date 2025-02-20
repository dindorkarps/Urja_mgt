#ifndef CAPTAIN_H
#define CAPTAIN_H

#include "User.h"

class Captain : public User {
public:
    // Constructor
    Captain(int id, const std::string& name, const std::string& role);
};

#endif // CAPTAIN_H