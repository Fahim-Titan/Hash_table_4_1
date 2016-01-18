/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Al Masum Fahim
 *
 * Created on January 16, 2016, 7:51 PM
 */

#include <cstdlib>
#include<iostream>
#include<string>

#include "hash.h"

using namespace std;


int main(int argc, char** argv) {

    hash Hashy;
    string name = "";

    Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothie");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

    Hashy.PrintTable();
    //Hashy.PrintItemInIndex(8);

  /*  while (name != "quit")
    {
        cout << "\nsearch for ";
        cin >> name ;
        if (name != "quit")
        {
            Hashy.FindDrink(name);
        }
    }*/

    while (name != "quit")
    {
        cout << "Remove : ";
        cin >> name;

        if (name != "quit")
        {
            Hashy.RemoveItem(name);
        }
    }
    Hashy.PrintTable();

    return 0;
}

