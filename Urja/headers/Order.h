
#ifndef Order_H
#define Order_H

#include <vector>
#include "OrderItem.h"
using namespace std;
class Order 
{
    private:
        int orderId;
            vector<OrderItem> items;
            int status; //1 for ready 0 for pending
        public:
            Order(){   }
            Order(int id):orderId(id),status(0){ 
                
            }
            
            void addItem(OrderItem item);
            void markAsReady(); //make satatus as 1
};
#endif