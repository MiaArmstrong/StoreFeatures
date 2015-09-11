
/*By Mia Armstrong
CS163 
Program #2
*/
//File: queue.h
// header file for the queue class. This ADT is a queue implemented as a circular linked list.


#include "stack.h"

struct q_node
{
    store_info store;//a store_info object
    product_info product;//a product_info object
    q_node * next;//a node pointer
};

class queue
{
    public:
           queue();//constructor for queue
           ~queue();//destructor for queue
           int display_all()const;// displays all contents of the nodes in the queue
           int enqueue(const store_info & a_store, const product_info & a_product);//adds a node to the back of the queue
           int dequeue();//removes a node from the front of the queue
    private:
           q_node * rear;// node pointer
};
