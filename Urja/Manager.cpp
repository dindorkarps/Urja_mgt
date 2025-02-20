#include ".\headers\Manager.h"
#include ".\headers\EnumMenuFunction.h"
#include ".\headers\Enums.h"
#include"./headers/dishItem.h"
#include <iostream>
const char* db_file = "MenuCard.dat";

Manager::Manager() {}
// Constructor
Manager::Manager(int id, const std::string& name, const std::string& role) 
    : User(id, name, role) {}

// Method to display manager information
void Manager::displayInfo() const {
    std::cout << "Manager ID: " << id << ", Name: " << name << ", Role: " << role << std::endl;
}


void Manager::managerMenuHandler()
{
    int ch;
    while ((ch = managerMenu()) != 0)
    {
        switch (ch)
        {
        case MANAGE_FOOD_MENU:
            while ((ch = managerfoodMenu()) != 0)
            {
                switch (ch)
                {
                case ADD_FOOD_MENU:
                        addFoodMenu();
                break;
                case VIEW_FOOD_MENU:
                        viewFoodMenu();
                break;
                case EDIT_FOOD_MENU:
                        //editFoodMenu();
                break;
                case DELETE_FOOD_MENU:
                    //deleteFoodMenu();
                    break;
                }
            }
        case MANAGE_BILLING:
            while ((ch = managerBilling()) != 0)
            {
                switch (ch)
                {
                case MANAGE_VIEW_BILL_DATE_RANGE:
                        //viewBillDateRange();
                break;
                case MANAGE_VIEW_TODAYS_BILL:
                        //viewTodaysBill();
                break;
                }  
            }  
        }
    }
}

void Manager::addFoodMenu() ////write file
{
    dishItem item;
    std::cin >> item;
    ofstream fout;
	fout.open(db_file, ios::binary | ios::out | ios::app);
	if (!fout)
	{
		cout << "Database file cannot be opened." << endl;
		return;
	}
    item.saveinFile(fout);
    fout.flush();
	fout.close();
}
void Manager::viewFoodMenu() //read file
{
    ifstream fin;
    fin.open(db_file, ios::binary | ios::in);
    if (!fin)
    {
        cout << "Database file cannot be opened." << endl;
        return;
    }
    dishItem item;
    while (!fin.eof())
    {
        item.loadFromFrole(fin);
        cout << item;
    }
    fin.close();
}
void Manager::editFoodMenu()
{

}
void Manager::deleteFoodMenu()
{

}
void Manager::viewBillDateRange()
{

}
void Manager::viewTodaysBill()
{

}