/* 
By Mia Armstrong
CS163 
Program #2
*/
//File: main.cpp
//This is the testbed for assignment 2. 
using namespace std;

#include "ordered_list.h"
const int SIZE = 100;


bool remove();//asks user if they want to remove
bool again();//asks user if they want to add a feature.

int main()
{
   int priority = 0; //to determine the place in the list
   int count = 0;// to help with removal from the list.
   char new_feature[SIZE]; //temporary for product info.
   char new_store[SIZE]; //temporary for store info.
   product_info a_feature, to_add, found;//make new product_info objects
   store_info a_store, found_at_top;//make new store_info objects
   Ordered_list a_list;//make an ordered_list
   stack stores;//make a stack
   queue store_product;//make a queue

   
    //Add features into the list.
   do
   {
       cout << "Enter a feature " << endl;
       cin.get(new_feature, SIZE, '\n'); cin.ignore(SIZE, '\n');

       to_add.create_feature(new_feature);
   

       cout << "Entry the priority of the feature (1-5)" << endl;
       cin >> priority; cin.ignore(SIZE, '\n');

       count = a_list.insert(count, priority, to_add);

       a_list.display();
 
       //remove features from the list.
       while(remove())
       {	
   	   cout << "Enter the number of the feature to remove: " << endl;
   	   cin >> priority; cin.ignore(SIZE, '\n');

   	   count = a_list.remove(count, priority);

   	   a_list.display(); 
       }
   }while(again());

   //add stores to the queue
   do
   {
      cout << "enter a store. " << endl;
      cin.get(new_store, 100); cin.ignore(SIZE, '\n');

      cout << "Enter a product at this store: " << endl;
      cin.get(new_feature, 100); cin.ignore(SIZE, '\n');
   
      a_store.create_store(new_store);
      a_feature.create_feature(new_feature);
      store_product.enqueue(a_store, a_feature);
   
      store_product.display_all();
      
   }while(again());

   //find stores that have producst that match the products in the list
  // do
  // {
      //compare the ordered list to the queue
  // }while(again());

}

//Asks user if they would like to add another.
//returns true for yes and false for everything else
bool again()
{
  char responce;
  cout << "\nAdd another (y/n)?" << endl;
  cin >> responce; cin.ignore(SIZE, '\n');

  if (responce == 'y')
     return 1;
  else
     return 0;
}

//Asks user if they would like to remove an entry
//returns a true for yes and a false for everything else.
bool remove()
{
   char responce;
   cout << "\nRemove an entry (y/n)? " << endl;
   cin >> responce; cin.ignore(SIZE, '\n');

   if (responce == 'y')
      return 1;
   else
      return 0;
}
