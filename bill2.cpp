
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Define classes for Customer, Order, MenuItem, and Bill
class Customer 
{
public:
    string name;
    int tableNumber;

    void registerCustomer() 
    {
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter table number: ";
        cin >> tableNumber;
    }
};

class MenuItem 
{
    /*public:
    string name;
    double price;
    int quatity;

    void addMenuItem() {
        cout << "Enter menu item name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter menu item price: ";
        cin >> price;
    }
    */

   //private:
   public:
        string name;
        double price;
        int quatity;
    public:
        // add menu item of hotel
        void addMenuItem() 
        {
            MenuItem item;
            cout << "Enter menu item name: ";
            cin.ignore();
            getline(cin, item.name);
            cout << "Enter menu item price: ";
            cin >> item.price;

            ofstream file("menu_items.txt", ios::app);
            if (file.is_open()) 
            {
                file << item.name << "," << item.price << endl;
                file.close();
                cout << "Menu item added successfully!" << endl;
            } 
            else
            {
                cout << "Unable to open file!" << endl;
            }
        }
        // Function to delete menu item of hotel
        void deleteMenuItem() 
        {
            string name;
            cout << "Enter menu item name to delete: ";
            cin.ignore();
            getline(cin, name);

            ifstream file("menu_items.txt");
            ofstream tempFile("temp.txt");
            bool found = false;

            if (file.is_open() && tempFile.is_open())
            {
                string line;
                while (getline(file, line)) 
                {
                    size_t commaPos = line.find(",");
                    string itemName = line.substr(0, commaPos);

                    if (itemName != name) 
                    {
                        tempFile << line << endl;
                    } 
                    else 
                    {
                        found = true;
                    }
                }

                file.close();
                tempFile.close();

                if (found) 
                {
                    remove("menu_items.txt");
                    rename("temp.txt", "menu_items.txt");
                    cout << "Menu item deleted successfully!" << endl;
                } 
                else 
                {
                    cout << "Menu item not found!" << endl;
                }
            } 
            else 
            {
                cout << "Unable to open file!" << endl;
            }
    }
    

    // Function to update menu item of hotel
    void updateMenuItem() 
    {
        string name;
        cout << "Enter menu item name to update: ";
        cin.ignore();
        getline(cin, name);

        ifstream file("menu_items.txt");
        ofstream tempFile("temp.txt");
        bool found = false;

        if (file.is_open() && tempFile.is_open()) 
        {
            string line;
            while (getline(file, line)) 
            {
                size_t commaPos = line.find(",");
                string itemName = line.substr(0, commaPos);

                if (itemName == name) 
                {
                    found = true;
                    cout << "Enter new menu item price: ";
                double price;
                cin >> price;
                tempFile << itemName << "," << price << endl;
                } 
                else 
                {
                    tempFile << line << endl;
                }
            }

            file.close();
            tempFile.close();

            if (found) 
            {
                remove("menu_items.txt");
                rename("temp.txt", "menu_items.txt");
                cout << "Menu item updated successfully!" << endl;
            } 
            else 
            {
                cout << "Menu item not found!" << endl;
            }
        } 
        else
        {
            cout << "Unable to open file!" << endl;
        }
    }

    // Function to view menu items of hotel
    void viewMenuItems()
    {
        ifstream file("menu_items.txt");
        if (file.is_open()) 
        {
            string line;
            while (getline(file, line)) 
            {
                size_t commaPos = line.find(",");
                string name = line.substr(0, commaPos);
                double price = stod(line.substr(commaPos + 1));
                cout << "Name: " << name << ", Price: " << price << endl;
            }
            file.close();
        } 
        else 
        {
            cout << "Unable to open file!" << endl;
        }
    }
};

class Order 
{
    public:
        int orderId;
        string customerName;
        vector<MenuItem> items;
        bool isReady;

    void takeOrder(vector<MenuItem>& menuItems) 
    {
        cout << "Enter order ID: ";
        cin >> orderId;
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, customerName);

        int choice;
        int qty;
        while (true) 
        {
            cout << "Enter menu item number (0 to finish): ";
            cin >> choice;
            
            if (choice == 0) {
                break;
            }
            cout<< "Enter quantity =";
            cin>>qty;
            
            menuItems[choice-1].quatity=qty;
            items.push_back(menuItems[choice - 1]);
        }
    }

    void markAsReady() {
        isReady = true;
    }
};

class Bill {
public:
    int billId;
    
    string customerName;
    double totalAmount;

    void generateBill(Order& order) 
    {
        int qty;
        billId = order.orderId;
        customerName = order.customerName;
        totalAmount = 0;

        for (const auto& item : order.items) 
        {
           
            totalAmount += item.price * item.quatity;
        }
    }

    void saveBillToFile() {
        ofstream file("bills.txt", ios::app);
        if (file.is_open()) {
            file << billId << "," << customerName << "," << totalAmount << endl;
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
    }
};

int hotel_Menu_choice()
{
    int choice;
    cout << "Hotel Menu Management System" << endl;
    cout << "1. Add Menu Item" << endl;
    cout << "2. Delete Menu Item" << endl;
    cout << "3. Update Menu Item" << endl;
    cout << "4. View Menu Items" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main()
 {

    MenuItem item;
    int choice;

    do
    {
       choice= hotel_Menu_choice(); 

        switch (choice) 
        {
            case 1:
                    item.addMenuItem();
                break;
            case 2:
                    item.deleteMenuItem();
                break;
            case 3:
                    item.updateMenuItem();
                break;
            case 4:
                    item.viewMenuItems();
                break;
            case 5:
                    break;
                    //return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;          
         }


   }while (choice!=0);
   

    vector<MenuItem> menuItems;
    vector<Customer> customers;
    vector<Order> orders;
    vector<Bill> bills;

    // Add menu items
   /* int numMenuItems;
    cout << "Enter number of menu items: ";
    cin >> numMenuItems;

    for (int i = 0; i < numMenuItems; i++) {
        MenuItem item;
        item.addMenuItem();
        menuItems.push_back(item);
    }

    */

        ifstream file("menu_items.txt");
        if (file.is_open()) 
        {
            string line;
            while (getline(file, line)) 
            {
                size_t commaPos = line.find(",");
                string name = line.substr(0, commaPos);
                double price = stod(line.substr(commaPos + 1));
                item.name= name;
                item.price=price;
                cout << "Name: " << name << ", Price: " << price << endl;
               menuItems.push_back(item);
            }
            file.close();
        } 

    // Register customer
    Customer customer;
    customer.registerCustomer();
    customers.push_back(customer);

    // Take order
    Order order;
    order.takeOrder(menuItems);
    orders.push_back(order);

    // Mark order as READY
    order.markAsReady();

    // Generate bill
    Bill bill;
    bill.generateBill(order);
    bills.push_back(bill);

    // Save bill to file
    bill.saveBillToFile();

    return 0;
}
