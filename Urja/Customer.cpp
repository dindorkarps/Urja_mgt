#include ".\headers\Customer.h"
#include "./headers/Order.h"

// Constructor
Customer::Customer() {}
Customer::Customer(int id, const std::string& name, const std::string& mobile) 
    :  mobile(mobile) {}

// Getter for mobile
std::string Customer::getMobile() const {
    return mobile;
}

// Setter for mobile
void Customer::setMobile(const std::string& mobile) {
    this->mobile = mobile;
}

void Customer::accept_Customer_Order()
{
    char ch;
	do{
        OrderItem newOrder;
        cout << "Enter dishItemID: ";
        // cin >> newOrder;
        // order.addItem(newOrder);

		
		
		cout << "\ntype 'Y' to add more items in order : ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	//newOrder.saveOrderinfile();
    
}

void Customer::displayOrder()
{
    
}