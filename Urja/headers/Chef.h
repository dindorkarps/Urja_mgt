#ifndef CHEIF_H
#define CHEIF_H

#include "User.h"

class Chef : public User {
public:
    // Constructor
    Chef(int id, const std::string& name, const std::string& role);
};

#endif // CHEIF_H