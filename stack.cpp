
/* 
By Mia Armstrong
CS163 
Program #2
*/
//File: stack.cpp
//This file has the functions for the stack ADT class.

#include "stack.h"
using namespace std;

//allocates a new node and a new array of store_info in the node
//sets top_indoex to 0.         
stack::stack()
{
   s_head = new s_node;
   top_index = 0;
   s_head->entries = new store_info[MAX];
}
          
//deallocates the array in each node and then deletes the node.
stack::~stack()
{
    while (s_head)
    {
        s_node * current = s_head;
        delete [] current->entries;
        s_head = current->next;
        delete current;
    }
    s_head = NULL;
}
          
//Displays all the elements in each array in each node
//returns 0 if there is no stack, 1 if stack was displayed.
int stack::display()const
{
    if (!s_head)
       return 0;

    s_node * current = s_head;

    int index = top_index - 1;

    while (current)
    {
       for (int i = 0; i < index; ++i)
          current->entries[i].display();
       
       index = MAX;

       current = current->next;
    }
    return 1;
}

//adds an element to the top of the stack and creates a new node when the array is full
//returns 1 if push is successful.          
int stack::push(const store_info & a_store)
{
    if (!s_head)
    {
       s_head = new s_node;
       s_head->next = NULL;
       s_head->entries = new store_info[MAX];
       top_index = 0;
     } // if there is not a list, make a new list.

     if (top_index == MAX)
     {
        s_node * temp = new s_node;
        temp->next = s_head;
        temp->entries = new store_info[MAX];
        s_head = temp;
        top_index = 0;
      } //if the array is full make a new node.

      s_head->entries[top_index].copy_store(a_store);
      ++ top_index;
         //push entry to the top of the stack. 
      return 1;
}

//removes an element from the top of the stack
//returns 0 if the stack is emptry, 1 if remove was successful          
int stack::pop()
{
    if (!s_head)
       return 0;

    if (top_index != 0)
       -- top_index;

    else
    {
       s_node * current = s_head;
       s_head = current->next;
       delete [] current->entries;
       delete current;
       top_index = MAX;
     }
      
     return 1;
}

//This function supplies the store at the top of the stack back to the client
//Return 0 if there are no items
//Return 1 if peek is successful          
int stack::peek(store_info & found_store)const
{
    if (!s_head)
       return 0;
    
    if (top_index == 0)
    {
        s_node * current = s_head->next;
        current->entries[top_index].retrieve(found_store);
    }    

    else 
       s_head->entries[top_index - 1].retrieve(found_store);

    return 1;
}


