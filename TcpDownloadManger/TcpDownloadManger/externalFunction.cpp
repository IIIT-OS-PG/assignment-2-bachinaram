//
//  externalFunction.cpp
//  TcpDownloadManger
//
//  Created by Ram Pratap Bachina on 02/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "clientOperations.h"
using namespace std;

// function takes string argument and returns char array
char *returnCharArray(string someString){
    char *resultCharArray = new char [someString.length()+1];
    strcpy (resultCharArray, someString.c_str());
    return resultCharArray;
}

/*
int helloWorld(char str1){
    int a = 1;
    return a;
}
*/
