#ifndef TABLE_H
#define TABLE_H

#include "header.h"
//------------------------------------------
class Order
{
    public:
        int menu_id;
        string dish_name;
        int order_qty;
        int rate;

    public:
        Order();
};
//-----------------------------------------
// class Bill
// {
//     protected:  
//         int dd,mm,yy;
//         vector <Order> T_Bill_order;
//         int bill_table_no;
//         int bill_total;
// };  
//-------------------------------------------
//--------------------------------------------
class Table
{
    public:
        int table_no; //Hotel

        int table_status;//table Busy/Not ->recep
        int order_taken;//Order taken or not ->captain
        int table_order_status;//Table order Ready/Not -> chef

        vector <Order> Table_order;// order list with qty

        int served; //order is served
        int table_bill_paid; //Bill paid not
        int total_bill;
    public:
        Table();
};
void initialise_table();
//-------------------------------------------

class Customer
{
    public:
        int dd,mm,yy;
        int cus_ID;
        string name;
        int table_no; //Bill or Customer info
        Table t1;
    public:
        Customer();
        void accept_cust();

};
void register_customer();
bool check_Table_Avail();

//--------------------------------------------

void captain_MenuHandler();
void take_order();
void check_oder_not_taken_table();
void take_food_order(int table_no);

void display_menu_vector(vector<Order> &myVector);
void display_table_order();
void add_menu_vector( vector<Order> &myVector);

void serve_order();
//--------------------------------------------

void chef_MenuHandler();
void show_pending_orders();
void process_order();
void show_all_cust_();
void generate_bill();
void write_All_Cust_vector_file(Customer);
//----------------------------------------------
#endif // USER_H