
/* 
By Mia Armstrong
CS163 
Program #2
*/
//File: stack.h
//This is the header file for the stack ADT class.

#include "info.h"

struct s_node
{
    store_info * entries; // a dynamically allocated array of store info.
    s_node * next;// a node pointer
};

const int MAX = 5;

class stack
{
    public:
          stack(); //constructor for stack class
          ~stack();//destructor for stack class
          int display()const;//displays each element of the array in each node.
          int push(const store_info & a_store);//add an element to the top of the stack
          int pop();//remove an element from the top of the stack
          int peek(store_info & found_store)const;//display the element at the top of the stack.

    private:
          s_node * s_head;
          int top_index; //the index for the next place to push, set to zero
                         //by constructor, when it is MAX, the array if full
};
