#include "FoodItem.h"
#include "Manager.h"
#include <iostream>
#include <conio.h>
using namespace std;


ManagerSubclass m;
void FoodItem::addFoodItem() {
    FILE *fp;
    FoodItem fi;

    
    fp = fopen("FoodMenu.txt", "ab");
    if (!fp) {
        cout << "File cannot be opened! \n";
        cout << "Press any key to continue\n";
        getch();
        return; 
    }

    
    fi.id = getNewId();

    // Take input for new food item
    cout << "Enter Item Name: ";
    cin >> fi.name;
    cout << "Enter Item Price: ";
    cin >> fi.price;

    // Check for duplicate item
    if (isDuplicateItem(fi.name)) {
        cout << "\nThis item is already in the file!!!\n";
        cout << "\nEnter a new item or edit the cost.\n";
        fclose(fp);
        cout << "\nPress any key to continue...\n";
        getch();
        system("cls");
        return;  
    }

    // Write new item to file
    fwrite(&fi, sizeof(FoodItem), 1, fp);
    fclose(fp);

    cout << "\nItem successfully added\n";
    cout << "\nPress any key to continue...\n";
    getch();
    system("cls");
    m.managerPage();
}

    void FoodItem::displayAllFoodItems() {
        FoodItem fi;
        FILE *fp = fopen("FoodMenu.txt", "rb");  
    
        if (!fp) {  
            cout << "Error: File cannot be opened! \n";
            cout << "Press any key to continue...\n";
            getch();
            return; 
        }
    
        cout << "\nID:\t\tItem Name:\t\tPrice (Rs.)\n";
        cout << "-------------------------------------------\n";
    
        bool isEmpty = true;
        while (fread(&fi, sizeof(FoodItem), 1, fp)) {
            cout << fi.id << "\t\t" << fi.name << "\t\t" << fi.price << "\n";
            isEmpty = false;
        }
    
        fclose(fp);  
    
        if (isEmpty) {
            cout << "No food items available in the menu.\n";
        }
    
        cout << "\nPress any key to continue...\n";
        getch();
        m.managerPage();

    }
    
void FoodItem::updateFoodItem() {
    FILE *fp = fopen("FoodMenu.txt", "rb+");
    if (!fp) {
        cout << "File cannot be opened!\n";
        return;
    }

    int searchId;
    cout << "\nEnter Food ID to update: ";
    cin >> searchId;

    FoodItem temp;
    bool found = false;

    while (fread(&temp, sizeof(FoodItem), 1, fp)) {
        if (temp.id == searchId) {
            cout << "\nEnter new Name: ";
            cin.ignore();
            cin.getline(temp.name, sizeof(temp.name));
            cout << "Enter new Price: ";
            cin >> temp.price;
            fseek(fp, -static_cast<long>(sizeof(FoodItem)), SEEK_CUR);
            fwrite(&temp, sizeof(FoodItem), 1, fp);
            found = true;
            break;
        }
    }

    fclose(fp);
    if (found){
        cout << "\nFood item updated successfully!\n";
        m.managerPage();
    }
    else
        cout << "\nFood item not found!\n";
        m.managerPage();
}

void FoodItem::deleteFoodItem() {
    FILE *fp = fopen("FoodMenu.txt", "rb");   // Open in binary read mode
    FILE *tempFile = fopen("Temp.txt", "wb"); // Open temp file in binary write mode

    if (!fp || !tempFile) {
        cout << "File cannot be opened!\n";
        if (fp) fclose(fp);
        if (tempFile) fclose(tempFile);
        return;
    }

    int deleteId;
    cout << "\nEnter Food ID to delete: ";
    cin >> deleteId;

    FoodItem temp;
    bool found = false;

    while (fread(&temp, sizeof(FoodItem), 1, fp)) {
        if (temp.id == deleteId) {
            found = true;  // Item found, don't copy it to temp file
        } else {
            fwrite(&temp, sizeof(FoodItem), 1, tempFile);
        }
    }

    fclose(fp);
    fclose(tempFile);

    // Delete old menu file and replace with temp file
    remove("FoodMenu.txt");
    rename("Temp.txt", "FoodMenu.txt");

    if (found) {
        cout << "\nFood item deleted successfully!\n";
    } else {
        cout << "\nFood item not found!\n";
    }

    cout << "Press any key to continue\n";
    getch();
    system("cls");
    m.managerPage();
}



int FoodItem::getNewId()
{
	int countId=1;
	FILE *fp;
	FoodItem fi;
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL)
    {
		cout<<"cannot be opened file in getNewId \n";
	}
	else
	{
		while(fread(&fi,sizeof(FoodItem),1,fp))
		{
            countId++;
		}
        fclose(fp);
	}
	fclose(fp);
	return countId;
}

bool FoodItem::isDuplicateItem(char item[30])
{
	bool result=false;
	FILE *fp;
	FoodItem fi;
	fp=fopen("FoodMenu.txt","r");
	if(fp==NULL)
    {
		cout<<"Cannot open file! \n";
	}
	else
	{
		while(fread(&fi,sizeof(FoodItem),1,fp))
		{
            if(strcmp(fi.name,item)==0)
            {
                result=true;
            }
		}
		fclose(fp);
	}
	fclose(fp);
	return result;
}