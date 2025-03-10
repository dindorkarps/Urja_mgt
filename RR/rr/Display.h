#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <cstdlib> 
#include <conio.h> 


using namespace std;

class Manager;
class User;

class Display
{
public:
    void firstScreen();
    void secondScreen();
    void printStar(int n);
    void welcome();
};

#endif // DISPLAY_H
