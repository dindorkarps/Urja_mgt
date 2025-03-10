#ifndef CAPTAIN_H
#define CAPTAIN_H

#include <iostream>
#include <fstream>
#include "FoodItem.h"
#include "Display.h"
#include "Customer.h"

class Captain {
public:
    void CaptainPage();
    void orderFood(int tableNo);
    void serveFood();
};

#endif // CAPTAIN_H
