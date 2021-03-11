#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
//#include <sys/socket.h>


int main(int argc, char *argv[]){

    int data_size, saddr_size;
    struct sockaddr saddr;
    unsigned char *buffer = (unsigned char *)malloc(65536);
    
    int sock_raw = socket("AF_INET", "SOCK_RAW", "IPPROTO_TCP");
    
    while(1){
        data_size = recvfrom(sock_raw , buffer , 65536 , 0 , &saddr , &saddr_size);
        printf("%d \n", data_size)
    }
}