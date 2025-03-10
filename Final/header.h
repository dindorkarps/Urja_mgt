#ifndef USER_H
#define USER_H

#include"header.h"
#include<iostream>
#include<string>
#include <fstream>
#include <vector>


using namespace std;
//---------------------------------------------------------------------
typedef enum menu {  EXIT = 0,MANAGER,RECEPTIONIST,CAPTAIN,CHEF }MENU;

enum managerMenu {	MANAGE_FOOD_MENU=1, MANAGE_BILLING};

enum managerfoodMenu
{ADD_FOOD_MENU=1, VIEW_FOOD_MENU,EDIT_FOOD_MENU,DELETE_FOOD_MENU};
enum managerBilling
{MANAGE_VIEW_BILL_DATE_RANGE=1, MANAGE_VIEW_TODAYS_BILL};

enum receptionistMenu{	REGISTER_CUSTOMER=1, GENERATE_BILL};

enum captaintMenu{CAPTAIN_TAKE_ORDER=1, CAPTAIN_SERVE_ORDER};

enum chefMenu{CHEF_DISPLAY_PENDING_ORDER=1, CHEF_PROCESS_ORDERS};

enum OrderStatus {PENDING=1, READY,SERVED};


//----------------------------------------------------------------
int mainMenu();
int managerMenu();
int managerfoodMenu();

//----------------------------------------------------------------


#include <string>

class User {
protected:
    int id;
    string name;
    string role;

public:
    // Constructor
    User(); 
    User(int id, const std::string& name, const std::string& role);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getRole() const;

    // Setters
    void setId(int id);
    void setName(const std::string& name);
    void setRole(const std::string& role);
    bool validate_user(const std::string &inputUsername, const std::string &inputPassword);
    };

//---------------------------------------------
class Menu
{
    public:
        int id;
        string name;
        int rate;
    public:
        Menu();
        Menu(int id, const std::string& name, int rate);
        int getId() const;
        std::string getName() const;

        void readFoodMenu();
 
        void addFoodMenu();
        void viewFoodMenu();
        void editFoodMenu();
        void deleteFoodMenu();
        void saveToFile();
        void managerMenuHandler();
        int delete_vector(vector<Menu> &myVector);
 
};
//---------------------------------------------
void display_vector(vector<Menu> &myVector);
void edit_vector(vector<Menu> &myVector);
void write_vector_file(vector<Menu> &myVector);
void add_menu_vector(vector<Menu> &myVector);

//----------------------------------------------
//recept related
void recep_MenuHandler();
void genrate_bill();
void calc_bill(int tb);

//--------------------------------------------------


//------------------------------------------------
#endif 