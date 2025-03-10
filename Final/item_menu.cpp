#include "header.h"
#include <fstream>

Menu::Menu()
{
    id = 0;
    name = "";
    rate = 0;
}

Menu::Menu(int id, const std::string &name, int rate)
{
    this->id = id;
    this->name = name;
    this->rate = rate;
}

void Menu::readFoodMenu()
{
    cout << "Enter Food ID: ";
    cin >> id;
    cin.ignore(); // Ignore the newline character left in the buffer
    cout << "Enter Food Name: ";
    getline(cin, name);
    cout << "Enter Food Price: ";
    cin >> rate;
}

void Menu::saveToFile()
{
    Menu m;
    m.readFoodMenu();

    ofstream file("FoodMenu.txt", ios::app);
    if (!file)
    {
        cout << "File cannot be opened! \n";
    }
    else
    {
        file << m.id << " " << m.name << " " << m.rate << "\n";
        cout << "\nItem successfully added\n";
    }
    file.close();

    cout << "Food Menu Added Successfully" << endl;
}