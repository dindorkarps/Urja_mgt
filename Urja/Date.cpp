#include<iostream>
using namespace std;
#include"./headers/Date.h"
#include<time.h>
Date::Date()
{
	//Assign system date in constructor
	time_t t = time(NULL);
	struct tm now = *localtime(&t);
	this->day = now.tm_mday;
	this->month = now.tm_mon + 1;
	this->year = now.tm_year + 1900;
}
void Date::AcceptDate()
{

}
void Date::PrintDate()
{
	cout <<"Date : " <<this->day<<"-"<<this->month<<"-"<<this->year<<endl;
}

