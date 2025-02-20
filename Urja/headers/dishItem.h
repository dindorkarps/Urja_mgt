#ifndef DISH_H
#define DISH_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


class dishItem
{
	int dishItemID;
	string dishItemName;
	int price;
public:
	int getDishItemID();
	string getDishItemName();
	//string getDishCategory();
	int getPrice();
	void setDishItemID(int id);
	void setDishItemName(string name);
	//void setDishCategory(string cat);
	void setPrice(int p);
	void saveinFile(ofstream &fout);
	void loadFromFrole(ifstream &fin);

	friend istream& operator >> (istream &in, dishItem &c);
	friend ostream& operator<< (ostream &out, dishItem &c);
	//int CategoryMenu();
};
#endif