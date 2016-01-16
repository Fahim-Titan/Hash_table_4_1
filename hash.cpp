#include <cstdlib>
#include<iostream>
#include<string>

#include "hash.h"

using namespace std;

hash::hash()
{
    tableSize = 100;
}

int hash::Hash(string key)
{
    int hash = 0;
    int index;
    
    
    
    for(int i=0; i<key.length();i++){
        hash += (int)key[i];
    }
    
//    cout << "key[0] = " << (int)key[0] << endl;
//    cout << "key[1] = " << (int)key[1] << endl;
//    cout << "key[2] = " << (int)key[2] << endl;
//    cout << "key[3] = " << (int)key[3] << endl;
  
    index = hash % tableSize;
    
    cout << "Hash is : " << hash <<endl;
    
    return index;    
}