//
//  groupOperations.cpp
//  Tracker
//
//  Created by Ram Pratap Bachina on 07/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <stdio.h>
#include <string>
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
    
    if(fileExists(fullPath)==0){
        strcat(groupId," group does not exist");
        return groupId;
    }
    char *memberLine = readGroupFile(groupUser, grpId);
    return memberLine;
}

//code to remove user from group
char *removeUserFromGroup(string groupUser, string grpId){
    char *groupId = new char [grpId.length()+1];
    strcpy (groupId, grpId.c_str());
    string fullPath = "groups/"+grpId;
    
    if(fileExists(fullPath)==0){
        strcat(groupId," group does not exist");
        return groupId;
    }
    char *memberLine = removeUserFromGroupFile(groupUser, grpId);
    return memberLine;
}
