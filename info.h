/*By Mia Armstrong
CS163 
Program #2
*/
//File: info.h
// header file for product info and store info classes. 

#include <cctype>
#include <iostream>
#include <cstring>

class product_info
{
    public:
          product_info();//constructor 
          ~product_info();//destructor
          int create_feature(char * new_feature);//deep copy into object memebers
          int copy_feature(const product_info & new_info);//copy into an object
          int retrieve_feature(product_info & found);//give an object back to the calling routine
          int remove_feature();//remove a feature
          int display_feature(int position);//for the ordred list.
          int display_feature();//display a feature
    private:
          char * feature;//dynamically allocated array of char
};

class store_info
{
    public:
          store_info();//constructor
          ~store_info();//destructor
          int create_store(char * new_store);//deep copy into object members
          int copy_store(const store_info & new_store);//copy into an object
          int retrieve(store_info & found_store)const;//give an object back to the calling routine
          int display();//display a store
    private:
          char * store;//dynamically allocated array of char
};
