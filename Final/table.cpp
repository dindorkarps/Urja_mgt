#include "table.h"
#include "header.h"

Table All_Table[5];

Table :: Table()
{
    table_no = 0;
    table_status = 0;
    order_taken = 0;
    table_order_status = 0;
    table_bill_paid = 0;
    total_bill = 0;
    served=0;
}
Order :: Order()
{
    menu_id=0;
    dish_name="";
    order_qty=0;
    rate=0;
}
        

Customer::Customer()
{
    dd = 0;
    mm = 0;
    yy = 2025;
    cus_ID = 0;
    name = "";
    table_no=0;
}
void Customer:: accept_cust()
{
    cout << "Enter Date DD:MM:YY :";
    cin >> dd;
    cin >> mm;
    cin >> yy;
    cout << "Enter Customer ID: ";
    cin >> cus_ID;
    cin.ignore(); // Ignore the newline character left in the buffer
    cout << "Enter Customer Name: ";
    getline(cin, name);   
}

void initialise_table()
{
    int i;
    for(i=0 ; i<=5; i++)
    {
        All_Table[i].table_no= i+1;
        All_Table[i].order_taken=0;
        All_Table[i].table_status=0;
        All_Table[i].table_order_status=0;
    }
}