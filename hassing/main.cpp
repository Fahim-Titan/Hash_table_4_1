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

    hash Hash_obj;
    string name = "";
    string choice;

    cout << "\t\t###  welcome to Hash Table creation program  ###\n\n";
    cout << "\t\tenter your choices: \n";

    //cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$_____$$$$\n$$$$_____$$$$$$$$$$$$$$$_____$$$$\n$$$$_____$$$$$$$$$$$$$$$_____$$$$\n$$$$_____$$____$$$____$$_____$$$$\n$$$$_____$______$______$_____$$$$\n$$$$_____$______$______$_____$$$$\n$$$$_____$____$$$$$$$$$$$$$$$$$$$\n$$$$_____$___$$___________$$$$$$$\n$$$$_____$__$$_______________$$$$\n$$$$__________$$_____________$$$$\n$$$$___________$$___________$$$$$\n$$$$_____________$_________$$$$$$\n$$$$$_____________________$$$$$$$\n$$$$$$___________________$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n";
        //terminal response
    while (choice != "quit")
    {
        cout << "\n\n\t\t\t1->Insert\n\t\t\t2->Look Up\n\t\t\t3->Show Data\n\t\t\t4->Delete\n\n";
        cout << "\n\n\twrite \"quit\" to quit the program\n\n\n\t:";
        cin >> choice;
        if (choice == "1")
        {
            string var_name, data_type;
            cout << "enter in the following format\t\t [variable_name] [data_type]\n";
            cin >> var_name;
            cin >> data_type;
            Hash_obj.AddItem(var_name, data_type);
        }
        else if(choice == "2")
        {
            string var_name;
            cout << "write the variable name\t:";
            cin >> var_name;
            Hash_obj.FindData_Type(var_name);
        }
        else if (choice == "3")
        {
            cout << "\n\n";
            Hash_obj.PrintTable();
        }
        else if (choice == "4")
        {
            string var_name;
            cout << "enter the variable you want to delete\t:";
            cin >> var_name;
            Hash_obj.RemoveItem(var_name);
        }
        else if(choice == "quit")
        {
            cout << "quiting...";
        }
        else
        {
            cout << "invalid choice";
        }
    }

    return 0;
}

