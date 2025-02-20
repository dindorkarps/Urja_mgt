#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <iostream>
#include "Order.h"

class Customer {
private:
    std::string mobile;
    std::string name;
    int tableNumber;
    Order order;

public:
    // Constructor
    Customer(){};
    Customer(int id, const std::string& name, const std::string& mobile){};

    // Getter for mobile
    std::string getMobile() const;

    // Setter for mobile
    void setMobile(const std::string& mobile);
    
    void accept_Customer_Order();
    void displayOrder();
}

#endif // CUSTOMER_H