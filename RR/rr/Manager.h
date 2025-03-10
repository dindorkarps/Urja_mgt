#ifndef MANAGER_H
#define MANAGER_H


#include "Display.h"
#include "User.h"
#include "FoodItem.h"

#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Manager : public Display{
private:
    char userId[20];
    char userPass[20];

public:
    bool isValidateManager();
    bool isValidateUser();
    virtual void managerPage() = 0;
    
};

class ManagerSubclass : public Manager {
public:
    void managerMain(int i);
    void managerPage();
    
    
    void addStaff(User& u);
    void showStaff(User& u);
    void deleteStaff(User& u, char* id);
    void manageFoodItem(FoodItem& f);
    
};


#endif
