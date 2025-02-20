#include ".\headers\Login.h"
#include <iostream>
#include ".\headers\EnumMenuFunction.h"
#include ".\headers\Login.h"
#include ".\headers\Enums.h"
#include ".\headers\Manager.h"
#include ".\headers\Captain.h"
#include ".\headers\Chef.h" 
#include ".\headers\Receptionist.h"
using namespace std;




int main()
{
    int ch;
	
    User user;
    string username, password;
	while ((ch = mainMenu()) != 0)
	{
		switch (ch)
		{
		case EXIT:
			break;
		case MANAGER:
            cout << "Enter your username: ";
            cin >> username;    
            cout << "Enter your password: ";
            cin >> password;    
            if (user.validate_user(username, password))
            {
                cout<<"Welcome Manager"<<endl;
                Manager mgr;
                mgr.managerMenuHandler();
            }
            else
            {
                cout << "Login failed" << endl;
            }
		break;
        case RECEPTIONIST:
            cout << "Enter your username: ";
            cin >> username;    
            cout << "Enter your password: ";
            cin >> password;    
            if (user.validate_user(username, password))
            {
                cout<<"Welcome RECEPTIONIST"<<endl;
                //managerMenuHandler();
            }
            else
            {
                cout << "Login failed" << endl;
            }

			
		break;
        case CAPTAIN:
            cout << "Enter your username: ";
            cin >> username;    
            cout << "Enter your password: ";
            cin >> password;    
            if (user.validate_user(username, password))
            {
                cout<<"Welcome CAPTAIN"<<endl;
                //managerMenuHandler();
            }
            else
            {
                cout << "Login failed" << endl;
            }
                
		break;
		case CHEF:
            cout << "Enter your username: ";
            cin >> username;    
            cout << "Enter your password: ";
            cin >> password;    
            if (user.validate_user(username, password))
            {
                cout<<"Welcome CHEF"<<endl;
                //managerMenuHandler();
            }
            else
            {
                cout << "Login failed" << endl;
            }
            break;
		}
	}
}




// g++ User.cpp EnumMenuFunction.cpp dishItem.cpp OrderItem.cpp Order.cpp  Customer.cpp Manager.cpp Main.cpp



// ./a.out