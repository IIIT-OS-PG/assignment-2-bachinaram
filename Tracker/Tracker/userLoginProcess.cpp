//
//  userLoginProcess.cpp
//  Tracker
//
//  Created by Ram Pratap Bachina on 07/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include<string.h>
#include "TrackerOperations.h"
using namespace std;


char *NewUserRegistration(vector<string> user_creation_command){
    string fName = user_creation_command[2];
    string password = user_creation_command[3];
    
    
    //conversion of string to char and adding the char to char array
    char *notResult = new char [fName.length()+1];
    strcpy (notResult, fName.c_str());
    char *Result = new char [fName.length()+1];
    strcpy (Result, fName.c_str());
    
    
    int creationFile = fileCreation(fName);
    if(creationFile == 1){
        strcat(notResult," creation failed");
        return notResult;
    }
    else{
        int writingFile = userFileWriting(fName,password);
        if(writingFile==0){
            strcat(Result," created successfully, now try login");
        }
    }
    return Result;
}

char *checkValidUser(string user,string password){
    char *returnUser = returnCharArray(user);
    if(fileExists(user)==0){
        strcat(returnUser," does not exists, please register");
        return returnUser;
    }
    
    char *retUser = returnCharArray(user);
    map<string, string> userPassAuthMap;
    userPassAuthMap=getString(user);
    char *map_userPass = returnCharArray(userPassAuthMap[user]);
    char *tmp_pass = returnCharArray(password);
    if(strcmp(map_userPass,tmp_pass) == 0){
        strcat(retUser," loggedin");
        return retUser;
    }
    strcat(retUser,", check your password");
    return retUser;
}
