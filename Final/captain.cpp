#include "header.h"
#include "table.h"

extern Table All_Table[5];
extern vector <Customer> All_cust;

void captain_MenuHandler()
{
    int ch;
    do
    {
        cout << "0.Exit\n1. Take Order:\n2. Serve Order:\n";
        cout << "Your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case CAPTAIN_TAKE_ORDER:
            cout << "Take Order" << endl;
            take_order();
            cout<< "Do you want to check order of table? (1-Y/0-N): ";
            cin>>ch;
            if (ch == 1)
            {
                display_table_order();
            }
            break;

        case CAPTAIN_SERVE_ORDER:
            cout << "Serve Order" << endl;
            serve_order();
            break;

        default:
            cout << "Invalid Option..." << endl;
            break;
        }
    } while (ch != 0);
}
void serve_order()
{
    //check_reaady_order;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (All_Table[i].table_order_status == 1)
        {
            if (All_Table[i].served == 0)
            {
                cout << "Table " << i + 1 << " Order Is Ready Serve " << endl;
                All_Table[i].served = 1;
                cout << "Table " << i + 1 << " Order Is Ready Served...\nEnjoy Testy Food.. " << endl;
            }
        }
    }
}

//----------------------------------------------
void take_order()
{
    check_oder_not_taken_table();

    int ch;
    cout << "Enter Table Number: ";
    cin >> ch;
    if(All_Table[ch - 1].order_taken == 1)
    {
        cout << "Order already taken" << endl;
        return;
    }
    else
    {
        All_Table[ch - 1].order_taken = 1;
        take_food_order(ch);
        cout << "Order Taken" << endl;
    }
}

void take_food_order(int table_no)
{
    if (table_no < 1 || table_no > 5)
    {
        cout << "Invalid table number." << endl;
        return;
    }
    vector<Order> order_list;
    add_menu_vector(order_list);
    display_menu_vector(order_list);

    Order o1;
    int ch;
    do
    {
        cout<<"Enter the food id : ";
        cin>>o1.menu_id;
        for(int i=0; i<order_list.size(); i++)
        {
            if(o1.menu_id == order_list[i].menu_id)
            {
                o1.dish_name = order_list[i].dish_name;
                o1.rate = order_list[i].rate;
                break;
            }
        }
        cout<<"Enter the quantity: ";
        cin>>o1.order_qty;
        All_Table[table_no - 1].order_taken=1;
        All_Table[table_no - 1].Table_order.push_back(o1);
        cout<<"Do you want to add more items? (1-Y/0-N): ";
        cin>>ch;
    } while (ch == 1);
    cout<<"Order taken successfully"<<endl;
}


void display_menu_vector(vector<Order> &myVector)
{
    cout << "Food Menu:\n";
    for (int i = 0; i < myVector.size(); i++)
    {
        cout << "ID:  " << myVector[i].menu_id << " , Name:  " << myVector[i].dish_name << " , Rate: " << myVector[i].rate << "\n";
    }
}
void add_menu_vector( vector<Order> &myVector)
{
    Order o1;
    ifstream file("FoodMenu.txt");
    if (!file)
    {
        cout << "File cannot be opened! \n";
        return;
    }
    else
    {
        cout << "Food Menu:\n";
        while (file >> o1.menu_id >> o1.dish_name >> o1.rate )
        {
            myVector.push_back(o1);
        }
    }
    file.close();
}

void display_table_order()
{
    int table_no,i;
    cout<<"Enter the table number To check Order : ";
    cin>>table_no;
    
    if( table_no < 1 || table_no > 5)
    {
        cout<<"Invalid table number."<<endl;
        return;
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            if(All_Table[i].table_no == table_no)
            {
                if (All_Table[i].table_status == 1)
                {
                    if (All_Table[i].order_taken == 1)
                    {
                        cout << "Table " << i + 1 << " Order: " << endl;
                        for (int j = 0; j < All_Table[i].Table_order.size(); j++)
                        {
                            cout << "Food ID: " << All_Table[i].Table_order[j].menu_id <<"  Item : " <<All_Table[i].Table_order[j].dish_name << " Quantity: " << All_Table[i].Table_order[j].order_qty << endl;
                        }
                    }
                }
            }
        }
    }
}

void check_oder_not_taken_table()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if( All_Table[i].table_status == 1)
        {
            if (All_Table[i].order_taken == 0)
            {
                cout << "Table " << i + 1 << " is not taken" << endl;
            }
        }
    }
}