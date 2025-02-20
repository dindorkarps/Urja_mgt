
#include "./headers/OrderItem.h"
#include "./headers/dishItem.h"
#include "./headers/Order.h"
#include <iostream>
#include <vector>
using namespace std;

void Order::markAsReady()
{
    status = 1;
}

void Order::addItem(OrderItem item)
{
    items.push_back(item);
}
