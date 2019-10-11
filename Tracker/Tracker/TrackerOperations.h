//
//  TrackerOpoerations.h
//  Tracker
//
//  Created by Ram Pratap Bachina on 07/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#ifndef TrackerOpoerations_h
#define TrackerOpoerations_h


#endif /* TrackerOpoerations_h */
#include <string>
#include<map>
#include<string.h>
#include <vector>
using namespace std;
char *commandChecker(string client_command);
vector<string> fetchEachString(string command);
char *NewUserRegistration(vector <string> user_creation_command);
bool fileCreation(string fName);
bool userFileWriting(string key,string value);
bool groupFileWriting(string grpOwn,string grpId);
bool fileExists(string fileName);
char *checkValidUser(string user,string password);
char *returnCharArray(string someString);
map<string,string> getString(string user);
char *NewGroup(string grpOwn, string grpId);
bool createDirIfNotExist();
char *OldGroup(string groupUser,string grpId);
char *readGroupFile(string groupUser,string groupId,string members);
char *removeUserFromGroup(string groupUser, string grpId);
char *removeUserFromGroupFile(string groupUser, string groupId, string members);
char *getAllGroups();
string getAllFiles();
char *getAllPendingUsers(string groupUser);
string getAllOwnerGroups(string groupUser);
bool readFile(string user, string file);
string getPendingUsers(string fileName);
char *addPendingUsersToGroup(string groupOwner,string groupId,string groupUser);
//int helloWorld(char str1);
