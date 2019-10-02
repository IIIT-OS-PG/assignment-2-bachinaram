//
//  allCommandsCheck.cpp
//  TcpDownloadManger
//
//  Created by Ram Pratap Bachina on 30/09/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "clientOperations.h"
using namespace std;

void commandChecker(string command){
    vector<string> dividedString = fetchEachString(command);
    string firstCommand = dividedString[0];
    if(firstCommand == "create_user"){
        NewUserRegistration(dividedString);
    }
    else if (firstCommand == "login"){
        string user = dividedString[1];
        checkValidUser(user);
    }
    else if (firstCommand == "create_group"){
        cout << "create_group" <<endl;
    }
    else if (firstCommand == "join_group"){
        cout << "join_group" <<endl;
    }
    else if (firstCommand == "leave_group"){
        cout << "leave_group" <<endl;
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
    else{
        cout << "command not found" <<endl;
    }

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

