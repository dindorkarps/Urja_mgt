#ifndef MANAGER_H
#define MANAGER_H

#include "User.h"

class Manager : public User {
    
public:
    // Constructor
    Manager();
    Manager(int id, const std::string& name, const std::string& role);

    // Method to display manager information
    void displayInfo() const;
    void managerMenuHandler();
    void addFoodMenu();
    void viewFoodMenu();
    void editFoodMenu();
    void deleteFoodMenu();
    void viewBillDateRange();
    void viewTodaysBill();
};

#endif // MANAGER_H