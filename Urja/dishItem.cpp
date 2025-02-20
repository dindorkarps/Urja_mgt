#include"./headers/dishItem.h"

#include<cstring>
#include <fstream>
#include <iostream>
using namespace std;

void dishItem::saveinFile(ofstream &fout)
{
	fout.write((char*)&this->dishItemID, sizeof(this->dishItemID));
	//fout.write(this->dishItemName, sizeof(this->dishItemName));
	fout.write(this->dishItemName.c_str(), this->dishItemName.size() + 1);
	//fout.write(this->getDishCategory(), sizeof(this->dishItemName));
	fout.write((char*)&this->price, sizeof(this->price));
}
void dishItem::loadFromFrole(ifstream &fin)
{
	// string strTemp;
	// fin.read((char*)&this->dishItemID, sizeof(this->dishItemID));
	// fin.read(this->dishItemName, sizeof(this->dishItemName));
	// fin.read(strTemp, sizeof(this->dishItemName));
	// //this->setDishCategory(strTemp);
	// fin.read((char*)&this->price, sizeof(this->price));
	fin.read((char*)&this->dishItemID, sizeof(this->dishItemID));
    getline(fin, this->dishItemName, '\0');
    fin.read((char*)&this->price, sizeof(this->price));
}

istream& operator >> (istream &in, dishItem &c)
{
	cout << "Enter Items Details : " << endl;
	cout << " dishItemID: ";
	in >> c.dishItemID;
	cout << " dish Item Name: ";
	in >> c.dishItemName;
	cout << " Unit price: ";
	in >> c.price;
	return in;
}
ostream& operator<< (ostream &out, dishItem &c)
{
	out << "\n " <<c.getDishItemID()<<"  "<<"    " << c.dishItemName << "     " << c.price;
	return out;
}
int dishItem::getDishItemID()
{
	return this->dishItemID;
}
string dishItem::getDishItemName(){
	return this->dishItemName;
}

void dishItem::setDishItemID(int id)
{
	this->dishItemID = id;
}
void dishItem::setDishItemName(string name)
{
	this->dishItemName = name;
}

void dishItem::setPrice(int p)
{
	this->price = p;
}
int dishItem::getPrice(){
	return this->price;
}
