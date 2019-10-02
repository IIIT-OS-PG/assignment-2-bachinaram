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
#include <vector>
using namespace std;
void commandChecker(string client_command);
vector<string> fetchEachString(string command);
void NewUserRegistration(vector <string> user_creation_command);
void fileCreation(string fName);
void fileWriting(string key,string value);
bool fileExists(string fileName);
void checkValidUser(string user);

