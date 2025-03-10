#include "Display.h"
#include "User.h"
#include "Manager.h"
#include "Reception.h"
#include "Captain.h"

using namespace std;

void Display::firstScreen() {
    system("cls");
    cout << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t******************************************************** \n";
    cout << "\t\t\t\t\t\t Welcome to Rahul Restaurant \n";
    cout << "\t\t\t\t******************************************************** \n";
    cout << "\n\n\n\t\t\t\t\t\tPress any key to continue\n";
    getch(); 
    system("cls");
}

void Display::secondScreen() {
    cout << "Select User \n";
    cout << "1. Manager \n";
    cout << "2. Reception \n";
    cout << "3. Captain \n";
    cout << "4. Chef \n";  
    cout << "5. Exit \n";
}

void Display::printStar(int n) {
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << "\n";
}

void Display::welcome() {
    char choice;
    printStar(20);
    secondScreen();
    printStar(20);

    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case '1':{
        system("cls");
        printf("\t\t\tWelcome Rahul\n");
        ManagerSubclass msc;
        msc.managerMain(1);
        }
            break;


        case '2':{
            system("cls");
            Reception rec;
            rec.receptionPage();
      }
            break;


        case '3':{
        system("cls");
        Captain cp;
        cp.CaptainPage();
        }
            break;


        case '4':
            system("cls");
            cout << "\n\nEntering Chef section...\n";
            break;

            
        case '5':
            cout << "\n\nThank you for visiting. Have a nice day!\n\n";
            exit(0);
            break;
        default:
            cout << "Invalid choice!\n";
            cout << "Press any key to continue...\n";
            getch();
            system("cls");
            welcome();
    }
}
