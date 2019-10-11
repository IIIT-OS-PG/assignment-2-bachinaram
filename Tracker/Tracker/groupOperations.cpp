//
//  groupOperations.cpp
//  Tracker
//
//  Created by Ram Pratap Bachina on 07/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
#include "TrackerOperations.h"
using namespace std;


char *NewGroup(string grpOwn, string grpId){
    char *groupId = new char [grpId.length()+1];
    strcpy (groupId, grpId.c_str());
    string fullPath = "groups/"+grpId;
    
    char *temp =new char [grpOwn.length()+1];
    strcpy (temp, grpOwn.c_str());
    
    createDirIfNotExist();
    
    if(fileExists(fullPath)==1){
        strcat(groupId," group already exist");
        return groupId;
    }
    else{
        int creationFile = fileCreation(fullPath);
        if(creationFile == 1){
            strcat(groupId," group creation failed");
            return groupId;
        }
        int writingFile = groupFileWriting(grpOwn,grpId);
        if(writingFile==0){
            strcat(groupId," group created successfully");
            return groupId;
            }
        }
    return temp;
    }

// code to add user to group
char *OldGroup(string groupUser, string grpId){
    char *groupId = new char [grpId.length()+1];
    strcpy (groupId, grpId.c_str());
    string fullPath = "groups/"+grpId;
    string members="pending=";
    if(fileExists(fullPath)==0){
        strcat(groupId," group does not exist");
        return groupId;
    }
    char *memberLine = readGroupFile(groupUser, grpId, members);
    return memberLine;
}

//code to remove user from group
char *removeUserFromGroup(string groupUser, string grpId){
    char *groupId = new char [grpId.length()+1];
    strcpy (groupId, grpId.c_str());
    string fullPath = "groups/"+grpId;
    string members="members=";
    if(fileExists(fullPath)==0){
        strcat(groupId," group does not exist");
        return groupId;
    }
    char *memberLine = removeUserFromGroupFile(groupUser, grpId, members);
    return memberLine;
}


char *getAllGroups(){
    char *files;
    string allfiles = getAllFiles();
    files = returnCharArray(allfiles);
    return files;
}

char *getAllPendingUsers(string groupUser){
    char *groups;
    string results;
    //try to findout groups that user is owner of
    string allOwnerGroups = getAllOwnerGroups(groupUser);
    stringstream ss(allOwnerGroups);
    string eachString;
    while (getline(ss, eachString, ' ')) {
        
        if(eachString.compare(".")!=0||eachString.compare("..")!=0){
            string result = getPendingUsers(eachString);
            results.append(result+" ");
            //results.append(result);
        }
    }
    groups = returnCharArray(results);
    //groups = returnCharArray(allOwnerGroups);
    return groups;
}

//add users to groups i.e., moving user from pending to membes key in group file
char *addPendingUsersToGroup(string groupOwner,string groupId,string groupUser){
    char *unauth1;
    string unauthour;
    string members="pending=";
    string join="members=";
    //string unauthour1 = "You are not owner of the group";
    //we need check passed user is owner to that group
    //so we need to get list of files that
    string allOwnerGroups = getAllOwnerGroups(groupOwner);
/*
    if(allOwnerGroups.find(groupId) != string::npos){
        string unauthour = groupId;
        unauth = returnCharArray(unauthour);
        return unauth;
    }
 */
    
    stringstream ss(allOwnerGroups);
    string eachString;
    while (getline(ss, eachString, ' ')) {
        if(groupId.compare(eachString)==0){
            char *test1 = removeUserFromGroupFile(groupUser, eachString, members);
            char *test2 = readGroupFile(groupUser, eachString, join);
            unauth1 = returnCharArray(eachString);
        }
    }
    return unauth1;
}

