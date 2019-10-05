//
//  clientOperations.h
//  TcpDownloadManger
//
//  Created by Ram Pratap Bachina on 30/09/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#ifndef clientOperations_h
#define clientOperations_h


#endif /* clientOperations_h */
#include <string>
#include<map>
#include<string.h>
#include <vector>
using namespace std;
char *commandChecker(string client_command);
vector<string> fetchEachString(string command);
char *NewUserRegistration(vector <string> user_creation_command);
bool fileCreation(string fName);
bool fileWriting(string key,string value);
bool fileExists(string fileName);
char *checkValidUser(string user,string password);
char *returnCharArray(string someString);
map<string,string> getString(string user);
char *NewGroup(string grpId);
//int helloWorld(char str1);
