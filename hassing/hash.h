
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   hash.h
 * Author: Al Masum Fahim
 *
 * Created on January 16, 2016, 7:52 PM
 */

#include <cstdlib>
#include<iostream>
#include<string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash{
private:
    static const int tableSize = 4;

    struct item{
        string name;
        string Data_Type;
        item* next;
    };

    item* HashTable[tableSize];

public:
    hash();
    int Hash(string key);
    void AddItem(string name, string Data_Type);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemInIndex(int index);
    void FindData_Type(string name);
    void RemoveItem(string name);
};





#endif /* HASH_H */

