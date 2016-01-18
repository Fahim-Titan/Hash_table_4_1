
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

void hash::PrintItemInIndex(int index)
{
    item* Ptr = HashTable[index];

    if (Ptr->name == "empty")
    {
        cout << "index = " << index << " is empty";
    }
    else
    {
        cout << "index " << index <<" contains the following item\n";

        while (Ptr != NULL)
        {
            cout << "-----------------\n";
            cout << Ptr->name <<endl;
            cout << Ptr->drink <<endl;
            cout << "-----------------\n";
            Ptr = Ptr->next;
        }
    }
}


int hash::Hash(string key)
{
    int hash = 0;
    int index;

    for(int i=0; i<key.length(); i++)
    {
        hash = (hash + (int)key[i])*17;
    }
    index = hash % tableSize;

    //cout << "Hash is : " << hash <<endl;

    return index;
}

void hash::RemoveItem(string name)
{
    int index = Hash(name);

    item* delPtr;
    item* P1;
    item* P2;

    //if we don't find the item we are looking
    if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
    {
        cout << name << " is not found in the hash table\n";
    }

    //if the item we are looking, is FOUND and there is no other items
    else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
    {
        HashTable[index]->name = "empty";
        HashTable[index]->drink == "empty";
        cout << name << " is removed from the table\n";
    }

    //we have found the item at the first. but there are other items in the table
    else if (HashTable[index]->name == name)
    {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;

        cout << name << " is removed from hash table\n";
    }

    //we have found the item, but it is not in the first
    else
    {
        P1 = HashTable[index]->next;
        P2 = HashTable[index];

        while (P1 != NULL && P1->name != name)
        {
            P2 = P1;
            P1 = P1->next;
        }
        if (P1 == NULL)
        {
            cout << name << " is not found in the table\n";
        }
        else
        {
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;
            delete delPtr;

            cout << name << " is removed from the hash table\n";
        }
    }
}











void hash::FindDrink(string name)
{
    int index = Hash(name);
    bool found = false;
    string drink;

    item* Ptr = HashTable[index];
    while (Ptr != NULL)
    {
        if (Ptr->name == name)
        {
            found = true;
            drink = Ptr->drink;
        }
        Ptr = Ptr->next;
    }

    if(found)
    {
        cout << "Drink name = " << drink << endl;
    }
    else
    {
        cout << "we didn't found the name" << name << " in the Hash Table\n";
    }
}
