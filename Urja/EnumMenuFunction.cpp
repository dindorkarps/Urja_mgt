#include ".\headers\EnumMenuFunction.h"
#include ".\headers\Enums.h"
#include <iostream>
using namespace std;

int mainMenu()
{
	int ch;
	cout << " \n 0 : Exit \n 1 : MANAGER \n 2 : RECEPTIONIST \n 3 : CAPTAIN \n 4 : Chef\n";
	cin >> ch;
	return ch;
}
int managerMenu()
{
	int ch;
	cout << " \n 1 : MANAGE FOOD MENU \n 2 : MANAGE BILLING \n";
	cin >> ch;
	return ch;
}
int managerfoodMenu()
{
	int ch;
	cout << " \n 1 : ADD FOOD MENU \n 2 : VIEW FOOD MENU \n 3 : EDIT FOOD MENU \n 4 : DELETE FOOD MENU \n";
	cin >> ch;
	return ch;
}
int managerBilling()
{
	int ch;
	cout << " \n 1 : MANAGE VIEW BILL DATE RANGE \n 2 : MANAGE VIEW TODAYS BILL \n";
	cin >> ch;
	return ch;
}
int receptionistMenu()
{
	int ch;
	cout << " \n 1 : REGISTER CUSTOMER \n 2 : GENERATE BILL \n";
	cin >> ch;
	return ch;
}
int captaintMenu()
{
	int ch;
	cout << " \n 1 : CAPTAIN TAKE ORDER \n 2 : CAPTAIN SERVE ORDER \n";
	cin >> ch;
	return ch;
}
int chefMenu()
{
	int ch;
	cout << " \n 1 : CHEF DISPLAY PENDING ORDER \n 2 : CHEF PROCESS ORDERS \n";
	cin >> ch;
	return ch;
}
