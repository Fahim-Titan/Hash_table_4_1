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
    int tableSize;
    
    
public:
    hash();
    int Hash(string key);
    
};





#endif /* HASH_H */

