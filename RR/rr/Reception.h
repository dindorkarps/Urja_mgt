#ifndef RECEPTION_H
#define RECEPTION_H

#include <iostream>
#include <vector>
#include "Customer.h"
#include "FoodItem.h"

#define MAX_TABLES 10  // Total number of tables

class Reception {
private:
    std::vector<bool> tables;  // Use vector for table availability

public:
    Reception();         // Constructor to initialize occupied tables
    void receptionPage();
    void addCustomer();
    void assignTable();
    bool isTableAvailable(int);
    int showBill(int);
    void checkOut(int);
};

#endif // RECEPTION_H
