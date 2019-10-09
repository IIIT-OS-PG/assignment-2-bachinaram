//
//  externalFunctions.cpp
//  Tracker
//
//  Created by Ram Pratap Bachina on 07/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "TrackerOperations.h"
using namespace std;

// function takes string argument and returns char array
char *returnCharArray(string someString){
    char *resultCharArray = new char [someString.length()+1];
    strcpy (resultCharArray, someString.c_str());
    return resultCharArray;
}
