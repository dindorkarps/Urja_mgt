#ifndef FOODITEM_H
#define FOODITEM_H

#include <iostream>
#include <cstdio>   // For file handling
#include <cstring>  // For string functions

class FoodItem {
public:
    int id;
    char name[50];
    float price;

public:

    bool isDuplicateItem(char name[30]);
    void addFoodItem();
    int getNewId();
    void displayAllFoodItems();
    void updateFoodItem();
    void deleteFoodItem();
};

#endif
