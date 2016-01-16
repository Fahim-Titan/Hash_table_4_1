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

    int index;
    hash hashobj;
    
    index = hashobj.Hash("alfah");
    cout << "index is " << index << endl;
    return 0;
}

