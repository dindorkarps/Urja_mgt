#include "table.h"
#include "header.h"

extern Table All_Table[5];
vector<Customer> All_cust;

void recep_MenuHandler()
{
    cout << "Welcome To Reception " << endl;
    int ch;
    do
    {
        cout << "0.Exit\n1.Register Customer \n2.Generate Bill " << endl;
        cout << "Your Choice : ";
        cin >> ch;
        switch (ch)
        {
            case REGISTER_CUSTOMER:
                cout << "Register_Customer" << endl;
                register_customer();
                break;
            case GENERATE_BILL:
                cout << "Generate Bill" << endl;
                show_all_cust_();
                generate_bill();
               
                break;
            default:
                cout << "Invalid Option..." << endl;
                break;
        }
    } while (ch != 0);
}

void show_all_cust_()
{
    if (All_cust.empty())
    {
        cout << "No customers registered." << endl;
        return;
    }
    //---------------------------------------------
    cout<<"------------------------------------------------\n";
    for (int j = 0; j < All_cust.size(); ++j)
    {
        if (  All_cust[j].table_no ==  All_Table[ All_Table[j].table_no-1].table_no )
        {
            All_cust[j].t1 =  All_Table[ All_Table[j].table_no-1] ;
            // cout<<"Copied...\n";

            // cout << "Customer ID: " << All_cust[j].cus_ID << endl;
            // cout << "Name: " << All_cust[j].name << endl;
            // cout << "Date: " << All_cust[j].dd << "/" << All_cust[j].mm << "/" << All_cust[j].yy << endl;
            // cout << "Table No: " << All_cust[j].t1.table_no  << endl; // Adding 1 to match table number display
            // cout << "Order Taken: " << All_cust[j].t1.order_taken << endl;
            // cout << "Order Status: " << All_cust[j].t1.table_order_status << endl;
            // cout << "Order Served: " << All_cust[j].t1.served << endl;
            // cout << "Order Total Bill: " << All_cust[j].t1.total_bill << endl;
            // cout << "Order Table Paid: " << All_cust[j].t1.table_bill_paid << endl;
            // cout << "-----------------------------" << endl;
        }
    }
    cout<<"------------------------------------------------\n";
    //---------------------------------------------
    for(int i=0 ; i < 5 ; i++)
    {
        if (All_Table[i].served == 1)
        {
            // cout << "Table No: " << All_Table[i].table_no << endl;
            // cout << "Order Taken: " << All_Table[i].order_taken << endl;
            // cout << "Order Status: " << All_Table[i].table_order_status << endl;
            // cout << "Order Served: " << All_Table[i].served << endl;
            // cout << "Total Bill: " << All_Table[i].total_bill << endl;
            // cout << "Table Bill Paid: " << All_Table[i].table_bill_paid << endl;
            // cout << "-----------------------------" << endl;
        }
    }
    cout<<"------------------------------------------------\n";
   //------------------------------------------------
    for (const auto& customer : All_cust)
    {
        // cout << "Customer ID: " << customer.cus_ID << endl;
        // cout << "Name: " << customer.name << endl;
        // cout << "Date: " << customer.dd << "/" << customer.mm << "/" << customer.yy << endl;
        // cout << "Table No: " << customer.t1.table_no << endl; // 
        // cout << "Order Taken: " << customer.t1.order_taken << endl;
        // cout << "Order Status: " << customer.t1.table_order_status << endl;
        // for (int j = 0; j < customer.t1.Table_order.size(); j++)
        //         {
        //             cout << "Id : " << customer.t1.Table_order[j].menu_id << " ";
        //             cout << "Item : " << customer.t1.Table_order[j].dish_name << " ";
        //             cout << "Qty : " << customer.t1.Table_order[j].order_qty << " ";
        //             cout << "Rate : " << customer.t1.Table_order[j].rate << "\n";

        //             //customer.t1.total_bill = customer.t1.total_bill + (customer.t1.Table_order[j].order_qty * customer.t1.Table_order[j].rate);
        //             //All_cust[i].t1.total_bill = All_cust[i].t1.total_bill + (All_cust[i].t1.Table_order[j].order_qty * All_cust[i].t1.Table_order[j].rate);
        //         }
        // cout << "Order Served: " << customer.t1.served << endl;
        // cout << "Order Total Bill: " << customer.t1.total_bill << endl;
        // cout << "Order Table Paid: " << customer.t1.table_bill_paid << endl;
        // cout << "-----------------------------" << endl;
    }
    cout<<"------------------------------------------------\n";
}

void generate_bill()
{

    int tb, flag = 0;
    cout << "Enter Table No: ";
    cin >> tb;
    for (int i = 0; i < All_cust.size(); i++)
    {
        cout << "Here-1 \n";
        if (All_cust[i].table_no == tb)
        {
            cout << "Here-2 \n";
            if (All_cust[i].t1.total_bill == 0)
            {
                cout << "Here-3 \n";
                flag = 1;
                //--------------------------------------------
                for (int j = 0; j < All_cust[i].t1.Table_order.size(); j++)
                {
                    cout << "Id : " << All_cust[i].t1.Table_order[j].menu_id << " ";
                    cout << "Item : " << All_cust[i].t1.Table_order[j].dish_name << " ";
                    cout << "Qty : " << All_cust[i].t1.Table_order[j].order_qty << " ";
                    cout << "Rate : " << All_cust[i].t1.Table_order[j].rate << "\n";

                    All_cust[i].t1.total_bill = All_cust[i].t1.total_bill + (All_cust[i].t1.Table_order[j].order_qty * All_cust[i].t1.Table_order[j].rate);
                }
                cout << "Total_bill : " << All_cust[i].t1.total_bill << endl;
                int paid;
                while (true)
                {
                    cout << "Pay To Bill Amount : ";
                    cin >> paid;
                    if (paid > All_cust[i].t1.total_bill)
                    {
                        cout << "Return : " << paid - All_cust[i].t1.total_bill << endl;
                        All_cust[i].t1.table_bill_paid = 1;
                        break;
                    }
                    else if (paid < All_cust[i].t1.total_bill)
                    {
                        cout << "Pay More : " << All_cust[i].t1.total_bill - paid << endl;
                        All_cust[i].t1.total_bill = All_cust[i].t1.total_bill - paid;
                    }
                    else
                    {
                        cout << "Bill Paid : \n";
                        All_cust[i].t1.table_bill_paid = 1;
                        break;
                    }
                }
            }
            //--------------------------------------------
            write_All_Cust_vector_file( All_cust[i] );
            return;
        }
    }
    if (flag == 0)
    {
        cout << "Invalid Table No...\n";
    }
}

void write_All_Cust_vector_file( Customer customer  )
{
    ofstream file("Bill.txt", ios::app);
    if (!file)
    {
        cout << "File cannot be opened! \n";
    }
    else
    {
        
            file << "Customer ID: " << customer.cus_ID << endl;
            file << "Name: " << customer.name << endl;
            file << "Date: " << customer.dd << "/" << customer.mm << "/" << customer.yy << endl;
            file << "Table No: " << customer.t1.table_no << endl;
           
            for (const auto& order : customer.t1.Table_order)
            {
                file << "Id: " << order.menu_id << " ";
                file << "Item: " << order.dish_name << " ";
                file << "Qty: " << order.order_qty << " ";
                file << "Rate: " << order.rate << "\n";
            }
            file << "Order Total Bill: " << customer.t1.total_bill << endl;
            file << "-----------------------------" << endl;   
    }
    cout << "Bill added in file successfully" << endl;
    file.close();
}





void register_customer()
{
    Customer c1;
    bool av = check_Table_Avail();
    if (av == true)
    {
        int ch;
        c1.accept_cust();
        cout << "Select Table: ";
        cin >> ch;//1
        All_Table[ch - 1].table_no = ch;
        All_Table[ch - 1].table_status = 1; // hotel table num
        c1.table_no=ch;
        c1.t1.table_no = ch ; // cust table num
        All_cust.push_back(c1);
    }
    else
    {
        cout << "Sorry, Table Not Available: " << endl;
    }
}

bool check_Table_Avail()
{
    bool avail = false;
    for (int i = 0; i < 5; i++)
    {
        if (All_Table[i].table_status == 0)
        {
            cout << "Table No: " << All_Table[i].table_no << " is available." << endl;
            avail = true;
        }
    }
    return avail;
}