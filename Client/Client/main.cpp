//
//  main.cpp
//  Client
//
//  Created by Ram Pratap Bachina on 07/10/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include <sstream>
#include <netdb.h>
#include <netinet/in.h>
#define PORT 1212
#include <errno.h>
#include <arpa/inet.h>
#include "clientOperations.h"


int main(int argc, const char * argv[]) {
    int client_sock;
    int client_connect;
    char buffer[2000];
    struct sockaddr_in socket_address;
    client_sock=socket(AF_INET,SOCK_STREAM,0);
    if(client_sock<0){
        perror("FIRST STEP FAILURE - SOCKET ISSUE in client");
        exit(1);
    }
    
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(PORT);
    socket_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    client_connect = connect(client_sock, (struct sockaddr *)&socket_address,sizeof(socket_address));
    if(client_sock<0){
        perror("CLIENT UNABLE TO ESTABLISH CONNECTION");
        exit(1);
    }
    
   
   //
    string user;
    char *command;
    const char *login="login";
    const char *create_user="create_user";
    cout << "Login to connect network or Register"<<endl;
    cout << "-->";
    getline(cin, user);
    command = commandChecker(user);
    
    if(strcmp(command, login)==0 || strcmp(command, create_user)==0){
        string loginUser = fetchUser(user);
        loginUser = loginUser+" ";
        
        while(1){
            if(user == "exit")
            {
                send(client_sock, buffer, sizeof(buffer), 0);
                cout << "you are logged out" <<endl;
                break;
            }
            memset(&buffer, 0, sizeof(buffer));
            strcat(buffer, loginUser.c_str());
            //strcpy(buffer, loginUser.c_str());
            //cout << buffer << endl;
            strcat(buffer, user.c_str());
            //strcpy(buffer, user.c_str());
            //cout << buffer << endl;
            send(client_sock, buffer, sizeof(buffer), 0);
            cout << "Awaiting server response..." << endl;
            memset(&buffer, 0, sizeof(buffer));
            recv(client_sock, buffer, sizeof(buffer),0);
            cout << "server: " << buffer << endl;
            if(!strcmp(buffer, "exit")){
                cout << "Server has quit the session" << endl;
                break;
            }
            cout << "-->";
            getline(cin, user);
        }
        close(client_sock);
    }
    else{
        cout << "you are not authorized, good bye"<<endl;
    }
    return 0;
}
