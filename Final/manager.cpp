#include "header.h"

void Menu ::managerMenuHandler()
{
    //cout<<"Here-1"<<endl;
    cout<<"*******************************************\n";
    cout<<"~~~~~~~~~~~~Welcome to Manager Menu~~~~~~~~\n";
    cout<<"*******************************************\n";
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
                        cout<<"*******************************************\n";
                        break;
                case VIEW_FOOD_MENU:
                        viewFoodMenu();
                        cout<<"*******************************************\n";
                        break;
                case EDIT_FOOD_MENU:
                        editFoodMenu();
                        cout<<"*******************************************\n";
                        break;
                case DELETE_FOOD_MENU:
                       deleteFoodMenu();
                       cout<<"*******************************************\n";
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
                        cout<<"*******************************************\n";
                break;
                case MANAGE_VIEW_TODAYS_BILL:
                        //viewTodaysBill();
                        cout<<"*******************************************\n";
                break;
                }  
            }  
        }
    }
}
//------------------------------------------
int managerMenu()
{
	int ch;
    cout<<"Here-2"<<endl;
	cout << " \n 1 : MANAGE FOOD MENU \n 2 : MANAGE BILLING \n";
	cout << "Enter your choice: ";
    cin >> ch;
    cout<<"*******************************************\n";
	return ch;
}
//------------------------------------------
int managerfoodMenu()
{
	int ch;
	cout << " \n 1 : ADD FOOD MENU \n 2 : VIEW FOOD MENU \n 3 : EDIT FOOD MENU \n 4 : DELETE FOOD MENU \n";
    cout << "Enter your choice: ";
	cin >> ch;
    cout<<"*******************************************\n";
	return ch;
}
//------------------------------------------
void Menu :: addFoodMenu() ////write file
{
    Menu m1;
    int ch ;
    do{
        m1.saveToFile(); 
        cout<< ""<<endl;
        cout<<"Do you want to add more food items? (1-Y/0-N): ";
        cin>>ch;
    }while(ch == 1);
    cout<<"*******************************************\n";


}
//-----------------------------------------
void Menu::viewFoodMenu() // read file
{
    ifstream file("FoodMenu.txt");
    if (!file)
    {
        cout << "File cannot be opened! \n";
    }
    else
    {
        Menu  m1;
        cout << "Food Menu:\n";
        while (file >> m1.id >> m1.name >> m1.rate)
        {
            cout << "ID: " << m1.id << ", Name: " << m1.name << ", Rate: " << m1.rate << "\n";
        }
    }
    file.close();
    cout<<"*******************************************\n";
}
//------------------------------------------
void Menu::editFoodMenu()
{
    vector<Menu> myVector;
    add_menu_vector(myVector);
    

    // Display all objects in the vector
    display_vector(myVector);
    edit_vector(myVector);
    write_vector_file(myVector);
    cout<<"*******************************************\n";
}
//------------------------------------------
void add_menu_vector(vector<Menu> &myVector)
{
    Menu m1;
    ifstream file("FoodMenu.txt");
    if (!file)
    {
        cout << "File cannot be opened! \n";
        return;
    }
    else
    {
        cout << "Food Menu:\n";
        while (file >> m1.id >> m1.name >> m1.rate)
        {
            myVector.push_back(m1);
        }
    }
    file.close();
    cout<<"*******************************************\n";
}
//------------------------------------------
void display_vector(vector<Menu> &myVector)
{
    for (const auto& obj : myVector) 
    {
        cout << "ID: " << obj.id << ", Name: " << obj.name << ", Rate: " << obj.rate << "\n";
    }
    cout<<"*******************************************\n";
}

void edit_vector(vector<Menu> &myVector)
{
    int id, flag = 0;
    cout << "Enter the ID of the food item you want to edit: ";
    cin >> id;

    // Find and edit the food item with the given ID
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        if (it->id == id) 
        {
            cout << "Enter new details for the food item: " << endl;
            it->readFoodMenu();
            cout << "Food item edited successfully" << endl;
            flag = 1;
            break; // Exit the loop after editing
        }
    }
    if (flag == 0)
    {
        cout << "Sorry, food item not found" << endl;
    }
    cout<<"*******************************************\n";
}

//--------------------------------------------
void write_vector_file(vector<Menu> &myVector)
{
    ofstream file("FoodMenu.txt");
    if (!file)
    {
        cout << "File cannot be opened! \n";
    }
    else
    {
        for (const auto& obj : myVector) 
        {
            file << obj.id << " " << obj.name << " " << obj.rate << "\n";
        }
        cout << "Food Menu updated successfully" << endl;
    }
    file.close();
    cout<<"*******************************************\n";
}
//----------------------------------------------
void Menu :: deleteFoodMenu()
{
    vector<Menu> myVector;
    add_menu_vector(myVector);
    display_vector(myVector);
    int x= delete_vector(myVector);
    //display_vector(myVector);
    if(x==1)
        write_vector_file(myVector);
        cout<<"*******************************************\n";
}
int Menu :: delete_vector(vector<Menu> &myVector)
{
    int id, flag = 0;
    cout << "Enter the ID of the food item you want to delete: ";
    cin >> id;

    // Find and delete the food item with the given ID
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        if (it->id == id) 
        {
            it = myVector.erase(it);
            cout << "Food item deleted successfully" << endl;
            flag = 1;
            return 1;
            break; // Exit the loop after deleting
        }
    }
    if (flag == 0)
    {
        cout << "Sorry, food item not found" << endl;
    }
    cout<<"*******************************************\n";
    return 0;
}