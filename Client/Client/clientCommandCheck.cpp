//
//  clientCommandCheck.cpp
//  Client
//
//  Created by Ram Pratap Bachina on 08/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include "clientOperations.h"
using namespace std;


char *commandChecker(string command){
    vector<string> dividedString = fetchEachString(command);
    string firstCommand = dividedString[0];
    if(firstCommand == "create_user"){
        char *userRegisterStatus = returnCharArray(firstCommand);
        return userRegisterStatus;
        }
    else if (firstCommand == "login"){
        char *login = returnCharArray(firstCommand);
        return login;
        }
    string someString= "Operation not found";
    char *notfound = returnCharArray(someString);
    return notfound;
    }


// returns user from the create_user and login commands
char *fetchUser(string command){
    vector<string> dividedString = fetchEachString(command);
    string firstCommand = dividedString[1];
    char *user = returnCharArray(firstCommand);
    return user;
}

/* break lines in to strings*/
/* below function breaks whole comamnd into strings and keeps all strings in vector*/

vector<string> fetchEachString(string command){
    stringstream ss(command);
    vector <string> allCommandStrings;
    string eachString;
    while (getline(ss, eachString, ' ')) {
        allCommandStrings.push_back(eachString);
    }
    return allCommandStrings;
}

