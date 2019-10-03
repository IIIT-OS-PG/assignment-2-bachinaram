//
//  fileFunctions.cpp
//  TcpDownloadManger
//
//  Created by Ram Pratap Bachina on 30/09/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include <string.h>
#include<map>
#include "clientOperations.h"
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

bool fileWriting(string key,string value){
    ofstream file;
    file.open(key,ios::out);
    file << key+"="+value<<endl;
    file.close();
    return 0;
}

/*checks if the file exists in the pwd*/
bool fileExists(string fileName){
    ifstream file(fileName.c_str());
    return file.good();
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
