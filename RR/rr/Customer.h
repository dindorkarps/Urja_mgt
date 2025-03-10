#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
public:
    char customerName[20];
    int tableNumber;
    int orderListId[10];
    int orderCount; // Track number of orders

    // Constructor to initialize default values
    Customer() : tableNumber(0), orderCount(0) {
        customerName[0] = '\0'; // Initialize as empty string
        for (int &id : orderListId) {
            id = 0; // Initialize order list IDs to 0
        }
    }
};

#endif // CUSTOMER_H
