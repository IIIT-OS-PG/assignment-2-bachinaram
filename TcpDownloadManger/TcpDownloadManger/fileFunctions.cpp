//
//  fileFunctions.cpp
//  TcpDownloadManger
//
//  Created by Ram Pratap Bachina on 30/09/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "clientOperations.h"
using namespace std;

/* New empty file creation function*/
/* empty file created with user name in the belwo location*/
/* /Users/rbachina/Library/Developer/Xcode/DerivedData/TcpDownloadManger-gdexvmpqdsycgfdrjdduvetonruy/Build/Products/Debug
*/

void fileCreation(string fName){
    ofstream file;
    file.open(fName,ios::out);
    if(!file){
        cout << fName << "record did not created" << endl;
        return;
    }
    file.close();
}

/*add the first line with user=password*/
/*writing new line into the file*/
void fileWriting(string key,string value){
    ofstream file;
    file.open(key,ios::out);
    file << key+"="+value<<endl;
    file.close();
}

/*checks if the file exists in the pwd*/
bool fileExists(string fileName){
    ifstream file(fileName.c_str());
    return file.good();
}

