
#include <cstdlib>
#include <fstream> // For file handling
#include <cstring>
#include <conio.h> // Needed for getch()


#include "Display.h"
#include "Manager.h"
#include "User.h"
#include "FoodItem.h"

void ManagerSubclass::managerPage() {
    
    char choice;
    User u;
    FoodItem f;
    char id[20];

    printStar(90);
    std::cout << "\t\t\t...MANAGE STAFF...\n";
    printStar(90);
    std::cout << "1. Add staff to the database \n";
    std::cout << "2. Show staff data \n";
    std::cout << "3. Delete staff data \n";
    
    printStar(90);
    cout<<"\n\n\n\n";
    std::cout << "\t\t\t...MANAGE FOOD ITEM...\n";
    printStar(90);
    std::cout << "4. Add Menu \n";
    std::cout << "5. Show Menu \n";
    std::cout << "6. Edit Menu \n";
    std::cout << "7. Delete Menu \n";
    printStar(90);
    cout<<"\n\n\n\n";
    std::cout << "\t\t\t...MANAGE BILLING...\n";
    printStar(90);
    std::cout << "8. View bill between range \n";
    std::cout << "9. View total bill todays  \n";
    
    std::cout << "0. Go to previous page \n";
    printStar(90);

    std::cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case '1':
            addStaff(u);
            managerPage();
            break;
        case '2':
            showStaff(u);
            break;
        case '3':
            std::cout << "Enter User ID to be deleted: ";
            cin >> id;
            deleteStaff(u, id);
            break;
        case '4':
            f.addFoodItem();
            break;
        case '5':
            system("cls");
            f.displayAllFoodItems();
            break;
        case '6':
            f.updateFoodItem();
            break;
        case '7':
            f.deleteFoodItem();
            break;
        case '0':
            welcome();
            break;
        default:
            std::cout << "Invalid option! \nPress any key to continue...\n";
            getch();
            managerPage();
    }
}

void ManagerSubclass::managerMain(int i) {
    if (isValidateManager()) {
        std::cout << "\nLogin Successful!\nPress any key to continue...\n";
        getch();
        system("cls");
        managerPage();
    } else {
        std::cout << "\nInvalid ID or Password. You have " << 3 - i << " attempt(s) left.\n";
        getch();
        if (i < 3) {
            managerMain(i + 1);
        } else {
            std::cout << "\nToo many failed attempts. Try again later.\n";
            exit(0);
        }
    }
}

void ManagerSubclass::addStaff(User& u) {
    FILE *fp = fopen("UserFile.txt", "a");
    if (!fp) {
        cout << "File cannot be opened!\nPress any key to continue\n";
        getch();
        system("cls");
        managerPage();
    } else {
        cout << "\nEnter User ID: ";
        cin >> u.uid;
        cout << "Enter Password: ";
        cin >> u.password;
        cout << "Enter Role: ";
        cin >> u.role;

        fwrite(&u, sizeof(User), 1, fp);
        fclose(fp);
        
        cout << "\nUser added successfully!\nPress any key to continue...\n";
        getch();
        system("cls");
        managerPage();
    }
}

void ManagerSubclass::showStaff(User& u) {
    FILE *fp = fopen("UserFile.txt", "rb");
    if (!fp) {
        cout << "File not found!\nPress any key to continue\n";
        getch();
        return;
    }

    cout << "User ID\t\tPassword\tRole\t\t\n";
    while (fread(&u, sizeof(User), 1, fp) == 1) { // Fixed fread condition
        cout << u.uid << "\t\t" << u.password <<"\t\t"<< u.role<<"\n";
    }
    fclose(fp);

    cout << "\nPress any key to continue...\n";
    getch();
    system("cls");
    managerPage();
}

void ManagerSubclass::deleteStaff(User& u, char* userid) {
    FILE *fp = fopen("UserFile.txt", "rb");
    FILE *ftemp = fopen("temp.txt", "wb");
    if (!fp || !ftemp) {
        cout << "File cannot be opened!\nPress any key to continue\n";
        getch();
        system("cls");
        managerPage();
    }

    int found = 0;
    while (fread(&u, sizeof(User), 1, fp) == 1) {
        if (strcmp(userid, u.uid) == 0) {
            cout << "\nStaff record deleted.\n";
            found = 1;
        } else {
            fwrite(&u, sizeof(User), 1, ftemp);
        }
    }
    
    fclose(fp);
    fclose(ftemp);
    
    if (!found) {
        cout << "\nNo record found for User ID: " << userid;
    } else {
        remove("UserFile.txt");
        rename("temp.txt", "UserFile.txt");
    }

    cout << "\nPress any key to continue...\n";
    getch();
    system("cls");
    managerPage();
}

bool Manager::isValidateManager() {
    cout << "Enter User ID: ";
    cin >> userId;

    cout << "Enter Password: ";
    int p = 0;
    do {
        userPass[p] = getch();
        if (userPass[p] != '\r') {
            cout << "*";
        }
        p++;
    } while (userPass[p - 1] != '\r');
    userPass[p - 1] = '\0';

     return strcmp(userId, "rahul") == 0 && strcmp(userPass, "rangari") == 0;
    return true;
}

bool Manager::isValidateUser() {
    FILE *fp = fopen("UserFile.txt", "r");
    if (!fp) return false; // Prevent segmentation fault

    User u;
    cout << "Enter User ID: ";
    cin >> userId;

    cout << "Enter Password: ";
    int p = 0;
    do {
        userPass[p] = getch();
        if (userPass[p] != '\r') {
            cout << "*";
        }
        p++;
    } while (userPass[p - 1] != '\r');
    userPass[p - 1] = '\0';

    while (fread(&u, sizeof(User), 1, fp) == 1) {
        if (strcmp(userId, u.getuid()) == 0 && strcmp(userPass, u.getpassword()) == 0) {
            fclose(fp);
            return true;
        }
    }
    
    fclose(fp);
    return false;
}

