
/*By Mia Armstrong
CS163 
Program #2
*/
//File: info.cpp
// This file has all the function for the product_info class and the store_info class. 


#include "info.h"
using namespace std;

// This function initialises feature to NULL.
product_info::product_info()
{
    feature = NULL;
}

//This function deallocates feature.         
product_info::~product_info()
{
    if (feature)
       delete [] feature;
}

//This function takes the argument and dynamically allocates 
//it into an array. It returns an int, 0 for failure and 1 for success          
int product_info::create_feature(char * new_feature)
{
    if (new_feature)
    {
       feature = new char[strlen(new_feature) +1];
       strcpy(feature, new_feature); //deep copy feature.
       return 1;
    }
    else
       return 0;
}

//This function takes the argument and copies it into the 
//product data members. It returns an int 0 for failure and 
// 1 for success.         
int product_info::copy_feature(const product_info & new_info)
{
   
    if (feature)
       delete [] feature; //deallocates any memory owned by the current object.
 
    if (!new_info.feature)
       return 0;  // check for feature
   
    if (new_info.feature)
    {
       feature = new char[strlen(new_info.feature) +1];
       strcpy(feature, new_info.feature); //deep copy feature
    }
    
    return 1;
}

//This function will return non-zero if the feature send in as
//an argument matches the data member. It supplies the matching
//feature back as an argument.          
int product_info::retrieve_feature(product_info & found)
{

    found.feature = new char[strlen(feature) +1];
    strcpy(found.feature, feature);
    return 1;
}
          
int product_info::remove_feature()
{
    if (feature)
    {
       delete [] feature;
       return 1;
    }
    else
       return 0;
}
//This function displays a feature. It returns a non zero int if the 
// feature was displayed.
int product_info::display_feature(int position)
{
    if (feature)
    {
        cout << position << ") " << feature << "\t"; 
        return 1;
    }
    else
       return 0;
}

int product_info::display_feature()
{
    if(feature)
    {
       cout << feature << "\t";
       return 1;
    }
    else
       return 0;
}
          
// This function initialises store to NULL.
store_info::store_info()
{
    store = NULL;
}
//This function deallocates store.          
store_info::~store_info()
{
    if(store)
      delete [] store;
}
          
//This function takes the argument and dynamically allocates 
//it into an array. It returns an int, 0 for failure and 1 for success          
int store_info::create_store(char * new_store)
{
    
    if (new_store)
    {
       store = new char[strlen(new_store) +1];
       strcpy(store, new_store); //deep copy store.
       return 1;
    }
    else
       return 0;
}
          
//This function takes the argument and copies it into the 
//store data members. It returns an int 0 for failure and 
// 1 for success.         
int store_info::copy_store(const store_info & new_store)
{

    if (store)
       delete [] store; //deallocates any memory owned by the current object.

    if (!new_store.store)
       return 0;  // check for feature

    if (new_store.store)
    {
       store = new char[strlen(new_store.store) +1];
       strcpy(store, new_store.store); //deep copy feature
    }
    
    return 1;
}
          
//This function will return non-zero if the store sent in as
//an argument matches the data member. It supplies the matching
//store back as an argument.          
int store_info::retrieve(store_info & found_store)const
{

    found_store.store = new char[strlen(store) +1];
    strcpy(found_store.store, store);
    return 1;
}
          
//This function displays a store. It returns a non zero int if the 
// store was displayed.
int store_info::display()
{

    if (store)
    {
        cout << store << "\t"; 
        return 1;
    }
    else
       return 0;
}

