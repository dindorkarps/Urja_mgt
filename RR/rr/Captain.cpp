#include "Captain.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>  // For getch()
#include <cstdlib>  // For system("cls")

using namespace std;

void Captain::CaptainPage() {
    system("cls");
    FoodItem fi;
    Display d;
    char choice;
    int tableno;

     // Keeps the menu active
        system("cls");
        d.printStar(90);
        cout << "CAPTAIN MENU\n";
        cout << "1. View Menu \n";
        cout << "2. Order Food \n";
        cout << "3. Serve Food\n";
        cout << "4. Go to previous menu \n";
        d.printStar(90);

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                fi.displayAllFoodItems();
                cout << "\nPress any key to continue...\n\n";
                getch();
                break;
            case '2':
                cout << "Enter table number: ";
                cin >> tableno;
                orderFood(tableno);
                break;
            case '3':
                serveFood();
                break;
            case '4':
                d.welcome(); // Exit the function properly
            default:
                cout << "Enter a valid option!\nPress any key to continue...\n";
                getch();
        }
    }


// Function to order food
void Captain::orderFood(int tableNo) {
    char ch;
    FoodItem m;
    int orderListId[5] = {0};  // Assuming a max of 5 food items per order
    int itemCount = 0;

    cout << "\n\nToday's Menu\n\n";
    m.displayAllFoodItems(); // Assuming FoodItem class has this function

    do {
        if (itemCount >= 5) {
            cout << "Maximum 5 items per order!\n";
            break;
        }

        cout << "\nEnter the food id to order: ";
        cin >> orderListId[itemCount];
        itemCount++;

        cout << "Do you want to add another item? [Y/N]: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    // File handling for orderList.txt
    ofstream file("orderList.txt", ios::app);
    if (!file) {
        cout << "File cannot be opened!\n";
        return;
    }

    file << tableNo << " ";  // Store table number
    for (int i = 0; i < itemCount; i++) {
        file << orderListId[i] << " ";
    }
    file << endl;

    file.close();
    cout << "Order placed successfully!\nPress any key to continue...\n";
    getch();
}

// Function to serve food
void Captain::serveFood() {
    ifstream file("orderList.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cout << "Error: Could not open order file!\n";
        return;
    }

    int tableNo;
    cout << "Enter table number to serve: ";
    cin >> tableNo;

    string line;
    bool orderFound = false;

    while (getline(file, line)) {
        istringstream ss(line);
        int storedTableNo;
        ss >> storedTableNo;

        if (storedTableNo == tableNo) {
            cout << "Serving food to Table " << tableNo << "\n";
            orderFound = true;
        } else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    if (!orderFound) {
        cout << "No orders found for Table " << tableNo << "!\n";
        remove("temp.txt");
    } else {
        remove("orderList.txt");
        rename("temp.txt", "orderList.txt");
        cout << "Order served successfully!\n";
    }
    getch();
}
