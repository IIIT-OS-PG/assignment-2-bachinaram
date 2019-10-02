//
//  userLoginProcess.cpp
//  TcpDownloadManger
//
//  Created by Ram Pratap Bachina on 30/09/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clientOperations.h"
using namespace std;


void NewUserRegistration(vector<string> user_creation_command){
    string fName = user_creation_command[1];
    string password = user_creation_command[2];
    fileCreation(fName);
    fileWriting(fName,password);
    cout << fName << " created successfully" << endl;
    cout << "Now try login with your user id" << endl;
    return;
}

void checkValidUser(string user){
    if(fileExists(user)==1){
        cout << "user exists"<<endl;
        cout << "login successful"<<endl;
    }
    else
    {
        cout << user <<" doesn't exists! Please register"<<endl;
    }
}
