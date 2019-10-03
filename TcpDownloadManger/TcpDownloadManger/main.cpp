//
//  main.cpp
//  TcpDownloadManagerTracker
//
//  Created by Ram Pratap Bachina on 01/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define PORT 1212
 #include "clientOperations.h"
/*
 cout << "Welcome to File tracker system"<<endl;

*/
using namespace std;
int main(int argc, const char * argv[]) {
    int fd_tracker;
    int add_count;
    int accept_socket=0;
    char buffer[2000];
    char *result;
    struct sockaddr_in socket_address;
    add_count=sizeof(socket_address);
    
    fd_tracker = socket(AF_INET,SOCK_STREAM,0);
    if(fd_tracker < 0){
        perror("SOCKET CREATION FAILED");
        exit(1);
    }
    
    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = INADDR_ANY;
    socket_address.sin_port = htons(PORT);
    
    
    bind(fd_tracker, (struct sockaddr *)&socket_address,sizeof(socket_address));
    int no_listeners = listen(fd_tracker, 4);
    if(no_listeners<0){
        perror("Listening issue");
        exit(1);
    }
    
    accept_socket = accept(fd_tracker,(struct sockaddr *)&socket_address,(socklen_t*)&add_count);
    if(accept_socket<0){
        perror("Unable to accept requests");
        exit(1);
    }
    
    while(1){
        
        cout << "server got connection"<<endl;
        cout << "Awaiting client response..." << endl;
        memset(&buffer, 0, sizeof(buffer));
        recv(accept_socket, buffer, sizeof(buffer),0);
        if(!strcmp(buffer, "exit"))
        {
            cout << "Client has quit the session" << endl;
            break;
        }
        string stringBuffer(buffer);
        cout << stringBuffer <<endl;
        result = commandChecker(stringBuffer);
        cout<<result<<endl;
        cout << "ClientEntered: " << buffer << endl;
        
        //cout << ">";
        string client_command=string(result);
        //getline(cin, client_command);
        //const char *client_request = commandChecker(buffer);
        //cout<<client_request<<endl;
        memset(&buffer, 0, sizeof(buffer));
        strcpy(buffer, client_command.c_str());
        //int result = strcmp(client_command,"exit");
        //if(result == 0)
        if(client_command=="exit")
        {
            send(accept_socket, buffer, sizeof(buffer), 0);
            break;
        }
        send(accept_socket, buffer, sizeof(buffer), 0);
        sleep(1);
    }
    close(accept_socket);
    close(fd_tracker);
    return 0;
}



