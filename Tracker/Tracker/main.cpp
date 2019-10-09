//
//  main.cpp
//  Tracker
//
//  Created by Ram Pratap Bachina on 07/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <string>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#define PORT 1212
 #include "TrackerOperations.h"
/*
 cout << "Welcome to File tracker system"<<endl;
*/
using namespace std;
int main(int argc, const char * argv[]) {
    int fd_tracker; //mastersocket
    int add_count; //addrelen
    int accept_socket=0; //accept newsocket
    /*async*/
    int client_socket[30],max_clients=30,activity,i,sd;
    int max_sd;
    /*async*/
    
    char buffer[2000];
    char *result;
    struct sockaddr_in socket_address;
    add_count=sizeof(socket_address);
    
    /*async*/
    fd_set readfds;
    for (i = 0; i < max_clients; i++)
    {
        client_socket[i] = 0;
    }
    /*async*/
    
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
    
    
    
    
    
    while(1){
        FD_ZERO(&readfds);
        FD_SET(fd_tracker, &readfds);
        max_sd = fd_tracker;
        for ( i = 0 ; i < max_clients ; i++)
        {
            sd = client_socket[i];
            if(sd > 0)
            FD_SET( sd , &readfds);
            if(sd > max_sd){
                max_sd = sd;
            }
        }
        activity = select(max_sd + 1,&readfds,NULL,NULL,NULL);
        if (FD_ISSET(fd_tracker, &readfds)){
            accept_socket = accept(fd_tracker,(struct sockaddr *)&socket_address,(socklen_t*)&add_count);
            if(accept_socket<0){
                perror("Unable to accept requests");
                exit(1);
            }
            cout << "some client hit the server"<<endl;
            //cout << "Awaiting client response..." << endl;
            for (i = 0; i < max_clients; i++){
                if( client_socket[i] == 0 ){
                    client_socket[i] = accept_socket;
                    printf("Adding to list of sockets as %d\n" , i);
                    break;
                }
            }
        }
        
        for (i = 0; i < max_clients; i++){
            sd = client_socket[i];
            if (FD_ISSET( sd , &readfds)){
                memset(&buffer, 0, sizeof(buffer));
                recv(sd, buffer, sizeof(buffer),0);
                if(!strcmp(buffer, "exit")){
                    cout << "Client has quit the session" << endl;
                    close(sd);
                    client_socket[i] = 0;
                    break;
                }
                string stringBuffer(buffer);
                cout << stringBuffer <<endl;
                cout << "ClientEntered: " << buffer << endl;
                
                result = commandChecker(stringBuffer);
                
                //cout<<result<<endl;
                
                cout << "ClientEntered: " << buffer << endl;
                string client_command=string(result);
                
                memset(&buffer, 0, sizeof(buffer));
                strcpy(buffer, client_command.c_str());

                if(client_command=="exit")
                {
                    send(sd, buffer, sizeof(buffer), 0);
                    break;
                }
                
                send(sd, buffer, sizeof(buffer), 0);
                sleep(1);
                }
        }
    }
        //close(accept_socket);
        //close(fd_tracker);
        return 0;
}
