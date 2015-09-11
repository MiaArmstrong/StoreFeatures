
/*By Mia Armstrong
CS163 
Program #2
*/
//File: ordered_list.cpp
// This file has all the functions for the ordered_list ADT class. The list is an array of product_info objects.

#include "ordered_list.h"

using namespace std;

//allocates a new array of products and sets count and position to 0.          
Ordered_list::Ordered_list()
{
    products = new product_info[LIST_SIZE];
  
    count = 0; 
    position = 0;
}

//deallocates an array of products.          
Ordered_list::~Ordered_list()
{
    delete [] products;
}

//inserts a product_info object into the list at the position.
//returns count.          
int Ordered_list::insert(int count, int position, const product_info & to_add)
{

    int success = products[position].copy_feature(to_add);// create an object and fill with data.
    if (success == 1)  //if there is already data in the index it will be overwritten.
       ++count;
    return count;
}
          
//removes a product_info object from the list at the position.
//returns count.
int Ordered_list::remove(int count, int position)
{
    products[position].remove_feature();
    
    
   // for (int i = position; i < count; ++i)
     //   products[i].copy_feature(products[i + 1]); // shift each feature up one position on the list
    
    //products[count].remove_feature(); //set the empty spot at the end of the list to null.
    
    --count;

    return count;
}

//Supplies calling routine with the object found at the position.
//returns non zero for success.          
int Ordered_list::retrieve(int position, product_info & found)const
{
    int success = products[position].retrieve_feature(found);
    return success;
}
          
//displays all the objects in the list
//returns 1 is thre are items in the list.
int Ordered_list::display() const
{
    for (int i = 0; i < LIST_SIZE; ++i)
    {
       products[i].display_feature(i);
    }

    return 1;
}
