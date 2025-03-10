#include <iostream>
#include <fstream>
#include "Reception.h"
#include "Customer.h"
#include "FoodItem.h"
#include "Display.h"


Display d;
using namespace std;

Reception::Reception() : tables(MAX_TABLES, false) {  
    std::ifstream file("orderList.txt", std::ios::binary);
    Customer temp;
    
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Customer))) {
        if (temp.tableNumber >= 1 && temp.tableNumber <= MAX_TABLES) {
            tables[temp.tableNumber - 1] = true;  // Mark occupied tables
        }
    }
}

void Reception::receptionPage() {
    system("cls");  
    FoodItem f;
    char choice;
    int tableno;

do
{
 

    cout << "********** RECEPTION MENU **********\n";
    cout << "1. Add Customer \n";
    cout << "2. Assign Table \n";
    cout << "3. Show Bill \n";
    cout << "4. Pay Bill and Checkout \n";
    cout << "5. Exit \n";
    cout << "************************************\n";
    cout << "Enter your choice: ";
    cin >> choice;
   
    switch (choice) {
        case '1':
            addCustomer();
            
            break;
        case '2':
            assignTable();
            receptionPage();
            break;
        case '3':
            cout << "Enter table number: ";
            cin >> tableno;
            if (!isTableAvailable(tableno)) {
                cout << "Table Not Occupied! No Bill Record!\n";
                break;
            }
            showBill(tableno);
            break;
        case '4':
            cout << "Enter table number: ";
            cin >> tableno;
            if (!isTableAvailable(tableno)) {
                cout << "Table Not Occupied! No Bill Record!\n";
                break;
            }
            checkOut(tableno);
            d.secondScreen();
            break;
        case '5':
            cout << "Exiting Reception...\n";
            d.firstScreen();
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}while (choice==true);
}
void Reception::addCustomer() {
    Customer c;
    FILE *fp = fopen("UserFile.txt", "ab");  // Open file in append mode
    if (!fp) {
        cout << "Error: File cannot be opened!\n";
        return;
    }

    cout << "Enter Customer Name: ";
    cin >> c.customerName;
    cout << "Enter Table Number: ";
    cin >> c.tableNumber;

    fwrite(&c, sizeof(Customer), 1, fp);
    fclose(fp);

    cout << "Customer added successfully!\n";
    
}

bool Reception::isTableAvailable(int tableNo) {
    return tables[tableNo - 1];  // Returns true if table is occupied
}

int Reception::showBill(int tableNo) {
    Customer c;
    FILE *fp = fopen("orderList.txt", "rb");
    if (!fp) {
        cout << "Error: Cannot open order list file!\n";
        return -1;
    }

    float totalCost = 0, gst = 0, bill = 0;
    bool found = false;

    while (fread(&c, sizeof(Customer), 1, fp)) {
        if (c.tableNumber == tableNo) {
            found = true;
            cout << "\nCustomer Name: " << c.customerName;
            cout << "\nTable Number: " << tableNo << "\n";
            cout << "\n********** BILL DETAILS **********\n";
            cout << "Item Name\t\tPrice (Rs.)\n";
            cout << "---------------------------------\n";

            for (int i = 0; i < 10 && c.orderListId[i] != 0; i++) {
                FoodItem m;
                FILE *fp1 = fopen("FoodMenu.txt", "rb");
                if (!fp1) {
                    cout << "Error: Cannot open menu file!\n";
                    fclose(fp);
                    return -1;
                }

                while (fread(&m, sizeof(FoodItem), 1, fp1)) {
                    if (c.orderListId[i] == m.id) {
                        cout << m.name << "\t\t" << m.price << " Rs.\n";
                        totalCost += m.price;
                    }
                }
                fclose(fp1);
            }

            gst = totalCost * 0.18;
            bill = totalCost + gst;
            cout << "Order Total: " << totalCost << " Rs.\n";
            cout << "GST (18%): " << gst << " Rs.\n";
            cout << "Final Bill: " << bill << " Rs.\n";
        }
    }
    fclose(fp);

    if (!found) {
        cout << "No bill found for Table " << tableNo << ".\n";
        return -1;
    }
    return bill;
}

void Reception::assignTable() {
    int tableNum;
    std::cout << "Enter table number to assign (1-" << MAX_TABLES << "): ";
    std::cin >> tableNum;

    if (tableNum < 1 || tableNum > MAX_TABLES) {
        std::cout << "Invalid table number! Please enter a valid number.\n";
        return;
    }

    if (tables[tableNum - 1]) {
        std::cout << "Table " << tableNum << " is already occupied!\n";
    } else {
        tables[tableNum - 1] = true;  // Mark table as occupied
        std::cout << "Table " << tableNum << " has been assigned successfully.\n";
    }
}



void Reception::checkOut(int tableNo) {
    FILE *fp = fopen("orderList.txt", "rb");
    if (!fp) {
        cout << "Error: Cannot open order list file!\n";
        return;
    }

    FILE *ftemp = fopen("templist.txt", "wb");
    if (!ftemp) {
        cout << "Error: Cannot create temporary file!\n";
        fclose(fp);
        return;
    }

    Customer c;
    bool found = false;
    float bill = showBill(tableNo);
    float billPaid = 0, change = 0;

    while (fread(&c, sizeof(Customer), 1, fp)) {
        if (c.tableNumber == tableNo) {
            found = true;
            do {
                cout << "\nTotal amount due: Rs. " << bill;
                cout << "\nEnter amount paid: ";
                cin >> billPaid;

                if (billPaid > bill) {
                    change = billPaid - bill;
                    cout << "\nPayment received. Change: Rs. " << change;
                } else if (billPaid < bill) {
                    change = bill - billPaid;
                    cout << "\nPartial payment received. Please pay Rs. " << change << " more.";
                    bill = change;
                } else {
                    cout << "\nFull payment received. Thank you!";
                }
            } while (billPaid != bill);
        } else {
            fwrite(&c, sizeof(Customer), 1, ftemp);
        }
    }

    fclose(fp);
    fclose(ftemp);

    if (!found) {
        cout << "Error: No customer found at Table " << tableNo << "!\n";
        remove("templist.txt");
    } else {
        remove("orderList.txt");
        rename("templist.txt", "orderList.txt");
        cout << "\nThank you for visiting!\n";
    }
}


// #include <iostream>
// #include <fstream>
// #include "Reception.h"
// #include "Customer.h"
// #include "FoodItem.h"
// #include "Display.h"

// using namespace std;

// Display d;

// // Constructor to initialize table availability from file
// Reception::Reception() : tables(MAX_TABLES, false) {
//     ifstream file("orderList.txt", ios::binary);
//     if (!file) {
//         cout << "Warning: Order list file not found. Assuming all tables are free.\n";
//         return;
//     }

//     Customer temp;
//     while (file.read(reinterpret_cast<char*>(&temp), sizeof(Customer))) {
//         if (temp.tableNumber >= 1 && temp.tableNumber <= MAX_TABLES) {
//             tables[temp.tableNumber - 1] = true;  // Mark occupied tables
//         }
//     }
//     file.close();
// }

// void Reception::receptionPage() {
//     system("cls");  
//     int choice;
//     int tableno;
    
//     do
//     {
//         cout << "********** RECEPTION MENU **********\n";
//         cout << "1. Add Customer \n";
//         cout << "2. Assign Table \n";
//         cout << "3. Show Bill \n";
//         cout << "4. Pay Bill and Checkout \n";
//         cout << "5. Back to privious page \n";
//         cout << "************************************\n";
        
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 addCustomer();
//                 break;
//             case 2:
//                 assignTable();
//                 break;
//             case 3:
//                 cout << "Enter table number: ";
//                 cin >> tableno;
//                 if (!isTableAvailable(tableno)) {
//                     cout << "Table Not Occupied! No Bill Record!\n";
//                     break;
//                 }
//                 showBill(tableno);
//                 break;
//             case 4:
//                 cout << "Enter table number: ";
//                 cin >> tableno;
//                 if (!isTableAvailable(tableno)) {
//                     cout << "Table Not Occupied! No Bill Record!\n";
//                     break;
//                 }
//                 checkOut(tableno);
//                 d.secondScreen();
//                 break;
//             case 5:
//                 cout << "Exiting Reception...\n";
//                 return;
                
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//         }
       
//         }while (true);
//     }   
        
       
        

// void Reception::addCustomer() {
//     Customer c;
//     FILE *fp = fopen("UserFile.txt", "ab");
//     if (!fp) {
//         cout << "Error: File cannot be opened!\n";
//         return;
//     }

//     cout << "Enter Customer Name: ";
//     cin >> c.customerName;
//     cout << "Enter Table Number: ";
//     cin >> c.tableNumber;

//     fwrite(&c, sizeof(Customer), 1, fp);
//     fclose(fp);
//     cout << "Customer added successfully!\n";
// }

// bool Reception::isTableAvailable(int tableNo) {
//     return !tables[tableNo - 1];
// }

// int Reception::showBill(int tableNo) {
//     Customer c;
//     FILE *fp = fopen("orderList.txt", "rb");
//     if (!fp) {
//         cout << "Error: Cannot open order list file!\n";
//         return -1;
//     }

//     float totalCost = 0, gst = 0, bill = 0;
//     bool found = false;

//     while (fread(&c, sizeof(Customer), 1, fp)) {
//         if (c.tableNumber == tableNo) {
//             found = true;
//             cout << "\nCustomer Name: " << c.customerName;
//             cout << "\nTable Number: " << tableNo << "\n";
//             cout << "\n********** BILL DETAILS **********\n";
//             cout << "Item Name\t\tPrice (Rs.)\n";
//             cout << "---------------------------------\n";

//             for (int i = 0; i < 10 && c.orderListId[i] != 0; i++) {
//                 FoodItem m;
//                 FILE *fp1 = fopen("FoodMenu.txt", "rb");
//                 if (!fp1) {
//                     cout << "Error: Cannot open menu file!\n";
//                     fclose(fp);
//                     return -1;
//                 }
//                 while (fread(&m, sizeof(FoodItem), 1, fp1)) {
//                     if (c.orderListId[i] == m.id) {
//                         cout << m.name << "\t\t" << m.price << " Rs.\n";
//                         totalCost += m.price;
//                     }
//                 }
//                 fclose(fp1);
//             }

//             gst = totalCost * 0.18;
//             bill = totalCost + gst;
//             cout << "Order Total: " << totalCost << " Rs.\n";
//             cout << "GST (18%): " << gst << " Rs.\n";
//             cout << "Final Bill: " << bill << " Rs.\n";
//         }
//     }
//     fclose(fp);
//     if (!found) {
//         cout << "No bill found for Table " << tableNo << ".\n";
//         return -1;
//     }
//     return bill;
// }

// void Reception::assignTable() {
//     int tableNum;
//     cout << "Enter table number to assign (1-" << MAX_TABLES << "): ";
//     cin >> tableNum;
//     if (tableNum < 1 || tableNum > MAX_TABLES) {
//         cout << "Invalid table number!\n";
//         return;
//     }
//     if (tables[tableNum - 1]) {
//         cout << "Table " << tableNum << " is already occupied!\n";
//     } else {
//         tables[tableNum - 1] = true;
//         cout << "Table " << tableNum << " has been assigned successfully.\n";
//     }
// }

// void Reception::checkOut(int tableNo) {
//     tables[tableNo - 1] = false;
//     cout << "\nThank you for visiting!\n";
// }
