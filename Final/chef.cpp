#include "header.h"
#include "table.h"


extern Table All_Table[5];
extern vector <Customer> All_cust;

void chef_MenuHandler()
{
    int ch;
    do
    {
        cout << "0.Exit\n1.See All Pending Orders::\n2. Prepare Order::\n";
        cout << "Your Choice : ";
        cin >> ch;
        switch (ch)
        {
            case CHEF_DISPLAY_PENDING_ORDER:
                            cout << "Check Order" << endl;
                            show_pending_orders();
                break;
                
            case CHEF_PROCESS_ORDERS:
                            cout << "Process-Cook Order" << endl;
                            process_order();

                            break;

            default:
                cout << "Invalid Option..." << endl;
                break;
            }
    } while (ch != 0);

}


void process_order()
{
    int i;
    for (i = 0; i < 5; i++)
    {   
        if (All_Table[i].table_status == 1)
        {
            if (All_Table[i].order_taken == 1)
            {
                if(All_Table[i].table_order_status == 0)
                {
                    cout << "Table " << i + 1 << " Order is Pending " << endl;
                    int ch;
                    for (int j = 0; j < All_Table[i].Table_order.size(); j++)
                    {
                        cout << "Food ID: " << All_Table[i].Table_order[j].menu_id <<"  Item : " <<All_Table[i].Table_order[j].dish_name << " Quantity: " << All_Table[i].Table_order[j].order_qty << endl;
                    }
                    cout << "Order is Raedy for table " << i + 1 << " ? (1-Y/0-N): ";
                    cin >> ch;
                    if (ch == 1)
                    {
                        All_Table[i].table_order_status = 1;
                        cout << "Order is Ready for table " << i + 1 << endl;
                    }
                    else
                    {
                        cout << "Order is not Ready for table " << i + 1 << endl;
                    }
                }
            }
        }
    } 
}

void show_pending_orders()
{
    int i;
    for (i = 0; i < 5; i++)
    {   
        if (All_Table[i].table_status == 1)
        {
            if (All_Table[i].order_taken == 1)
            {
                if(All_Table[i].table_order_status == 0)
                {
                    cout << "Table " << i + 1 << " Order is Pending " << endl;
                    for (int j = 0; j < All_Table[i].Table_order.size(); j++)
                    {
                        cout << "Food ID: " << All_Table[i].Table_order[j].menu_id <<"  Item : " <<All_Table[i].Table_order[j].dish_name << " Quantity: " << All_Table[i].Table_order[j].order_qty << endl;
                    }
                }
            }
        }
    } 
}