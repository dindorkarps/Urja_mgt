#include "header.h"
#include "table.h"

using namespace std;

int main()
{
    int ch;
    cout<<"*******************************************\n";
	cout << "~~~~Welcome To Urja Hotel~~~~"<<endl;
    cout<<"*******************************************\n";
    User user;
    string username, password;
    initialise_table();
	while ((ch = mainMenu()) != 0)
	{
		switch (ch)
		{
		case EXIT:
			break;
            cout<<"*******************************************\n";
		case MANAGER:
            cout << "Enter your username: ";
            cin >> username;    
            cout << "Enter your password: ";
            cin >> password;    
            if (user.validate_user(username, password))
            {
                cout<<"Welcome Manager"<<endl;
                Menu m1;
                m1.managerMenuHandler();
            }
            else
            {
                cout << "Login failed" << endl;
            }
            cout<<"*******************************************\n";
		break;
        case RECEPTIONIST:
            // cout << "Enter your username: ";
            // cin >> username;    
            // cout << "Enter your password: ";
            // cin >> password;    
            // if (user.validate_user(username, password))
            // {
                //cout<<"Welcome RECEPTIONIST"<<endl;
                recep_MenuHandler();
            // }
            // else
            // {
            //     cout << "Login failed" << endl;
            // }
            cout<<"*******************************************\n";	
		break;
        case CAPTAIN:
            // cout << "Enter your username: ";
            // cin >> username;    
            // cout << "Enter your password: ";
            // cin >> password;    
            // if (user.validate_user(username, password))
            // {
                //cout<<"Welcome CAPTAIN"<<endl;
                captain_MenuHandler();
            // }
            // else
            // {
            //     cout << "Login failed" << endl;
            // }
            cout<<"*******************************************\n";   
		break;
		case CHEF:
            // cout << "Enter your username: ";
            // cin >> username;    
            // cout << "Enter your password: ";
            // cin >> password;    
            // if (user.validate_user(username, password))
            // {
                //cout<<"Welcome CHEF"<<endl;
                chef_MenuHandler();
            //}
            // else
            // {
            //     cout << "Login failed" << endl;
            // }
            cout<<"*******************************************\n";
            break;
		}
	}
    cout<<"*******************************************\n";
    return 0;
    
}




// g++ User.cpp EnumMenuFunction.cpp dishItem.cpp OrderItem.cpp Order.cpp  Customer.cpp Manager.cpp Main.cpp



// ./a.out