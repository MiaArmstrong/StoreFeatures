/*By Mia Armstrong
CS163 
Program #2
*/
//File: ordered_list.h
// header file for the ordered list class. 

#include "queue.h"

const int LIST_SIZE = 6;// The maximum size of the ordered list is 5. The first element of the list is left open. 

class Ordered_list
{
    public: 
          Ordered_list(); //constructor for the ordered list class
          ~Ordered_list();//destructor for the ordered list class
          int insert(int count, int position, const product_info & to_add);//Inserts a product info object into the list by position
          int remove(int count, int position);//removes a product_info object from the list by position.
          int retrieve(int position, product_info & found)const;//gives a product_info object back to the calling routine by position of the object.
          int display() const;//displays all the objects in the list.

    private:
         int position; //to keep track of the current index of the list.
         int count; //to keep track of the number of items in the list.
         product_info * products;//dynamically allocated array of product_info objects.
};
