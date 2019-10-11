//
//  fileFunctions.cpp
//  Tracker
//
//  Created by Ram Pratap Bachina on 07/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include <string.h>
#include<map>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "TrackerOperations.h"
using namespace std;

/* New empty file creation function*/
/* empty file created with user name in the belwo location*/
/* /Users/rbachina/Library/Developer/Xcode/DerivedData/TcpDownloadManger-gdexvmpqdsycgfdrjdduvetonruy/Build/Products/Debug
*/

bool fileCreation(string fName){
    ofstream file;
    file.open(fName,ios::out);
    if(!file){
        cout << fName << "record did not created" << endl;
        return 1;
    }
    file.close();
    return 0;
}

/*add the first line with user=password*/
/*writing new line into the file*/

bool userFileWriting(string key,string value){
    ofstream file;
    file.open(key,ios::out);
    file << key+"="+value<<endl;
    file.close();
    return 0;
}

bool groupFileWriting(string grpOwn,string grpId){
    string id ="gid";
    string fullPath = "groups/"+grpId;
    ofstream file;
    file.open(fullPath,ios::out);
    file << id+"="+grpId<<endl;
    file << "owner="+grpOwn<<endl;
    file << "members="<<endl;
    file << "pending="<<endl;
    file.close();
    return 0;
}


/*checks if the file exists in the pwd*/
bool fileExists(string fileName){
    ifstream file(fileName.c_str());
    return file.good();
}


bool createDirIfNotExist(){
    if(mkdir("groups", 0777) == -1){
        return 1;
    }
    else{
        mkdir("groups", 0777);
        return 0;
    }
}


map<string,string> getString(string user){
    string eachLine;
    string token1;
    string token2;
    string delimiter = "=";
    map<string,string> userAuth;
    ifstream userFile;
    userFile.open(user);
    if(userFile.is_open()){
        while(getline(userFile,eachLine)){
            //char *Line = returnCharArray(eachLine);
            //ram comes out from the line before delimiter
            token1=eachLine.substr(0,eachLine.find(delimiter));
            eachLine.erase(0,eachLine.find(delimiter)+delimiter.length());
            token2=eachLine.substr(0,eachLine.find(delimiter));
            userAuth[token1]=token2;
            //userAuth.insert({ token1, token2 });
        }
        userFile.close();
}
    return userAuth;
}



char *readGroupFile(string groupUser,string groupId, string members){
    string fullPath1 = "groups/"+groupId;
    string fullPath2 = "groups/"+groupId+".temp";
    char *oldFile = returnCharArray(fullPath1);
    char *newFile = returnCharArray(fullPath2);
    char *memberLine;

    //string members="pending=";
    string user=groupUser+",";
    string eachLine;
    ifstream grpFile;
    ofstream newGrpFile;
    grpFile.open(fullPath1,ios::in);
    newGrpFile.open(fullPath2,ios::out);
    if(grpFile.is_open()){
        while(getline(grpFile,eachLine)){
            if(eachLine.find(members) != string::npos){
                newGrpFile << eachLine.append(user) << endl;
                memberLine = returnCharArray(eachLine);
            }
            else{
                newGrpFile << eachLine << endl;
            }
        }
        grpFile.close();
        remove(oldFile);
        newGrpFile.close();
        rename(newFile,oldFile);
    }
    return memberLine;
}


char *removeUserFromGroupFile(string groupUser, string groupId, string members){
    string fullPath1 = "groups/"+groupId;
    string fullPath2 = "groups/"+groupId+".temp";
    char *oldFile = returnCharArray(fullPath1);
    char *newFile = returnCharArray(fullPath2);
    char *memberLine;
    //string members="members=";
    string user=groupUser+",";
    string eachLine;
    ifstream grpFile;
    ofstream newGrpFile;
    grpFile.open(fullPath1,ios::in);
    newGrpFile.open(fullPath2,ios::out);
    if(grpFile.is_open()){
        while(getline(grpFile,eachLine)){
            if(eachLine.find(members) != string::npos){
                size_t lineFirstPlace = eachLine.find(user);
                newGrpFile << eachLine.erase(lineFirstPlace, user.length()) << endl;
                memberLine = returnCharArray(eachLine);
            }
            else{
                newGrpFile << eachLine << endl;
            }
        }
        grpFile.close();
        remove(oldFile);
        newGrpFile.close();
        rename(newFile,oldFile);
    }
    return memberLine;
}


//read all files from the given directory
string getAllFiles(){
    struct dirent *pDirent;
    DIR *dr = opendir("./groups");
    string files;
    string nodir = "No Groups available in network";
    if(dr == 0){
        return nodir;
    }
    while ((pDirent = readdir(dr)) != NULL){
        string file = pDirent->d_name;
        files.append(file+" ");
    }
    closedir(dr);
    return files;
}

string getAllOwnerGroups(string groupUser){
    struct dirent *pDirent;
    bool check;
    string files;
    string nothing = "You are not owner of any group";
    DIR *dr = opendir("./groups");
    string nodir = "No Groups available in network";
    if(dr == 0){
        return nodir;
    }
    while ((pDirent = readdir(dr)) != NULL){
        string file = pDirent->d_name;
        check = readFile(groupUser, file);
        if(check){
            files.append(file+" ");
        }
    }
    closedir(dr);
    if(files.empty()){
        return nothing;
    }
    return files;
}

//read each file and check the argument passed file has that owner
bool readFile(string user, string file){
    string fullPath = "groups/"+file;
    string owner="owner="+user;
    string eachLine;
    bool myReturn = true;
    ifstream grpFile;
    grpFile.open(fullPath,ios::in);
    if(grpFile.is_open()){
        while(getline(grpFile,eachLine)){
            if(eachLine.find(owner) != string::npos){
                myReturn = true;
                break;
            }
            else{
                myReturn = false;
            }
        }
        grpFile.close();
    }
    return myReturn;
}

//read a file for oending requests
string getPendingUsers(string fileName){
    string fullPath = "groups/"+fileName;
    string members="pending=";
    string eachLine;
    string tmpLine;
    ifstream grpFile;
    grpFile.open(fullPath,ios::in);
    if(grpFile.is_open()){
        while(getline(grpFile,eachLine)){
            if(eachLine.find(members) != string::npos){
                //tmpLine=eachLine.substr(eachLine.find(members) + 1);
                tmpLine=fileName+"->"+eachLine;
                break;
            }
        }
        grpFile.close();
    }
    /*
    if(tmpLine.empty()){
        return members;
    }
     */
    return tmpLine;
}
