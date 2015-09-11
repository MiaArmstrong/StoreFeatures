         
/* 
By Mia Armstrong
CS163 
Program #2
*/
//File: queue.cpp
//This file has all the functions for the queue ADT class.


#include "queue.h"

//Sets the rear pointer to null
queue::queue()
{
    rear = NULL;
}
           
//deletes all the nodes in the list.
queue::~queue()
{
   
    while (rear)
    {
      q_node * current = rear->next;
      delete rear;
      rear = current;
     }
     rear = NULL;
}
           
//displays all the objects in the nodes in the list
//returns 0 if the list is empty, 1 if the list was displayed.
int queue::display_all()const
{
   if (!rear)
      return 0; //if the queue is empty return o

   if (rear->next != rear)
   {
       q_node * current = rear->next;
     
        while (current != rear)
        {
           current->store.display();
           current->product.display_feature();
           current = current->next;
        }
    
     rear->store.display();
     rear->product.display_feature();
    }
      return 1;
}
           
//creates a new node and adds it to the end of the list
//returns a 1 for sucess.
int queue::enqueue(const store_info & a_store, const product_info & a_product)
{
    q_node * temp = new q_node;
    temp->store.copy_store(a_store);
    temp->product.copy_feature(a_product);

    if(!rear)
    {
       rear = temp;
       rear->next = rear;
     }

     else
     {
        q_node * current = rear->next;
        temp->next = current;
        rear->next = temp;
        rear = temp;
      }
      return 1;
}

//removes a node from the front of the list.
//returns a 0 if the list is empty and a 1 if the node was removed.           
int queue::dequeue()
{
   if (!rear)
      return 0;
     
   if (rear->next == rear)
   {
      delete rear;
      rear = NULL;
   }

   else
   {
      q_node * current = rear->next;
      rear->next = current->next;
      delete current;
   }
   return 1;
}

