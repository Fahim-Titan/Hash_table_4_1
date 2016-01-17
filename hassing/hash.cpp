
#include <cstdlib>
#include<iostream>
#include<string>

#include "hash.h"

using namespace std;

hash::hash()
{
    for(int i=0; i<tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }
}

void hash::AddItem(string name, string drink)
{
    int index = Hash(name);

    if(HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;

        while(Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;

    if(HashTable[index]->name == "empty")
    {
        return count;
    }
    else
    {
        count++;
        item* Ptr = HashTable[index];
        while(Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}

void hash::PrintTable()
{
    int number;
    for(int i=0; i<tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "-------------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "# of Items = " << number << endl;
        cout << "-------------------\n";
    }

}



int hash::Hash(string key)
{
    int hash = 0;
    int index;

    for(int i=0; i<key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    index = hash % tableSize;

    //cout << "Hash is : " << hash <<endl;

    return index;
}
