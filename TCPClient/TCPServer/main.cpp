//
//  main.cpp
//  TCPClient
//
//  Created by Ram Pratap Bachina on 30/09/19.
//  Copyright © 2019 Ram Pratap Bachina. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#define PORT 1212
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, const char * argv[]) {
    int client_sock;
    int client_connect;
    char buffer[2000];
    struct sockaddr_in socket_address;

    
    client_sock=socket(AF_INET, SOCK_STREAM,0);
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
    while(1){
        cout << ">";
        string hello;
        getline(cin, hello);
        memset(&buffer, 0, sizeof(buffer));
        strcpy(buffer, hello.c_str());
        if(hello == "exit")
        {
            send(client_sock, buffer, sizeof(buffer), 0);
            break;
        }
        send(client_sock, buffer, sizeof(buffer), 0);
        cout << "Awaiting server response..." << endl;
        memset(&buffer, 0, sizeof(buffer));
        recv(client_sock, buffer, sizeof(buffer),0);
        if(!strcmp(buffer, "exit")){
            cout << "Server has quit the session" << endl;
            break;
        }
        cout << "server: " << buffer << endl;
    }
    close(client_sock);
    return 0;
}
