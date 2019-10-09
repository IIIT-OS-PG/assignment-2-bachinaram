//
//  allCommandsCheck.cpp
//  Tracker
//
//  Created by Ram Pratap Bachina on 07/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "TrackerOperations.h"
using namespace std;

char *commandChecker(string command){
    //char lst[] = "hello last";
    
    vector<string> dividedString = fetchEachString(command);
    string firstCommand = dividedString[1];
    if(firstCommand == "create_user"){
        char *userRegisterStatus = NewUserRegistration(dividedString);
        return userRegisterStatus;
    }
    else if (firstCommand == "login"){
        string user = dividedString[2];
        string password = dividedString[3];
        char *validUser = checkValidUser(user,password);
        return validUser;
    }
    else if (firstCommand == "create_group"){
        string groupOwner = dividedString[0];
        string groupId = dividedString[2];
        char *groupRegistration = NewGroup(groupOwner,groupId);
        return groupRegistration;
    }
    else if (firstCommand == "join_group"){
        string groupUser = dividedString[0];
        string groupId = dividedString[2];
        char *groupJoin = OldGroup(groupUser, groupId);
        return groupJoin;
    }
    else if (firstCommand == "leave_group"){
        string groupUser = dividedString[0];
        string groupId = dividedString[2];
        char *groupLeave = removeUserFromGroup(groupUser, groupId);
        return groupLeave;
    }
    else if (firstCommand == "list_requests"){
        cout << "list_requests" <<endl;
    }
    else if (firstCommand == "accept_request"){
        cout << "accept_request" <<endl;
    }
    else if (firstCommand == "list_groups"){
        cout << "list_groups" <<endl;
    }
    else if (firstCommand == "list_files"){
        cout << "list_files" <<endl;
    }
    else if (firstCommand == "upload_file"){
        cout << "upload_file" <<endl;
    }
    else if (firstCommand == "download_file"){
        cout << "download_file" <<endl;
    }
    else if (firstCommand == "logout"){
        cout << "logout" <<endl;
    }
    else if (firstCommand == "show_downloads"){
        cout << "show_downloads" <<endl;
    }
    else if (firstCommand == "stop_share"){
        cout << "stop_share" <<endl;
    }
    string someString= "Operation not found";
    char *notfound = returnCharArray(someString);
    return notfound;
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


